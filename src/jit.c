/*
 * jit.c
 *
 * $Id$
 */

#include <parrot/parrot.h>
#include "parrot/jit.h"
#define JIT_EMIT 0
#include "parrot/jit_emit.h"

/*
 * s. jit/$arch/jit_emit.h for the meaning of these defs
 */

#ifndef INT_REGISTERS_TO_MAP
# define INT_REGISTERS_TO_MAP 0
  char *intval_map = 0;
#endif

#ifndef FLOAT_REGISTERS_TO_MAP
# define FLOAT_REGISTERS_TO_MAP 0
  char *floatval_map = 0;
#endif

#ifndef ALLOCATE_REGISTERS_PER_SECTION
# define ALLOCATE_REGISTERS_PER_SECTION 1
#endif

#if ALLOCATE_REGISTERS_PER_SECTION
# undef PRESERVED_INT_REGS
# undef PRESERVED_FLOAT_REGS
#endif

#ifndef PRESERVED_INT_REGS
# if ALLOCATE_REGISTERS_PER_SECTION
#   define PRESERVED_INT_REGS INT_REGISTERS_TO_MAP
# else
#   define PRESERVED_INT_REGS 0
# endif
#endif

#ifndef PRESERVED_FLOAT_REGS
# if ALLOCATE_REGISTERS_PER_SECTION
#   define PRESERVED_FLOAT_REGS FLOAT_REGISTERS_TO_MAP
# else
#   define PRESERVED_FLOAT_REGS 0
# endif
#endif

#ifdef __GNUC__
void Parrot_jit_debug(struct Parrot_Interp* interpreter);
#endif

/*
 * optimizer->map_branch parallels the opcodes with a list of
 * branch information and register mapping information
 *
 * - branch instructions have JIT_BRANCH_SOURCE
 * - opcodes jumped to have   JIT_BRANCH_TARGET
 * - mapped arguments have register type + 1 and finally
 * - after register allocation these have the processor register
 *   that got mapped
 *
 */

static void
make_branch_list(struct Parrot_Interp *interpreter,
        Parrot_jit_optimizer_t * optimizer,
        opcode_t *cur_op, opcode_t *code_start, opcode_t *code_end)
{

    op_info_t *op_info;
    char *branch;

    /* Allocate space for the branch information and register map */
    optimizer->map_branch = branch =
        (char *)mem_sys_allocate_zeroed((size_t)(code_end - code_start));

    /* Allocate space for the branch list */
    optimizer->branch_list = (opcode_t **)
        mem_sys_allocate_zeroed(
                (size_t)(code_end - code_start) * sizeof(opcode_t *));

    /* If the opcode jumps we may:
     *
     * PARROT_JUMP_RELATIVE:
     *      The op jumps to an address relative to the current position,
     *      thus we mark the branch target and the branch source.
     *
     * PARROT_JUMP_ADDRESS:
     *      The op jumps to an absolute address,thus we mark the branch
     *      target.
     *
     * PARROT_JUMP_POP:
     *      The op pops the address to jump to,thus we don't mark the
     *      branch target, anyway it may probably use expr(NEXT)
     *
     * PARROT_JUMP_ENEXT:
     *      The op does something with expr(NEXT),
     *      XXX I'll assume that it's stored in the control stack for
     *          later returning since that's the only way it's used now
     *          but this should go away by the time we add some metadata
     *          to the ops.
     *      So we will mark the branch target.
     *
     * PARROT_JUMP_GNEXT:
     *      Means the opcode does some other kind of jump, and also
     *      might goto(NEXT)
     *
     * PARROT_JUMP_UNPREDICTABLE:
     *      The branch target is unpredictable.
     *      Things get a little tricky since it's not 100% true that the
     *      target is unpredictable because of the set_addr opcode, we
     *      need to find a solution for this, in the mean time, we will
     *      make each section have it's own arena and try to avoid
     *      going in and out from them as much as posible.
     *
     *  PARROT_JUMP_RESTART
     *      If the parrot program counter is zero, fall out of the
     *      run loop.
     *
     */

    while (cur_op < code_end) {
        /* Predereference the opcode information table for this opcode
         * early since it's going to be used many times */
        op_info = &interpreter->op_info_table[*cur_op];

        /* if op_info->jump is not 0 this opcode may jump,
         * so mark this opcode as a branch source */
        if (op_info->jump)
            branch[cur_op - code_start] |= JIT_BRANCH_SOURCE;
        /* If it's not a constant, no joy */
        if (op_info->types[op_info->arg_count - 1] == PARROT_ARG_IC) {
            /* The branch target is relative, the offset is in last argument */
            if (op_info->jump & PARROT_JUMP_RELATIVE) {
                /* Set the branch target */
                optimizer->branch_list[cur_op - code_start] =
                    cur_op + cur_op[op_info->arg_count - 1];
                branch[cur_op - code_start + cur_op[op_info->arg_count - 1]] |=
                    JIT_BRANCH_TARGET;
            }
            /* The branch target is absolute, the address is in last argument */
            else if (op_info->jump & PARROT_JUMP_ADDRESS) {
                /* Set the branch target */
                optimizer->branch_list[cur_op - code_start] =
                    cur_op + cur_op[op_info->arg_count - 1];
                branch[cur_op[op_info->arg_count - 1]] |= JIT_BRANCH_TARGET;
            }
        }
        /* The address of the next opcode */
        if ((op_info->jump & PARROT_JUMP_ENEXT) ||
            (op_info->jump & PARROT_JUMP_GNEXT))
            branch[cur_op + op_info->arg_count - code_start] |=
                JIT_BRANCH_TARGET;
        if (op_info->jump & PARROT_JUMP_UNPREDICTABLE)
            optimizer->has_unpredictable_jump = 1;
        /* Move to the next opcode */
        cur_op += op_info->arg_count;
    }
}

static void
set_register_usage(struct Parrot_Interp *interpreter,
        Parrot_jit_optimizer_t * optimizer,
        Parrot_jit_optimizer_section_ptr cur_section,
        op_info_t *op_info, opcode_t *cur_op, opcode_t *code_start)
{
    int argn;
    int typ;
    Parrot_jit_register_usage_t *ru = cur_section->ru;
    char *map = optimizer->map_branch;

    /* For each argument that has the opcode increment the usage count,
     * We move from the end since we need to check if the first opcode
     * using the register will read or write it.
     *
     * registers are set per their type [IPSN]
     * */
    for (argn = op_info->arg_count - 1; argn > 0; argn--) {
        switch (op_info->types[argn]) {
            case PARROT_ARG_I:
            case PARROT_ARG_KI:
                typ = 0;
                break;
            case PARROT_ARG_P:
            case PARROT_ARG_K:
                typ = 1;
                break;
            case PARROT_ARG_S:
                typ = 2;
                break;
            case PARROT_ARG_N:
                typ = 3;
                break;
            default:
                typ = -1;
                break;
        }
        if (typ >= 0) {
            /* remember the register typ (+1) for this op argument
             * for register allocation */
            map[cur_op + argn - code_start] = typ + 1;
            if ((!ru[typ].reg_count[*(cur_op + argn)]++) &&
                (op_info->dirs[argn] & PARROT_ARGDIR_IN))
                ru[typ].reg_dir[*(cur_op + argn)] |= PARROT_ARGDIR_IN;
            if (op_info->dirs[argn] & PARROT_ARGDIR_OUT) {
                ru[typ].reg_dir[*(cur_op + argn)] |= PARROT_ARGDIR_OUT;
            }
        }
        /* key constants may have register keys */
        else if (op_info->types[argn] == PARROT_ARG_KC) {
            PMC *key = interpreter->code->const_table->constants[
                *(cur_op + argn)]->key;
            while (key) {
                UINTVAL flags = PObj_get_FLAGS(key);
                if (flags & KEY_register_FLAG) {
                    INTVAL n = key->cache.int_val;
                    if (flags & KEY_integer_FLAG)
                        typ = 0;
                    else if (flags & KEY_pmc_FLAG)
                        typ = 1;
                    else if (flags & KEY_string_FLAG)
                        typ = 2;

                    if (!ru[typ].reg_count[n]++)
                        ru[typ].reg_dir[n] |= PARROT_ARGDIR_IN;
                }
                key = key_next(interpreter, key);
            }
        }
    }
}

static void
make_sections(struct Parrot_Interp *interpreter,
        Parrot_jit_optimizer_t * optimizer,
        opcode_t *cur_op, opcode_t *code_start, opcode_t *code_end)
{
    Parrot_jit_optimizer_section_ptr cur_section, t_section, prev_section;
    opcode_t *next_op;
    op_info_t *op_info;
    char *branch;
    int i, typ, branched, start_new;

    branch = optimizer->map_branch;

    /* Allocate the first section */
    cur_section = optimizer->sections = (Parrot_jit_optimizer_section_t *)
        mem_sys_allocate_zeroed(sizeof(Parrot_jit_optimizer_section_t));
    cur_section->begin = code_start;
    prev_section = cur_section;

    cur_op = code_start;
    while (cur_section) {
        branched = start_new = 0;
        /* Predereference the opcode information for this opcode
         * early since it's going to be used many times */
        op_info = &interpreter->op_info_table[*cur_op];

        /* Calculate the next pc */
        next_op = cur_op + op_info->arg_count;

        /* Update op_count */
        cur_section->op_count++;

        /* set register usage for this section */
        set_register_usage(interpreter, optimizer, cur_section,
                op_info, cur_op, code_start);

        /*
         * End a section:
         * If this opcode is jitted and next calls a C function */
        if (!op_jit[*cur_op].extcall) {
            cur_section->jit_op_count++;

            if (next_op < code_end && op_jit[*next_op].extcall)
                start_new = 1;
        }
        else
            /* or if current section is not jitted, and the next opcode
             * is. */
            if (next_op < code_end && !op_jit[*next_op].extcall)
                start_new = 1;

        /* or when the current opcode is a branch source,
         * in other words if the opcode jumps, or if the next opcode is
         * a branch target, allocate a new section only if it's not the
         * last opcode */
        if ((branch[cur_op - code_start] & JIT_BRANCH_SOURCE)
                || (next_op < code_end &&
                    (branch[next_op - code_start] & JIT_BRANCH_TARGET))
                || (next_op >= code_end)) {
            /* remember to start a new block */
            branched = 1;
            start_new = 1;
        }

        if (start_new) {
            /* Set the type, depending on whether the current
             * instruction is external or jitted. */
            cur_section->isjit = !op_jit[*cur_op].extcall;

            /* Save the address where the section ends */
            cur_section->end = cur_op;

            if (next_op < code_end) {
                /* Allocate a new section */
                t_section = (Parrot_jit_optimizer_section_t *)
                    mem_sys_allocate_zeroed(
                            sizeof(Parrot_jit_optimizer_section_t));
                /* Add it to the double linked list */
                cur_section->next = t_section;
                t_section->prev = cur_section;
                /* Make the new section be the current one */
                cur_section = t_section;

                /* registers get either allocated per section or
                 * per basic block (i.e. one or more sections divided
                 * by branches. When allocation per block is done
                 * all sections in one block have the same block number
                 */
                if (ALLOCATE_REGISTERS_PER_SECTION || branched) {
                    cur_section->block = prev_section->block + 1;
                    prev_section = cur_section;
                }
                else
                    cur_section->block = prev_section->block;
                /* Save the address where the section begins */
                cur_section->begin = next_op;
            }
            else {
                cur_section = NULL;
            }
        }

        /* Move to the next opcode */
        cur_op = next_op;
    }
}

static void
make_branch_targets(struct Parrot_Interp *interpreter,
        Parrot_jit_optimizer_t *optimizer, opcode_t * code_start)
{
    Parrot_jit_optimizer_section_ptr cur_section, t_section;
    /* Set the branch target of this section, that is the section where
     * the program execution continues, if it ends in a branch source we
     * use the branch target and not the next section. */
    cur_section = optimizer->sections;
    while (cur_section) {
        if (optimizer->branch_list[cur_section->end - code_start]) {
            /* If the branch target is to a section before the current one
             * move from the start, otherwise from the current section */
            if (optimizer->branch_list[cur_section->end - code_start] <
                    cur_section->begin)
                t_section = optimizer->sections;
            else
                t_section = cur_section;

            while (t_section) {
                /* If we find the section attach it to the current one. */
                if (t_section->begin ==
                        optimizer->branch_list[cur_section->end - code_start]) {
                    cur_section->branch_target = t_section;
                    break;
                }
                /* If not move to the next. */
                t_section = t_section->next;
            }

        }
        /* Move to the next section */
        cur_section = cur_section->next;
    }
}

static void
sort_registers(struct Parrot_Interp *interpreter,
        Parrot_jit_optimizer_t *optimizer, opcode_t * code_start)
{
    Parrot_jit_optimizer_section_ptr cur_section, next, prev;
    int i, any, k, typ;
    int max_count, max_i = 0;
    int to_map[] = { INT_REGISTERS_TO_MAP, 0, 0, FLOAT_REGISTERS_TO_MAP };

    /* Start from the first section */
    cur_section = optimizer->sections;

    /* While there is section */
    while (cur_section) {
        Parrot_jit_register_usage_t *ru = cur_section->ru;
        /* some up register usage for one block, don't change
         * reg_dir. If allocation is done per section, block numbers
         * are different, so this is a nop
         */
        next = cur_section->next;
        while (next && next->block == cur_section->block) {
            Parrot_jit_register_usage_t *nru = next->ru;
            for (typ = 0; typ < 4; typ++)
                for (i = 0; i < NUM_REGISTERS; i++)
                    ru[typ].reg_count[i] += nru[typ].reg_count[i];
            next = next->next;
        }

        /* now sort registers by there usage count */
        for (typ = 0; typ < 4; typ++) {
            /* find most used register */
            for (i = max_count = 0; i < NUM_REGISTERS; i++) {
                if (cur_section->ru[typ].reg_count[i] > max_count) {
                    max_count = cur_section->ru[typ].reg_count[i];
                    max_i = i;
                }
            }
            /* start from this register and set usage */
            k = ru[typ].registers_used = 0;
            /* no usage, go on with next type */
            if (max_count == 0 || !to_map[typ])
                continue;
            /* as long as we map registers for this typ */
            while (1) {
                if (max_i >= 0)
                    ru[typ].reg_usage[k++] = max_i;
                /* all mapped? */
                if (k == to_map[typ])
                    break;
                /* now check for equal usage starting after maxi */
                for (any = 0, i = max_i + 1; i < NUM_REGISTERS; i++) {
                    if (ru[typ].reg_count[i] == max_count) {
                        max_i = i;
                        any = 1;
                        break;
                    }
                }
                /* if same usage not found, look for lower usage */
                if (any == 0) {
                    if (max_count > 1) {
                        max_count--;
                        max_i = -1;
                        continue;
                    }
                    break;
                }
            }
            ru[typ].registers_used = k;
        }
        next = cur_section->next;
        prev = cur_section;
        /* duplicate usage to all sections of block */
        while (next && next->block == cur_section->block) {
            Parrot_jit_register_usage_t *nru = next->ru;
            for (typ = 0; typ < 4; typ++) {
                for (i = 0; i < ru[typ].registers_used; i++) {
                    nru[typ].reg_count[i] = ru[typ].reg_count[i];
                    nru[typ].reg_usage[i] = ru[typ].reg_usage[i];
#if 0
Not yet: We must classify external functions what they do
    e.g. stack pop operations change registers, which we dont know
    because we have no ARGDIR in op_info for e.g. popi

                    /* if register was not used in non JIT section and
                     * used in next JIT section, avoid loading this
                     * register, by resetting its ARGDIR_IN
                     * but only, if prev was not a new block
                     */
                    if (prev && !prev->isjit && next->isjit &&
                            prev != cur_section &&
                            !(prev->ru[typ].reg_dir[i] & PARROT_ARGDIR_OUT)
                            && nru[typ].reg_dir[i])
                        nru[typ].reg_dir[i] &= ~PARROT_ARGDIR_IN;

                    /* if register is used in next non JIT
                     * section, save register
                     * XXX don't do that, there might later be a branch
                     * which loads a non saved register
                     */
                    if (prev && prev->isjit && !next->isjit &&
                            nru[typ].reg_dir[i])
                        prev->ru[typ].reg_dir[i] |= PARROT_ARGDIR_OUT;
                    else
                        prev->ru[typ].reg_dir[i] &= ~PARROT_ARGDIR_OUT;
#endif
                }
                nru[typ].registers_used = ru[typ].registers_used;
            }
            prev = next;
            next = next->next;
        }
        /* Move to the next section */
        cur_section = next;
    }
}

static void
assign_registers(struct Parrot_Interp *interpreter,
        Parrot_jit_optimizer_t *optimizer,
        Parrot_jit_optimizer_section_ptr cur_section,
        opcode_t * code_start)
{
    char *map;
    op_info_t *op_info;
    int i, op_arg, typ;
    opcode_t * cur_op;
    char * maps[] = {0, 0, 0, 0};
    maps[0] = intval_map;
    maps[3] = floatval_map;

    map = optimizer->map_branch;
    /* For each opcode in this section */
    cur_op = cur_section->begin;
    while (cur_op <= cur_section->end) {
        op_info = &interpreter->op_info_table[*cur_op];
        /* For each argument of the current opcode */
        for (op_arg = 1; op_arg < op_info->arg_count; op_arg++) {
            /* get the register typ */
            typ = map[cur_op + op_arg - code_start];
            /* clear the register typ/map */
            map[cur_op + op_arg - code_start] = 0;
            /* if not JITted, don't map */
            if (!cur_section->isjit)
                continue;
            if (typ > 0) {
                typ--;  /* types are + 1 */
                if (!maps[typ])
                    continue;
                /* If the argument is in most used list for this typ */
                for (i = 0; i < cur_section->ru[typ].registers_used; i++)
                    if (cur_op[op_arg] ==
                            (opcode_t)cur_section->ru[typ].reg_usage[i]) {
                        map[cur_op + op_arg - code_start] = maps[typ][i];
                        cur_section->maps++;
                        break;
                    }
            }
        }

        /* Move to the next opcode */
        cur_op += op_info->arg_count;
    }
}

static void
map_registers(struct Parrot_Interp *interpreter,
        Parrot_jit_optimizer_t *optimizer, opcode_t * code_start)
{
    Parrot_jit_optimizer_section_ptr cur_section;

    /* Start from the first section */
    cur_section = optimizer->sections;

    /* While there is section */
    while (cur_section) {

        assign_registers(interpreter, optimizer, cur_section, code_start);

        /* Move to the next section */
        cur_section = cur_section->next;
    }
}


#define JIT_DEBUG 0

#if JIT_DEBUG
static void
debug_sections(struct Parrot_Interp *interpreter,
        Parrot_jit_optimizer_t *optimizer, opcode_t * code_start)
{
    Parrot_jit_optimizer_section_ptr cur_section;
    op_info_t *op_info;
    opcode_t * cur_op;
#if JIT_DEBUG > 1
    char * map = optimizer->map_branch;
#endif
    int i, typ;
    unsigned int j;
    const char *types = "IPSN";
    int t_l[] = {0,3};

    cur_section = optimizer->sections;
    while (cur_section) {
        Parrot_jit_register_usage_t *ru = cur_section->ru;

        PIO_eprintf(interpreter, "\nSection:\n");
        PIO_eprintf(interpreter, "%s block %d\n",
                (cur_section->isjit) ? "JITTED" : "NOT JITTED",
                cur_section->block);
        for (cur_op = cur_section->begin; cur_op <= cur_section->end;) {
            char instr[256];
            op_info = &interpreter->op_info_table[*cur_op];
            PDB_disassemble_op(interpreter, instr, sizeof(instr),
                    op_info, cur_op, NULL, code_start, 0);
            PIO_eprintf(interpreter, "\t\tOP%vu: %s\n",
                    cur_op - code_start, instr);
#if JIT_DEBUG > 1
            PIO_eprintf(interpreter, "\t\t\tmap_branch: ");
            for (i = 0; i < op_info->arg_count; i++)
                PIO_eprintf(interpreter, "%02x ", map[cur_op-code_start+i]);
            PIO_eprintf(interpreter, "\n");
#endif

            cur_op += op_info->arg_count;
        }
        PIO_eprintf(interpreter, "\tbegin:\t%#p\t(%Ou)\n",
                cur_section->begin, *cur_section->begin);
        PIO_eprintf(interpreter, "\tend:\t%#p\t(%Ou)\n",
                cur_section->end, *cur_section->end);

        for (j = 0; j < sizeof(t_l)/sizeof(int); j++) {
            char t;
            typ = t_l[j];
            t = types[typ];
            PIO_eprintf(interpreter, "\t%c registers used:\t%i\n",
                    t, ru[typ].registers_used);
            if (1 || ru[typ].registers_used) {
                PIO_eprintf(interpreter, "\t%c register count:\t", t);
                for (i = 0; i < NUM_REGISTERS; i++)
                    PIO_eprintf(interpreter, "%i ", ru[typ].reg_count[i]);
                PIO_eprintf(interpreter, "\n\t%c register usage:\t", t);
                for (i = 0; i < NUM_REGISTERS; i++)
                    PIO_eprintf(interpreter, "%i ", ru[typ].reg_usage[i]);
                PIO_eprintf(interpreter, "\n\t%c register direction:\t", t);
                for (i = 0; i < NUM_REGISTERS; i++)
                    PIO_eprintf(interpreter, "%i ", (int)ru[typ].reg_dir[i]);
                PIO_eprintf(interpreter, "\n");
            }
        }
        PIO_eprintf(interpreter, "\tJit opcodes:\t%u\n",
                cur_section->jit_op_count);
        PIO_eprintf(interpreter, "\tTotal opcodes:\t%u\n",
                cur_section->op_count);
        if (cur_section->branch_target)
            PIO_eprintf(interpreter, "\tBranch target:\tOP%u\n",
                    cur_section->branch_target->begin - code_start);

        cur_section = cur_section->next;
    }
}
#endif

/*
 * optimize_jit()
 */

static Parrot_jit_optimizer_t *
optimize_jit(struct Parrot_Interp *interpreter, opcode_t *cur_op,
             opcode_t *code_start, opcode_t *code_end)
{
    Parrot_jit_optimizer_t *optimizer;

    /* Allocate space for the optimizer */
    optimizer = (Parrot_jit_optimizer_t *)
        mem_sys_allocate_zeroed(sizeof(Parrot_jit_optimizer_t));

    /* Look, which opcodes might branch */
    make_branch_list(interpreter, optimizer, cur_op, code_start, code_end);

    /* ok, let's loop again and generate the sections */
    make_sections(interpreter, optimizer, cur_op, code_start, code_end);

    /* look where a section jumps too */
    make_branch_targets(interpreter, optimizer, code_start);

    /* This is where we start deciding which Parrot registers get
     * mapped to a hardware one in each different section. */

#if JIT_DEBUG > 2
    debug_sections(interpreter, optimizer, code_start);
#endif
    sort_registers(interpreter, optimizer, code_start);
    map_registers(interpreter, optimizer, code_start);

#if JIT_DEBUG
    debug_sections(interpreter, optimizer, code_start);
#endif

    return optimizer;
}

static char *
reg_addr(struct Parrot_Interp * interpreter, int typ, int i)
{
    switch (typ) {
        case 0:
            return (char*)&interpreter->ctx.int_reg.registers[i];
        case 3:
            return (char*)&interpreter->ctx.num_reg.registers[i];
        default:
            return 0;   /* not currently */
    }
}

/* Load registers for the current section from parrot to
 * processor registers
 */

static void
Parrot_jit_load_registers(Parrot_jit_info_t *jit_info,
                          struct Parrot_Interp * interpreter)
{
    Parrot_jit_optimizer_section_t *sect = jit_info->optimizer->cur_section;
    Parrot_jit_register_usage_t *ru = sect->ru;
    int i, typ;
    void (*mov_f[4])(struct Parrot_Interp *, int, char *)
        = { Parrot_jit_emit_mov_rm, 0, 0, Parrot_jit_emit_mov_rm_n};
    int lasts[] = { PRESERVED_INT_REGS, 0,0,  PRESERVED_FLOAT_REGS };
    char * maps[] = {0, 0, 0, 0};
    maps[0] = jit_info->intval_map;
    maps[3] = jit_info->floatval_map;


    for (typ = 0; typ < 4; typ++) {
        if (maps[typ]) {
            for (i = ru[typ].registers_used-1; i >= 0; --i) {
                int us = ru[typ].reg_usage[i];
                if ((i >= lasts[typ] && ru[typ].reg_dir[us]) ||
                        (ru[typ].reg_dir[us] & PARROT_ARGDIR_IN)) {
                    char *m = reg_addr(interpreter, typ, us);
                    (mov_f[typ])(interpreter, maps[typ][i], m);
                }
            }
        }
    }

    /* The total size of the loads. This is used for branches to
     * the same section - these skip the load asm bytes */
    sect->load_size = jit_info->native_ptr -
        (jit_info->arena.start +
         jit_info->arena.op_map[jit_info->op_i].offset);
}

/* Save registers for the current section */
static void
Parrot_jit_save_registers(Parrot_jit_info_t *jit_info,
                          struct Parrot_Interp * interpreter)
{
    Parrot_jit_optimizer_section_t *sect = jit_info->optimizer->cur_section;
    Parrot_jit_register_usage_t *ru = sect->ru;
    int i, typ;
    void (*mov_f[4])(struct Parrot_Interp * , char *, int)
        = { Parrot_jit_emit_mov_mr, 0, 0, Parrot_jit_emit_mov_mr_n};
    int lasts[] = { PRESERVED_INT_REGS, 0,0,  PRESERVED_FLOAT_REGS };
    char * maps[] = {0, 0, 0, 0};
    maps[0] = jit_info->intval_map;
    maps[3] = jit_info->floatval_map;

    for (typ = 0; typ < 4; typ++) {
        if (maps[typ])
            for (i = 0; i < ru[typ].registers_used; ++i) {
                int us = ru[typ].reg_usage[i];
                if ((i >= lasts[typ] && ru[typ].reg_dir[us]) ||
                    ru[typ].reg_dir[us] & PARROT_ARGDIR_OUT) {
                    char *m = reg_addr(interpreter, typ, us);
                    (mov_f[typ])(interpreter, m, maps[typ][i]);
                }
            }
    }
}

void
Parrot_destroy_jit(struct Parrot_Interp *interpreter)
{
    Parrot_jit_info_t *jit_info;
    Parrot_jit_optimizer_t *optimizer;
    Parrot_jit_optimizer_section_ptr cur_section, next;
    Parrot_jit_fixup_t *fixup, *next_f;

    jit_info = interpreter->jit_info;
    if (!jit_info)
        return;
    /* delete sections */
    optimizer = jit_info->optimizer;
    cur_section = optimizer->sections;
    while (cur_section) {
        next = cur_section->next;
        free(cur_section);
        cur_section = next;
    }
    /* arena stuff */
    free(jit_info->arena.op_map);
    free(jit_info->arena.start);
    fixup = jit_info->arena.fixups;
    while (fixup) {
        next_f = fixup->next;
        free(fixup);
        fixup = next_f;
    }
    /* optimizer stuff */
    free(optimizer->map_branch);
    free(optimizer->branch_list);
    free(optimizer);

    free(jit_info);
}

/*
** build_asm()
*/

jit_f
build_asm(struct Parrot_Interp *interpreter, opcode_t *pc,
          opcode_t *code_start, opcode_t *code_end)
{
    UINTVAL i;
    char *new_arena;
    Parrot_jit_info_t *jit_info = NULL;
    opcode_t cur_opcode_byte, *cur_op;
    Parrot_jit_optimizer_section_ptr cur_section;
    char *map;


    /* XXX assume, we restart */
    if (pc != code_start && interpreter->jit_info) {
        jit_info = interpreter->jit_info;
        return (jit_f)D2FPTR(jit_info->arena.start);
    }
    if (!interpreter->jit_info)
        jit_info = interpreter->jit_info =
            mem_sys_allocate(sizeof(Parrot_jit_info_t));

    jit_info->optimizer = optimize_jit(interpreter, pc, code_start, code_end);

    /* Attach the register map to the jit_info structure */
    jit_info->intval_map = intval_map;
    jit_info->floatval_map = floatval_map;


    /* Byte code size in opcode_t's */
    jit_info->arena.map_size = (code_end - code_start) + 1;
    jit_info->arena.op_map =
        (Parrot_jit_opmap_t *)mem_sys_allocate_zeroed(
            jit_info->arena.map_size * sizeof(* (jit_info->arena.op_map)));

#if REQUIRES_CONSTANT_POOL
    Parrot_jit_init_arenas(jit_info);
#else
    jit_info->arena.size = 1024;
    /* estimate size needed
     * 10 times pbc code size seems to be enough for i386
     */
    if ((size_t)jit_info->arena.map_size * 10 > (size_t)jit_info->arena.size)
        jit_info->arena.size = jit_info->arena.map_size * 10;
    jit_info->native_ptr = jit_info->arena.start =
        mem_sys_allocate_zeroed((size_t)jit_info->arena.size);
#endif

    jit_info->op_i = 0;
    jit_info->arena.fixups = NULL;

    /*
     *   op_map holds the offset from arena.start
     *   of the parrot op at the given opcode index
     *
     *  bytecode:       56  1   1   56  1   1
     *  op_map:         3   0   0   15  0   0
     */

    Parrot_jit_begin(jit_info, interpreter);

    /* Set the offset of the first opcode */
    jit_info->arena.op_map[jit_info->op_i].offset =
        jit_info->native_ptr - jit_info->arena.start;

    /* The first section */
    cur_section = jit_info->optimizer->cur_section =
        jit_info->optimizer->sections;
    map = jit_info->optimizer->map_branch;

    while (jit_info->optimizer->cur_section) {
        /* the code emitting functions need cur_op and cur_section
         * so these vars are in jit_info too
         */

        /* The first opcode for this section */
        cur_op = jit_info->cur_op = cur_section->begin;

        /* Load mapped registers for this section, if JIT */
        if (cur_section->isjit && cur_section->prev) {
            Parrot_jit_load_registers(jit_info, interpreter);
        }

        /* The first opcode of each section doesn't have a previous one since
         * it's impossible to be sure which was it */
        jit_info->prev_op = NULL;

        while (cur_op <= cur_section->end) {
            /* Grow the arena early */
            if (jit_info->arena.size <
                    (jit_info->arena.op_map[jit_info->op_i].offset + 100)) {
#if REQUIRES_CONSTANT_POOL
                Parrot_jit_extend_arena(jit_info);
#else
                new_arena = mem_sys_realloc(jit_info->arena.start,
                        (size_t)jit_info->arena.size * 2);
                jit_info->arena.size *= 2;
                jit_info->native_ptr = new_arena +
                    (jit_info->native_ptr - jit_info->arena.start);
                jit_info->arena.start = new_arena;
#endif
            }

            cur_opcode_byte = *cur_op;

            /* Need to save the registers if there is a branch and is not to
             * the same section, I admit I don't like this, and it should be
             * really checking if the target section has the same registers
             * mapped too. */
            if ((map[cur_op - code_start] == JIT_BRANCH_SOURCE) &&
                    (cur_section->branch_target != cur_section) &&
                    cur_section->isjit) {
                Parrot_jit_save_registers(jit_info, interpreter);
            }

            /* Generate native code for current op */
            (op_jit[cur_opcode_byte].fn) (jit_info, interpreter);

            /* Update the previous opcode */
            jit_info->prev_op = cur_op;

            /* update op_i and cur_op accordingly */
            jit_info->op_i +=
                interpreter->op_info_table[cur_opcode_byte].arg_count;
            jit_info->cur_op +=
                interpreter->op_info_table[cur_opcode_byte].arg_count;
            cur_op = jit_info->cur_op;

            /* if this is a branch target, align it */
#ifdef jit_emit_noop
#  if JUMP_ALIGN
            if (map[cur_op - code_start] == JIT_BRANCH_TARGET) {
                while ((long)jit_info->native_ptr & ((1<<JUMP_ALIGN) - 1))
                    jit_emit_noop(jit_info->native_ptr);
            }
#  endif
#endif

            /* set the offset */
            jit_info->arena.op_map[jit_info->op_i].offset =
                jit_info->native_ptr - jit_info->arena.start;
        }

        /* Save mapped registers back to the Parrot registers */
        if (cur_section->isjit)
            Parrot_jit_save_registers(jit_info, interpreter);

        /* update the offset for saved registers */
        jit_info->arena.op_map[jit_info->op_i].offset =
            jit_info->native_ptr - jit_info->arena.start;

        /* Move to the next section */
        cur_section = jit_info->optimizer->cur_section =
            cur_section->next;
    }

    /* Do fixups before converting offsets */
    Parrot_jit_dofixup(jit_info, interpreter);

    /* Convert offsets to pointers */
    for (i = 0; i < jit_info->arena.map_size; i++) {

        /* Assuming native code chunks contain some initialization code,
         * the first op (and every other op) is at an offset > 0
         */
        if (jit_info->arena.op_map[i].offset) {
            jit_info->arena.op_map[i].ptr = (char *)jit_info->arena.start +
                jit_info->arena.op_map[i].offset;
        }
    }

#if JIT_DEBUG
    PIO_eprintf(interpreter, "\nTotal size %u bytes\n",
            (unsigned int)(jit_info->native_ptr - jit_info->arena.start));
#endif

#ifdef ARM
    arm_sync_d_i_cache(jit_info->arena.start, jit_info->native_ptr);
#endif
#ifdef PPC
    ppc_sync_cache(jit_info->arena.start, jit_info->native_ptr);
#endif

    /* assume gdb is available: generate symbol information  */
#ifdef __GNUC__
    if (Interp_flags_TEST(interpreter, PARROT_DEBUG_FLAG))
        Parrot_jit_debug(interpreter);
#endif

    return (jit_f)D2FPTR(jit_info->arena.start);
}

/* Remember the current position in the native code for later update */
void
Parrot_jit_newfixup(Parrot_jit_info_t *jit_info)
{
    Parrot_jit_fixup_t *fixup;

    fixup = mem_sys_allocate_zeroed(sizeof(*fixup));

    if (!fixup)
        internal_exception(ALLOCATION_ERROR,
                           "System memory allocation failed\n");

    /* Insert fixup at the head of the list */
    fixup->next = jit_info->arena.fixups;
    jit_info->arena.fixups = fixup;

    /* Fill in the native code offset */
    fixup->native_offset =
        (ptrdiff_t)(jit_info->native_ptr - jit_info->arena.start);
}

/*
 * Local variables:
 * c-indentation-style: bsd
 * c-basic-offset: 4
 * indent-tabs-mode: nil
 * End:
 *
 * vim: expandtab shiftwidth=4:
*/
