/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     LOW_PREC = 258,
     PARAM = 259,
     PRAGMA = 260,
     N_OPERATORS = 261,
     HLL = 262,
     HLL_MAP = 263,
     GOTO = 264,
     ARG = 265,
     IF = 266,
     UNLESS = 267,
     PNULL = 268,
     ADV_FLAT = 269,
     ADV_SLURPY = 270,
     ADV_OPTIONAL = 271,
     ADV_OPT_FLAG = 272,
     ADV_NAMED = 273,
     ADV_ARROW = 274,
     NEW = 275,
     ADV_INVOCANT = 276,
     NAMESPACE = 277,
     ENDNAMESPACE = 278,
     DOT_METHOD = 279,
     SUB = 280,
     SYM = 281,
     LOCAL = 282,
     LEXICAL = 283,
     CONST = 284,
     INC = 285,
     DEC = 286,
     GLOBAL_CONST = 287,
     PLUS_ASSIGN = 288,
     MINUS_ASSIGN = 289,
     MUL_ASSIGN = 290,
     DIV_ASSIGN = 291,
     CONCAT_ASSIGN = 292,
     BAND_ASSIGN = 293,
     BOR_ASSIGN = 294,
     BXOR_ASSIGN = 295,
     FDIV = 296,
     FDIV_ASSIGN = 297,
     MOD_ASSIGN = 298,
     SHR_ASSIGN = 299,
     SHL_ASSIGN = 300,
     SHR_U_ASSIGN = 301,
     SHIFT_LEFT = 302,
     SHIFT_RIGHT = 303,
     INTV = 304,
     FLOATV = 305,
     STRINGV = 306,
     PMCV = 307,
     LOG_XOR = 308,
     RELOP_EQ = 309,
     RELOP_NE = 310,
     RELOP_GT = 311,
     RELOP_GTE = 312,
     RELOP_LT = 313,
     RELOP_LTE = 314,
     GLOBAL = 315,
     GLOBALOP = 316,
     ADDR = 317,
     RESULT = 318,
     RETURN = 319,
     YIELDT = 320,
     GET_RESULTS = 321,
     POW = 322,
     SHIFT_RIGHT_U = 323,
     LOG_AND = 324,
     LOG_OR = 325,
     COMMA = 326,
     ESUB = 327,
     DOTDOT = 328,
     PCC_BEGIN = 329,
     PCC_END = 330,
     PCC_CALL = 331,
     PCC_SUB = 332,
     PCC_BEGIN_RETURN = 333,
     PCC_END_RETURN = 334,
     PCC_BEGIN_YIELD = 335,
     PCC_END_YIELD = 336,
     NCI_CALL = 337,
     METH_CALL = 338,
     INVOCANT = 339,
     MAIN = 340,
     LOAD = 341,
     INIT = 342,
     IMMEDIATE = 343,
     POSTCOMP = 344,
     METHOD = 345,
     ANON = 346,
     OUTER = 347,
     NEED_LEX = 348,
     MULTI = 349,
     VTABLE_METHOD = 350,
     LOADLIB = 351,
     SUB_INSTANCE_OF = 352,
     SUB_LEXID = 353,
     UNIQUE_REG = 354,
     LABEL = 355,
     EMIT = 356,
     EOM = 357,
     IREG = 358,
     NREG = 359,
     SREG = 360,
     PREG = 361,
     IDENTIFIER = 362,
     REG = 363,
     MACRO = 364,
     ENDM = 365,
     STRINGC = 366,
     INTC = 367,
     FLOATC = 368,
     USTRINGC = 369,
     PARROT_OP = 370,
     VAR = 371,
     LINECOMMENT = 372,
     FILECOMMENT = 373,
     DOT = 374,
     CONCAT = 375
   };
#endif
/* Tokens.  */
#define LOW_PREC 258
#define PARAM 259
#define PRAGMA 260
#define N_OPERATORS 261
#define HLL 262
#define HLL_MAP 263
#define GOTO 264
#define ARG 265
#define IF 266
#define UNLESS 267
#define PNULL 268
#define ADV_FLAT 269
#define ADV_SLURPY 270
#define ADV_OPTIONAL 271
#define ADV_OPT_FLAG 272
#define ADV_NAMED 273
#define ADV_ARROW 274
#define NEW 275
#define ADV_INVOCANT 276
#define NAMESPACE 277
#define ENDNAMESPACE 278
#define DOT_METHOD 279
#define SUB 280
#define SYM 281
#define LOCAL 282
#define LEXICAL 283
#define CONST 284
#define INC 285
#define DEC 286
#define GLOBAL_CONST 287
#define PLUS_ASSIGN 288
#define MINUS_ASSIGN 289
#define MUL_ASSIGN 290
#define DIV_ASSIGN 291
#define CONCAT_ASSIGN 292
#define BAND_ASSIGN 293
#define BOR_ASSIGN 294
#define BXOR_ASSIGN 295
#define FDIV 296
#define FDIV_ASSIGN 297
#define MOD_ASSIGN 298
#define SHR_ASSIGN 299
#define SHL_ASSIGN 300
#define SHR_U_ASSIGN 301
#define SHIFT_LEFT 302
#define SHIFT_RIGHT 303
#define INTV 304
#define FLOATV 305
#define STRINGV 306
#define PMCV 307
#define LOG_XOR 308
#define RELOP_EQ 309
#define RELOP_NE 310
#define RELOP_GT 311
#define RELOP_GTE 312
#define RELOP_LT 313
#define RELOP_LTE 314
#define GLOBAL 315
#define GLOBALOP 316
#define ADDR 317
#define RESULT 318
#define RETURN 319
#define YIELDT 320
#define GET_RESULTS 321
#define POW 322
#define SHIFT_RIGHT_U 323
#define LOG_AND 324
#define LOG_OR 325
#define COMMA 326
#define ESUB 327
#define DOTDOT 328
#define PCC_BEGIN 329
#define PCC_END 330
#define PCC_CALL 331
#define PCC_SUB 332
#define PCC_BEGIN_RETURN 333
#define PCC_END_RETURN 334
#define PCC_BEGIN_YIELD 335
#define PCC_END_YIELD 336
#define NCI_CALL 337
#define METH_CALL 338
#define INVOCANT 339
#define MAIN 340
#define LOAD 341
#define INIT 342
#define IMMEDIATE 343
#define POSTCOMP 344
#define METHOD 345
#define ANON 346
#define OUTER 347
#define NEED_LEX 348
#define MULTI 349
#define VTABLE_METHOD 350
#define LOADLIB 351
#define SUB_INSTANCE_OF 352
#define SUB_LEXID 353
#define UNIQUE_REG 354
#define LABEL 355
#define EMIT 356
#define EOM 357
#define IREG 358
#define NREG 359
#define SREG 360
#define PREG 361
#define IDENTIFIER 362
#define REG 363
#define MACRO 364
#define ENDM 365
#define STRINGC 366
#define INTC 367
#define FLOATC 368
#define USTRINGC 369
#define PARROT_OP 370
#define VAR 371
#define LINECOMMENT 372
#define FILECOMMENT 373
#define DOT 374
#define CONCAT 375




/* Copy the first part of user declarations.  */
#line 1 "compilers/imcc/imcc.y"

/*
 * imcc.y
 *
 * Intermediate Code Compiler for Parrot.
 *
 * Copyright (C) 2002 Melvin Smith <melvin.smith@mindspring.com>
 * Copyright (C) 2002-2008, The Perl Foundation.
 *
 * Grammar of the PIR language parser.
 *
 * $Id$
 *
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define _PARSER
#define PARSER_MAIN
#include "imc.h"
#include "parrot/dynext.h"
#include "pbc.h"
#include "parser.h"
#include "optimizer.h"

/* prevent declarations of malloc() and free() in the generated parser. */
#define YYMALLOC
#define YYFREE

#ifndef YYENABLE_NLS
#  define YYENABLE_NLS 0
#endif

#ifndef YYLTYPE_IS_TRIVIAL
#  define YYLTYPE_IS_TRIVIAL 0
#endif

/* HEADERIZER HFILE: compilers/imcc/imc.h */

/* HEADERIZER BEGIN: static */
/* Don't modify between HEADERIZER BEGIN / HEADERIZER END.  Your changes will be lost. */

static void add_pcc_named_arg(PARROT_INTERP,
    ARGMOD(SymReg *cur_call),
    ARGIN(const char *name),
    ARGIN(SymReg *value))
        __attribute__nonnull__(1)
        __attribute__nonnull__(2)
        __attribute__nonnull__(3)
        __attribute__nonnull__(4)
        FUNC_MODIFIES(*cur_call);

static void add_pcc_named_param(PARROT_INTERP,
    ARGMOD(SymReg *cur_call),
    ARGIN(const char *name),
    ARGIN(SymReg *value))
        __attribute__nonnull__(1)
        __attribute__nonnull__(2)
        __attribute__nonnull__(3)
        __attribute__nonnull__(4)
        FUNC_MODIFIES(*cur_call);

static void add_pcc_named_result(PARROT_INTERP,
    ARGMOD(SymReg *cur_call),
    ARGIN(const char *name),
    ARGIN(SymReg *value))
        __attribute__nonnull__(1)
        __attribute__nonnull__(2)
        __attribute__nonnull__(3)
        __attribute__nonnull__(4)
        FUNC_MODIFIES(*cur_call);

static void add_pcc_named_return(PARROT_INTERP,
    ARGMOD(SymReg *cur_call),
    ARGIN(const char *name),
    ARGIN(SymReg *value))
        __attribute__nonnull__(1)
        __attribute__nonnull__(2)
        __attribute__nonnull__(3)
        __attribute__nonnull__(4)
        FUNC_MODIFIES(*cur_call);

static void adv_named_set(PARROT_INTERP, ARGIN(char *name))
        __attribute__nonnull__(1)
        __attribute__nonnull__(2);

static void begin_return_or_yield(PARROT_INTERP, int yield)
        __attribute__nonnull__(1);

static void clear_state(PARROT_INTERP)
        __attribute__nonnull__(1);

static void do_loadlib(PARROT_INTERP, ARGIN(const char *lib))
        __attribute__nonnull__(1)
        __attribute__nonnull__(2);

PARROT_WARN_UNUSED_RESULT
PARROT_CAN_RETURN_NULL
static Instruction* func_ins(PARROT_INTERP,
    ARGMOD(IMC_Unit *unit),
    ARGIN(SymReg *lhs),
    ARGIN(const char *op),
    ARGMOD(SymReg **r),
    int n,
    int keyv,
    int emit)
        __attribute__nonnull__(1)
        __attribute__nonnull__(2)
        __attribute__nonnull__(3)
        __attribute__nonnull__(4)
        __attribute__nonnull__(5)
        FUNC_MODIFIES(*unit)
        FUNC_MODIFIES(*r);

PARROT_CAN_RETURN_NULL
static Instruction * iINDEXFETCH(PARROT_INTERP,
    ARGMOD(IMC_Unit *unit),
    ARGIN(SymReg *r0),
    ARGIN(SymReg *r1),
    ARGIN(SymReg *r2))
        __attribute__nonnull__(1)
        __attribute__nonnull__(2)
        __attribute__nonnull__(3)
        __attribute__nonnull__(4)
        __attribute__nonnull__(5)
        FUNC_MODIFIES(*unit);

PARROT_CAN_RETURN_NULL
static Instruction * iINDEXSET(PARROT_INTERP,
    ARGMOD(IMC_Unit *unit),
    ARGIN(SymReg *r0),
    ARGIN(SymReg *r1),
    ARGIN(SymReg *r2))
        __attribute__nonnull__(1)
        __attribute__nonnull__(2)
        __attribute__nonnull__(3)
        __attribute__nonnull__(4)
        __attribute__nonnull__(5)
        FUNC_MODIFIES(*unit);

PARROT_CANNOT_RETURN_NULL
static Instruction * iLABEL(PARROT_INTERP,
    ARGMOD_NULLOK(IMC_Unit *unit),
    ARGMOD(SymReg *r0))
        __attribute__nonnull__(1)
        __attribute__nonnull__(3)
        FUNC_MODIFIES(*r0);

PARROT_WARN_UNUSED_RESULT
PARROT_CAN_RETURN_NULL
static const char * inv_op(ARGIN(const char *op))
        __attribute__nonnull__(1);

PARROT_CANNOT_RETURN_NULL
static Instruction * iSUBROUTINE(PARROT_INTERP,
    ARGMOD_NULLOK(IMC_Unit *unit),
    ARGMOD(SymReg *r))
        __attribute__nonnull__(1)
        __attribute__nonnull__(3)
        FUNC_MODIFIES(*r);

PARROT_IGNORABLE_RESULT
PARROT_CAN_RETURN_NULL
static Instruction * MK_I(PARROT_INTERP,
    ARGMOD(IMC_Unit *unit),
    ARGIN(const char *fmt),
    int n,
    ...)
        __attribute__nonnull__(1)
        __attribute__nonnull__(2)
        __attribute__nonnull__(3)
        FUNC_MODIFIES(*unit);

PARROT_WARN_UNUSED_RESULT
PARROT_CAN_RETURN_NULL
static Instruction* mk_pmc_const(PARROT_INTERP,
    ARGMOD(IMC_Unit *unit),
    ARGIN(const char *type),
    ARGMOD(SymReg *left),
    ARGIN(const char *constant))
        __attribute__nonnull__(1)
        __attribute__nonnull__(2)
        __attribute__nonnull__(3)
        __attribute__nonnull__(4)
        __attribute__nonnull__(5)
        FUNC_MODIFIES(*unit)
        FUNC_MODIFIES(*left);

PARROT_CANNOT_RETURN_NULL
static SymReg * mk_sub_address_fromc(PARROT_INTERP, ARGIN(const char *name))
        __attribute__nonnull__(1)
        __attribute__nonnull__(2);

PARROT_CANNOT_RETURN_NULL
static SymReg * mk_sub_address_u(PARROT_INTERP, ARGIN(const char *name))
        __attribute__nonnull__(1)
        __attribute__nonnull__(2);

static void set_lexical(PARROT_INTERP,
    ARGMOD(SymReg *r),
    ARGIN(const char *name))
        __attribute__nonnull__(1)
        __attribute__nonnull__(2)
        __attribute__nonnull__(3)
        FUNC_MODIFIES(*r);

/* Don't modify between HEADERIZER BEGIN / HEADERIZER END.  Your changes will be lost. */
/* HEADERIZER END: static */


#define YYDEBUG 1
#define YYERROR_VERBOSE 1

/*
 * We use a pure parser with the interpreter as a parameter. However this still
 * doesn't make the parser reentrant, as there are too many globals around.
 */

/*
 * Choosing instructions for Parrot is pretty easy since many are
 * polymorphic.
 */


/*
 * MK_I: build and emitb instruction by INS
 *
 * fmt may contain:
 *   op %s, %s # comment
 * or just
 *   op
 *
 *
 *  NOTE: Most usage of this function is with
 *        IMCC_INFO(interp)->cur_unit, but there are some
 *        exceptions. Thus, we can't easily factorize that piece of
 *        code.
 */

PARROT_IGNORABLE_RESULT
PARROT_CAN_RETURN_NULL
static Instruction *
MK_I(PARROT_INTERP, ARGMOD(IMC_Unit *unit), ARGIN(const char *fmt), int n, ...)
{
    char opname[64];
    char *p;
    const char *q;
    va_list ap;
    SymReg *r[IMCC_MAX_FIX_REGS];
    int i;

    for (p = opname, q = fmt; *q && *q != ' ';)
        *p++ = *q++;
    *p = 0;
    if (!*q)
        fmt = NULL;
    else
        fmt = ++q;
#ifdef OPDEBUG
    fprintf(stderr, "op '%s' format '%s' (%d)\n", opname, fmt?:"", n);
#endif
    va_start(ap, n);
    i = 0;
    for (i = 0; i < n; ++i) {
        r[i] = va_arg(ap, SymReg *);
    }
    va_end(ap);
    return INS(interp, unit, opname, fmt, r, n,
               IMCC_INFO(interp)->keyvec, 1);
}

PARROT_WARN_UNUSED_RESULT
PARROT_CAN_RETURN_NULL
static Instruction*
mk_pmc_const(PARROT_INTERP, ARGMOD(IMC_Unit *unit), ARGIN(const char *type),
        ARGMOD(SymReg *left), ARGIN(const char *constant))
{
    const int type_enum = atoi(type);
    const int ascii = (*constant == '\'' || *constant == '"');
    SymReg *rhs;
    SymReg *r[2];
    char   *name;

    if (left->type == VTADDRESS) {      /* IDENTIFIER */
        if (IMCC_INFO(interp)->state->pasm_file) {
            IMCC_fataly(interp, EXCEPTION_SYNTAX_ERROR,
                        "Ident as PMC constant",
                        " %s\n", left->name);
        }
        left->type = VTIDENTIFIER;
        left->set = 'P';
    }
    r[0] = left;
    if (ascii) {
        /* strip delimiters */
        name                   = str_dup(constant + 1);
        name[strlen(name) - 1] = '\0';
    }
    else {
        name = str_dup(constant);
    }

    switch (type_enum) {
        case enum_class_Sub:
        case enum_class_Coroutine:
            rhs = mk_const(interp, name, 'p');

            if (!ascii)
                rhs->type |= VT_ENCODED;

            rhs->usage    = U_FIXUP;
            break;
        default:
            rhs = mk_const(interp, name, 'P');
            break;
    }

    r[1]          = rhs;
    rhs->pmc_type = type_enum;

    mem_sys_free(name);

    return INS(interp, unit, "set_p_pc", "", r, 2, 0, 1);
}

PARROT_WARN_UNUSED_RESULT
PARROT_CAN_RETURN_NULL
static Instruction*
func_ins(PARROT_INTERP, ARGMOD(IMC_Unit *unit), ARGIN(SymReg *lhs), ARGIN(const char *op),
         ARGMOD(SymReg **r), int n, int keyv, int emit)
{
    int i;
    /* shift regs up by 1 */
    for (i = n - 1; i >= 0; --i)
        r[i+1] = r[i];
    r[0] = lhs;
    /* shift keyvec */
    keyv <<= 1;
    return INS(interp, unit, op, "", r, n+1, keyv, emit);
}
/*
 * special instructions
 *
 * labels and such
 */

static void
clear_state(PARROT_INTERP)
{
    IMCC_INFO(interp) -> nargs = 0;
    IMCC_INFO(interp) -> keyvec = 0;
}

PARROT_CANNOT_RETURN_NULL
Instruction *
INS_LABEL(PARROT_INTERP, ARGMOD_NULLOK(IMC_Unit *unit), ARGMOD(SymReg *r0), int emit)
{

    Instruction * const ins = _mk_instruction("", "%s:", 1, &r0, 0);
    ins->type               = ITLABEL;
    r0->first_ins           = ins;

    if (emit)
        emitb(interp, unit, ins);

    return ins;
}

PARROT_CANNOT_RETURN_NULL
static Instruction *
iLABEL(PARROT_INTERP, ARGMOD_NULLOK(IMC_Unit *unit), ARGMOD(SymReg *r0))
{
    Instruction * const i = INS_LABEL(interp, unit, r0, 1);
    i->line               = IMCC_INFO(interp)->line;

    clear_state(interp);
    return i;
}

PARROT_CANNOT_RETURN_NULL
static Instruction *
iSUBROUTINE(PARROT_INTERP, ARGMOD_NULLOK(IMC_Unit *unit), ARGMOD(SymReg *r))
{
    Instruction * const i = iLABEL(interp, unit, r);

    r->type    = (r->type & VT_ENCODED) ? VT_PCC_SUB|VT_ENCODED : VT_PCC_SUB;
    r->pcc_sub = mem_allocate_zeroed_typed(pcc_sub_t);

    IMCC_INFO(interp)->cur_call = r;
    i->line                     = IMCC_INFO(interp)->line;

    add_namespace(interp, unit);
    return i;
}

/*
 * substr or X = P[key]
 */
PARROT_CAN_RETURN_NULL
static Instruction *
iINDEXFETCH(PARROT_INTERP, ARGMOD(IMC_Unit *unit), ARGIN(SymReg *r0), ARGIN(SymReg *r1),
        ARGIN(SymReg *r2))
{
    if (r0->set == 'S' && r1->set == 'S' && r2->set == 'I') {
        SymReg * const r3 = mk_const(interp, "1", 'I');
        return MK_I(interp, unit, "substr %s, %s, %s, 1", 4, r0, r1, r2, r3);
    }

    IMCC_INFO(interp) -> keyvec |= KEY_BIT(2);
    return MK_I(interp, unit, "set %s, %s[%s]", 3, r0, r1, r2);
}

/*
 * substr or P[key] = X
 */

PARROT_CAN_RETURN_NULL
static Instruction *
iINDEXSET(PARROT_INTERP, ARGMOD(IMC_Unit *unit), ARGIN(SymReg *r0), ARGIN(SymReg *r1),
        ARGIN(SymReg *r2))
{
    if (r0->set == 'S' && r1->set == 'I' && r2->set == 'S') {
        SymReg * const r3 = mk_const(interp, "1", 'I');
        MK_I(interp, unit, "substr %s, %s, %s, %s", 4, r0, r1, r3, r2);
    }
    else if (r0->set == 'P') {
        IMCC_INFO(interp)->keyvec |= KEY_BIT(1);
        MK_I(interp, unit, "set %s[%s], %s", 3, r0, r1, r2);
    }
    else
        IMCC_fataly(interp, EXCEPTION_SYNTAX_ERROR,
            "unsupported indexed set op\n");

    return NULL;
}

PARROT_WARN_UNUSED_RESULT
PARROT_CAN_RETURN_NULL
static const char *
inv_op(ARGIN(const char *op))
{
    int n;
    return get_neg_op(op, &n);
}

PARROT_CANNOT_RETURN_NULL
Instruction *
IMCC_create_itcall_label(PARROT_INTERP)
{
    char         name[128];
    SymReg      *r;
    Instruction *i;

    snprintf(name, sizeof (name), "%cpcc_sub_call_%d", IMCC_INTERNAL_CHAR,
        IMCC_INFO(interp)->cnr++);

    r       = mk_pcc_sub(interp, name, 0);
    i       = iLABEL(interp, IMCC_INFO(interp)->cur_unit, r);
    i->type = ITCALL | ITPCCSUB;

    IMCC_INFO(interp)->cur_call = r;

    return i;
}

PARROT_CANNOT_RETURN_NULL
static SymReg *
mk_sub_address_fromc(PARROT_INTERP, ARGIN(const char *name))
{
    /* name is a quoted sub name */
    SymReg *r;
    char *name_copy                  = str_dup(name + 1);
    name_copy[strlen(name_copy) - 1] = '\0';

    r = mk_sub_address(interp, name_copy);
    mem_sys_free(name_copy);

    return r;
}

PARROT_CANNOT_RETURN_NULL
static SymReg *
mk_sub_address_u(PARROT_INTERP, ARGIN(const char *name))
{
    SymReg * const r = mk_sub_address(interp, name);
    r->type         |= VT_ENCODED;

    return r;
}

void
IMCC_itcall_sub(PARROT_INTERP, ARGIN(SymReg *sub))
{
    IMCC_INFO(interp)->cur_call->pcc_sub->sub = sub;
    if (IMCC_INFO(interp)->cur_obj) {
        if (IMCC_INFO(interp)->cur_obj->set != 'P')
            IMCC_fataly(interp, EXCEPTION_SYNTAX_ERROR, "object isn't a PMC");
        IMCC_INFO(interp)->cur_call->pcc_sub->object = IMCC_INFO(interp)->cur_obj;
        IMCC_INFO(interp)->cur_obj = NULL;
    }
    if (IMCC_INFO(interp)->cur_call->pcc_sub->sub->pmc_type == enum_class_NCI)
        IMCC_INFO(interp)->cur_call->pcc_sub->flags |= isNCI;
    if (IMCC_INFO(interp)->cur_unit->type == IMC_PCCSUB)
        IMCC_INFO(interp)->cur_unit->instructions->symregs[0]->pcc_sub->calls_a_sub |= 1;
}

static void
begin_return_or_yield(PARROT_INTERP, int yield)
{
    Instruction *i;
    Instruction * const ins = IMCC_INFO(interp)->cur_unit->instructions;
    char                name[128];

    if (!ins || !ins->symregs[0] || !(ins->symregs[0]->type & VT_PCC_SUB))
        IMCC_fataly(interp, EXCEPTION_SYNTAX_ERROR,
                    "yield or return directive outside pcc subroutine\n");
    if (yield)
       ins->symregs[0]->pcc_sub->calls_a_sub = 1 | ITPCCYIELD;
    snprintf(name, sizeof (name), yield ? "%cpcc_sub_yield_%d" : "%cpcc_sub_ret_%d",
            IMCC_INTERNAL_CHAR, IMCC_INFO(interp)->cnr++);
    interp->imc_info->sr_return = mk_pcc_sub(interp, name, 0);
    i = iLABEL(interp, IMCC_INFO(interp)->cur_unit, interp->imc_info->sr_return);
    i->type = yield ? ITPCCSUB | ITLABEL | ITPCCYIELD : ITPCCSUB | ITLABEL ;
    interp->imc_info->asm_state = yield ? AsmInYield : AsmInReturn;
}

static void
set_lexical(PARROT_INTERP, ARGMOD(SymReg *r), ARGIN(const char *name))
{
    SymReg * const n = mk_const(interp, name, 'S');

    r->usage |= U_LEXICAL;

    if (n == r->reg)
        IMCC_fataly(interp, EXCEPTION_SYNTAX_ERROR,
            "register %s already declared as lexical %s", r->name, n->name);

    /* chain all names in r->reg */
    n->reg = r->reg;
    r->reg = n;
    r->use_count++;
}

static void
add_pcc_named_arg(PARROT_INTERP, ARGMOD(SymReg *cur_call), ARGIN(const char *name),
        ARGIN(SymReg *value))
{
    SymReg * const r = mk_const(interp, name, 'S');

    r->type  |= VT_NAMED;

    add_pcc_arg(cur_call, r);
    add_pcc_arg(cur_call, value);
}

static void
add_pcc_named_result(PARROT_INTERP, ARGMOD(SymReg *cur_call), ARGIN(const char *name),
        ARGIN(SymReg *value))
{
    SymReg * const r = mk_const(interp, name, 'S');
    r->type         |= VT_NAMED;

    add_pcc_result(cur_call, r);
    add_pcc_result(cur_call, value);
}

static void
add_pcc_named_param(PARROT_INTERP, ARGMOD(SymReg *cur_call), ARGIN(const char *name),
        ARGIN(SymReg *value))
{
    SymReg * const r = mk_const(interp, name, 'S');
    r->type         |= VT_NAMED;

    add_pcc_arg(cur_call, r);
    add_pcc_arg(cur_call, value);
}

static void
add_pcc_named_return(PARROT_INTERP, ARGMOD(SymReg *cur_call), ARGIN(const char *name),
        ARGIN(SymReg *value))
{
    SymReg * const r = mk_const(interp, name, 'S');
    r->type         |= VT_NAMED;

    add_pcc_result(cur_call, r);
    add_pcc_result(cur_call, value);
}

/* XXX Can name be consted? */
static void
adv_named_set(PARROT_INTERP, ARGIN(char *name))
{
    if (IMCC_INFO(interp)->adv_named_id) {
        IMCC_fataly(interp, EXCEPTION_SYNTAX_ERROR,
                    "Named parameter with more than one name.\n");
    }
    IMCC_INFO(interp)->adv_named_id = name;
}

static void
do_loadlib(PARROT_INTERP, ARGIN(const char *lib))
{
    STRING * const s = string_unescape_cstring(interp, lib + 1, '"', NULL);
    PMC    *ignored  = Parrot_load_lib(interp, s, NULL);
    UNUSED(ignored);
    Parrot_register_HLL_lib(interp, s);
}

/* HEADERIZER STOP */



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 615 "compilers/imcc/imcc.y"
{
    IdList * idlist;
    int t;
    char * s;
    SymReg * sr;
    Instruction *i;
}
/* Line 187 of yacc.c.  */
#line 958 "compilers/imcc/imcparser.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 971 "compilers/imcc/imcparser.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   753

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  137
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  123
/* YYNRULES -- Number of rules.  */
#define YYNRULES  343
/* YYNRULES -- Number of states.  */
#define YYNSTATES  554

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   375

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       4,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   127,     2,     2,     2,   133,   134,     2,
     125,   126,   131,   130,     2,   129,     2,   132,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   136,
       2,   122,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   123,     2,   124,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   135,     2,   128,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    18,
      21,    23,    25,    29,    32,    36,    39,    44,    49,    51,
      53,    54,    61,    62,    69,    71,    73,    75,    78,    82,
      85,    87,    89,    91,    93,    95,    96,   100,   101,   106,
     109,   114,   115,   117,   118,   123,   124,   126,   130,   134,
     137,   138,   139,   140,   141,   152,   153,   155,   159,   160,
     164,   168,   174,   179,   184,   189,   191,   196,   201,   206,
     207,   211,   213,   215,   217,   219,   221,   223,   225,   229,
     230,   232,   233,   243,   244,   247,   248,   252,   253,   255,
     257,   260,   262,   264,   266,   268,   270,   272,   274,   276,
     278,   280,   282,   284,   286,   292,   296,   300,   304,   308,
     314,   320,   321,   325,   328,   329,   333,   337,   338,   343,
     344,   347,   349,   351,   353,   355,   360,   362,   363,   369,
     371,   372,   378,   379,   382,   386,   390,   391,   397,   399,
     401,   402,   404,   408,   412,   418,   420,   423,   424,   427,
     430,   432,   434,   435,   437,   440,   442,   444,   448,   451,
     453,   457,   460,   461,   463,   465,   467,   470,   473,   474,
     479,   484,   485,   492,   494,   495,   502,   505,   508,   511,
     514,   516,   518,   520,   522,   523,   525,   527,   529,   531,
     533,   537,   542,   548,   555,   562,   569,   577,   582,   587,
     592,   599,   606,   614,   619,   624,   629,   634,   641,   649,
     653,   654,   664,   666,   668,   670,   674,   676,   678,   680,
     682,   684,   686,   688,   690,   692,   694,   696,   698,   700,
     702,   704,   706,   708,   710,   712,   714,   716,   718,   720,
     722,   724,   726,   727,   733,   737,   739,   741,   743,   745,
     747,   749,   751,   753,   755,   757,   759,   761,   763,   768,
     770,   772,   774,   776,   780,   784,   788,   789,   795,   796,
     800,   802,   808,   812,   815,   816,   819,   821,   823,   828,
     831,   835,   841,   843,   847,   848,   850,   852,   859,   865,
     870,   875,   882,   888,   890,   892,   894,   896,   898,   900,
     902,   904,   906,   908,   909,   911,   915,   917,   919,   924,
     928,   930,   932,   934,   936,   938,   940,   942,   944,   946,
     948,   950,   951,   954,   955,   958,   960,   964,   965,   970,
     972,   976,   979,   982,   984,   986,   988,   990,   992,   994,
     996,   998,  1000,  1002
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     138,     0,    -1,   139,    -1,   140,    -1,   139,   140,    -1,
     159,    -1,   145,    -1,   161,    -1,   156,    -1,   110,     4,
      -1,   141,    -1,     4,    -1,     6,   142,     4,    -1,   143,
       4,    -1,    97,   112,     4,    -1,     7,   113,    -1,     8,
     112,    72,   112,    -1,     9,   112,   144,   112,    -1,    72,
      -1,   122,    -1,    -1,    30,   146,   216,   108,   122,   258,
      -1,    -1,    30,   148,   113,   248,   122,   149,    -1,   112,
      -1,   115,    -1,   151,    -1,   150,   151,    -1,   205,   152,
       4,    -1,   110,     4,    -1,   119,    -1,   118,    -1,   159,
      -1,   147,    -1,   141,    -1,    -1,   153,   116,   155,    -1,
      -1,    78,   154,   181,   101,    -1,    14,   249,    -1,    29,
     112,    72,   109,    -1,    -1,   242,    -1,    -1,   102,   157,
     158,   103,    -1,    -1,   150,    -1,    23,   160,     4,    -1,
     123,   250,   124,    -1,   123,   124,    -1,    -1,    -1,    -1,
      -1,    26,   162,   245,   163,   181,     4,   164,   165,   176,
      73,    -1,    -1,     4,    -1,   165,   166,     4,    -1,    -1,
       5,   167,   168,    -1,   216,   108,   190,    -1,   216,   112,
      20,   108,   190,    -1,    95,   125,   174,   126,    -1,    93,
     125,   112,   126,    -1,    93,   125,   108,   126,    -1,    96,
      -1,    96,   125,   112,   126,    -1,    98,   125,   112,   126,
      -1,    99,   125,   112,   126,    -1,    -1,   174,    72,   175,
      -1,   175,    -1,    50,    -1,    51,    -1,    53,    -1,    52,
      -1,   108,    -1,   112,    -1,   123,   250,   124,    -1,    -1,
     202,    -1,    -1,    75,     4,   178,   185,   180,   184,   179,
     187,    76,    -1,    -1,   207,     4,    -1,    -1,    85,   249,
       4,    -1,    -1,   182,    -1,   183,    -1,   182,   183,    -1,
      87,    -1,    88,    -1,    86,    -1,    89,    -1,    90,    -1,
      92,    -1,    91,    -1,    94,    -1,   169,    -1,   170,    -1,
     171,    -1,   172,    -1,   173,    -1,    77,   249,    72,   249,
       4,    -1,    77,   249,     4,    -1,    83,   249,     4,    -1,
      84,   241,     4,    -1,    84,   112,     4,    -1,    84,   241,
      72,   249,     4,    -1,    84,   112,    72,   249,     4,    -1,
      -1,   185,   186,     4,    -1,    11,   231,    -1,    -1,   187,
     188,     4,    -1,    64,   241,   190,    -1,    -1,    28,   189,
     216,   210,    -1,    -1,   190,   191,    -1,    16,    -1,    17,
      -1,    18,    -1,    19,    -1,    19,   125,   112,   126,    -1,
     100,    -1,    -1,    79,     4,   193,   196,    80,    -1,   198,
      -1,    -1,    81,     4,   195,   196,    82,    -1,    -1,   196,
       4,    -1,   196,   197,     4,    -1,    65,   249,   232,    -1,
      -1,   200,   125,   199,   201,   126,    -1,    65,    -1,    66,
      -1,    -1,   231,    -1,   112,    20,   249,    -1,   201,    72,
     231,    -1,   201,    72,   112,    20,   249,    -1,   204,    -1,
     202,   204,    -1,    -1,   203,   208,    -1,   110,     4,    -1,
     119,    -1,   118,    -1,    -1,   206,    -1,   206,   207,    -1,
     207,    -1,   101,    -1,   205,   212,     4,    -1,     1,     4,
      -1,   210,    -1,   209,    72,   210,    -1,   108,   211,    -1,
      -1,   100,    -1,   218,    -1,   236,    -1,    23,   108,    -1,
      24,   108,    -1,    -1,    28,   213,   216,   209,    -1,    29,
     112,    72,   241,    -1,    -1,    30,   214,   216,   108,   122,
     258,    -1,   147,    -1,    -1,    33,   215,   216,   108,   122,
     258,    -1,    65,   228,    -1,    10,   247,    -1,   116,   242,
      -1,    14,   249,    -1,   228,    -1,   177,    -1,   192,    -1,
     194,    -1,    -1,    50,    -1,    51,    -1,    52,    -1,    53,
      -1,   108,    -1,   241,   122,   249,    -1,   241,   122,   220,
     249,    -1,   241,   122,   249,   221,   249,    -1,   241,   122,
     249,   123,   250,   124,    -1,   241,   123,   250,   124,   122,
     249,    -1,   241,   122,    21,   217,    72,   249,    -1,   241,
     122,    21,   217,   123,   250,   124,    -1,   241,   122,    21,
     217,    -1,   241,   122,    21,   249,    -1,   241,   122,    21,
     160,    -1,   241,   122,    21,   160,    72,   249,    -1,   241,
     122,    21,   249,    72,   249,    -1,   241,   122,    21,   249,
     123,   250,   124,    -1,   241,   122,    63,   108,    -1,   241,
     122,    62,   259,    -1,    62,   259,   122,   249,    -1,    21,
     241,    72,   249,    -1,    21,   241,    72,   249,    72,   249,
      -1,    21,   241,    72,   249,   123,   250,   124,    -1,   241,
     122,   228,    -1,    -1,   125,   219,   235,   126,   122,   227,
     125,   230,   126,    -1,   222,    -1,   224,    -1,   226,    -1,
     241,   122,    14,    -1,   127,    -1,   128,    -1,   129,    -1,
     129,    -1,   130,    -1,   131,    -1,   132,    -1,   133,    -1,
      42,    -1,    68,    -1,   121,    -1,    55,    -1,    56,    -1,
      57,    -1,    58,    -1,    59,    -1,    60,    -1,    48,    -1,
      49,    -1,    69,    -1,    70,    -1,    71,    -1,    54,    -1,
     134,    -1,   135,    -1,   128,    -1,    -1,    67,   223,   125,
     235,   126,    -1,   241,   225,   249,    -1,    34,    -1,    35,
      -1,    36,    -1,    37,    -1,    44,    -1,    43,    -1,    38,
      -1,    39,    -1,    40,    -1,    41,    -1,    45,    -1,    46,
      -1,    47,    -1,   241,   122,   116,   155,    -1,   108,    -1,
     112,    -1,   115,    -1,   241,    -1,   241,   120,   246,    -1,
     241,   120,   112,    -1,   241,   120,   241,    -1,    -1,   227,
     229,   125,   230,   126,    -1,    -1,   230,    72,   231,    -1,
     231,    -1,   230,    72,   112,    20,   249,    -1,   112,    20,
     249,    -1,   249,   232,    -1,    -1,   232,   233,    -1,    15,
      -1,    19,    -1,    19,   125,   112,   126,    -1,   241,   190,
      -1,   235,    72,   234,    -1,   235,    72,   112,    20,   241,
      -1,   234,    -1,   112,    20,   241,    -1,    -1,   238,    -1,
     237,    -1,    13,   249,   240,   249,    10,   247,    -1,    13,
      14,   249,    10,   247,    -1,    13,   249,   239,   247,    -1,
      12,   249,   239,   247,    -1,    12,   249,   240,   249,    10,
     247,    -1,    12,    14,   249,    10,   247,    -1,    72,    -1,
      10,    -1,    55,    -1,    56,    -1,    57,    -1,    58,    -1,
      59,    -1,    60,    -1,   117,    -1,   257,    -1,    -1,   243,
      -1,   243,    72,   244,    -1,   244,    -1,   248,    -1,   241,
     123,   250,   124,    -1,   123,   252,   124,    -1,   246,    -1,
     112,    -1,   115,    -1,   108,    -1,   116,    -1,   108,    -1,
     116,    -1,   247,    -1,   249,    -1,   241,    -1,   258,    -1,
      -1,   251,   254,    -1,    -1,   253,   254,    -1,   256,    -1,
     254,   136,   256,    -1,    -1,   254,    72,   255,   256,    -1,
     249,    -1,   249,    74,   249,    -1,    74,   249,    -1,   249,
      74,    -1,   104,    -1,   105,    -1,   106,    -1,   107,    -1,
     109,    -1,   113,    -1,   114,    -1,   112,    -1,   115,    -1,
     106,    -1,   112,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   707,   707,   711,   712,   716,   717,   718,   724,   730,
     731,   732,   736,   737,   738,   747,   757,   775,   795,   796,
     800,   800,   809,   809,   816,   817,   821,   822,   826,   827,
     828,   829,   830,   831,   832,   835,   835,   844,   843,   855,
     859,   867,   871,   875,   875,   887,   889,   893,   908,   916,
     917,   922,   926,   929,   921,   935,   936,   937,   950,   950,
     954,   965,   980,   984,   990,   999,  1005,  1014,  1022,  1032,
    1035,  1040,  1048,  1049,  1050,  1051,  1052,  1063,  1074,  1077,
    1079,  1084,  1083,  1116,  1117,  1121,  1122,  1126,  1127,  1131,
    1132,  1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,
    1145,  1146,  1147,  1148,  1152,  1157,  1161,  1166,  1170,  1174,
    1179,  1188,  1189,  1193,  1198,  1199,  1207,  1208,  1208,  1223,
    1224,  1228,  1229,  1230,  1231,  1232,  1233,  1239,  1238,  1247,
    1255,  1255,  1261,  1262,  1267,  1275,  1280,  1279,  1292,  1293,
    1297,  1298,  1308,  1312,  1322,  1330,  1331,  1343,  1347,  1349,
    1350,  1351,  1355,  1356,  1360,  1361,  1365,  1374,  1375,  1386,
    1393,  1402,  1412,  1413,  1418,  1419,  1420,  1421,  1422,  1422,
    1438,  1442,  1442,  1449,  1450,  1450,  1456,  1462,  1463,  1475,
    1476,  1477,  1478,  1479,  1480,  1484,  1485,  1486,  1487,  1491,
    1504,  1506,  1508,  1510,  1512,  1514,  1516,  1518,  1520,  1522,
    1524,  1526,  1528,  1530,  1533,  1535,  1539,  1541,  1543,  1546,
    1553,  1552,  1561,  1562,  1563,  1564,  1572,  1573,  1574,  1578,
    1579,  1580,  1581,  1582,  1583,  1584,  1585,  1586,  1587,  1588,
    1589,  1590,  1591,  1592,  1593,  1594,  1595,  1596,  1597,  1598,
    1599,  1600,  1606,  1605,  1617,  1624,  1625,  1626,  1627,  1628,
    1629,  1630,  1631,  1632,  1633,  1634,  1635,  1636,  1641,  1652,
    1653,  1654,  1655,  1661,  1662,  1667,  1673,  1672,  1681,  1682,
    1692,  1702,  1708,  1717,  1721,  1722,  1726,  1727,  1730,  1734,
    1738,  1748,  1753,  1763,  1768,  1772,  1773,  1777,  1781,  1785,
    1792,  1796,  1800,  1807,  1808,  1812,  1813,  1814,  1815,  1816,
    1817,  1821,  1822,  1826,  1827,  1831,  1832,  1836,  1837,  1844,
    1851,  1852,  1853,  1857,  1858,  1862,  1863,  1867,  1868,  1872,
    1873,  1877,  1877,  1890,  1890,  1903,  1904,  1909,  1909,  1918,
    1924,  1931,  1932,  1936,  1937,  1938,  1939,  1940,  1944,  1945,
    1946,  1947,  1951,  1952
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LOW_PREC", "'\\n'", "PARAM", "PRAGMA",
  "N_OPERATORS", "HLL", "HLL_MAP", "GOTO", "ARG", "IF", "UNLESS", "PNULL",
  "ADV_FLAT", "ADV_SLURPY", "ADV_OPTIONAL", "ADV_OPT_FLAG", "ADV_NAMED",
  "ADV_ARROW", "NEW", "ADV_INVOCANT", "NAMESPACE", "ENDNAMESPACE",
  "DOT_METHOD", "SUB", "SYM", "LOCAL", "LEXICAL", "CONST", "INC", "DEC",
  "GLOBAL_CONST", "PLUS_ASSIGN", "MINUS_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "CONCAT_ASSIGN", "BAND_ASSIGN", "BOR_ASSIGN",
  "BXOR_ASSIGN", "FDIV", "FDIV_ASSIGN", "MOD_ASSIGN", "SHR_ASSIGN",
  "SHL_ASSIGN", "SHR_U_ASSIGN", "SHIFT_LEFT", "SHIFT_RIGHT", "INTV",
  "FLOATV", "STRINGV", "PMCV", "LOG_XOR", "RELOP_EQ", "RELOP_NE",
  "RELOP_GT", "RELOP_GTE", "RELOP_LT", "RELOP_LTE", "GLOBAL", "GLOBALOP",
  "ADDR", "RESULT", "RETURN", "YIELDT", "GET_RESULTS", "POW",
  "SHIFT_RIGHT_U", "LOG_AND", "LOG_OR", "COMMA", "ESUB", "DOTDOT",
  "PCC_BEGIN", "PCC_END", "PCC_CALL", "PCC_SUB", "PCC_BEGIN_RETURN",
  "PCC_END_RETURN", "PCC_BEGIN_YIELD", "PCC_END_YIELD", "NCI_CALL",
  "METH_CALL", "INVOCANT", "MAIN", "LOAD", "INIT", "IMMEDIATE", "POSTCOMP",
  "METHOD", "ANON", "OUTER", "NEED_LEX", "MULTI", "VTABLE_METHOD",
  "LOADLIB", "SUB_INSTANCE_OF", "SUB_LEXID", "UNIQUE_REG", "LABEL", "EMIT",
  "EOM", "IREG", "NREG", "SREG", "PREG", "IDENTIFIER", "REG", "MACRO",
  "ENDM", "STRINGC", "INTC", "FLOATC", "USTRINGC", "PARROT_OP", "VAR",
  "LINECOMMENT", "FILECOMMENT", "DOT", "CONCAT", "'='", "'['", "']'",
  "'('", "')'", "'!'", "'~'", "'-'", "'+'", "'*'", "'/'", "'%'", "'&'",
  "'|'", "';'", "$accept", "program", "compilation_units",
  "compilation_unit", "pragma", "pragma_1", "hll_def",
  "comma_will_be_equals", "constdef", "@1", "pmc_const", "@2",
  "any_string", "pasmcode", "pasmline", "pasm_inst", "@3", "@4",
  "pasm_args", "emit", "@5", "opt_pasmcode", "class_namespace", "maybe_ns",
  "sub", "@6", "@7", "@8", "sub_params", "sub_param", "@9",
  "sub_param_type_def", "multi", "outer", "vtable", "instanceof", "lexid",
  "multi_types", "multi_type", "sub_body", "pcc_sub_call", "@10",
  "opt_label", "opt_invocant", "sub_proto", "sub_proto_list", "proto",
  "pcc_call", "pcc_args", "pcc_arg", "pcc_results", "pcc_result", "@11",
  "paramtype_list", "paramtype", "pcc_ret", "@12", "pcc_yield", "@13",
  "pcc_returns", "pcc_return", "pcc_return_many", "@14", "return_or_yield",
  "var_returns", "statements", "helper_clear_state", "statement", "labels",
  "_labels", "label", "instruction", "id_list", "id_list_id",
  "opt_unique_reg", "labeled_inst", "@15", "@16", "@17", "type",
  "classname", "assignment", "@18", "un_op", "bin_op", "get_results",
  "@19", "op_assign", "assign_op", "func_assign", "the_sub", "sub_call",
  "@20", "arglist", "arg", "argtype_list", "argtype", "result",
  "targetlist", "conditional_statement", "unless_statement",
  "if_statement", "comma_or_goto", "relop", "target", "vars", "_vars",
  "_var_or_i", "sub_label_op_c", "sub_label_op", "label_op", "var_or_i",
  "var", "keylist", "@21", "keylist_force", "@22", "_keylist", "@23",
  "key", "reg", "const", "string", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,    10,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,    61,    91,    93,    40,    41,    33,   126,    45,
      43,    42,    47,    37,    38,   124,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   137,   138,   139,   139,   140,   140,   140,   140,   140,
     140,   140,   141,   141,   141,   142,   143,   143,   144,   144,
     146,   145,   148,   147,   149,   149,   150,   150,   151,   151,
     151,   151,   151,   151,   151,   153,   152,   154,   152,   152,
     152,   152,   155,   157,   156,   158,   158,   159,   160,   160,
     160,   162,   163,   164,   161,   165,   165,   165,   167,   166,
     168,   168,   169,   170,   170,   171,   171,   172,   173,   174,
     174,   174,   175,   175,   175,   175,   175,   175,   175,   176,
     176,   178,   177,   179,   179,   180,   180,   181,   181,   182,
     182,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   184,   184,   184,   184,   184,   184,
     184,   185,   185,   186,   187,   187,   188,   189,   188,   190,
     190,   191,   191,   191,   191,   191,   191,   193,   192,   192,
     195,   194,   196,   196,   196,   197,   199,   198,   200,   200,
     201,   201,   201,   201,   201,   202,   202,   203,   204,   204,
     204,   204,   205,   205,   206,   206,   207,   208,   208,   209,
     209,   210,   211,   211,   212,   212,   212,   212,   213,   212,
     212,   214,   212,   212,   215,   212,   212,   212,   212,   212,
     212,   212,   212,   212,   212,   216,   216,   216,   216,   217,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     219,   218,   218,   218,   218,   218,   220,   220,   220,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   223,   222,   224,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   226,   227,
     227,   227,   227,   227,   227,   227,   229,   228,   230,   230,
     230,   230,   230,   231,   232,   232,   233,   233,   233,   234,
     235,   235,   235,   235,   235,   236,   236,   237,   237,   237,
     238,   238,   238,   239,   239,   240,   240,   240,   240,   240,
     240,   241,   241,   242,   242,   243,   243,   244,   244,   244,
     245,   245,   245,   246,   246,   247,   247,   248,   248,   249,
     249,   251,   250,   253,   252,   254,   254,   255,   254,   256,
     256,   256,   256,   257,   257,   257,   257,   257,   258,   258,
     258,   258,   259,   259
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     2,
       1,     1,     3,     2,     3,     2,     4,     4,     1,     1,
       0,     6,     0,     6,     1,     1,     1,     2,     3,     2,
       1,     1,     1,     1,     1,     0,     3,     0,     4,     2,
       4,     0,     1,     0,     4,     0,     1,     3,     3,     2,
       0,     0,     0,     0,    10,     0,     1,     3,     0,     3,
       3,     5,     4,     4,     4,     1,     4,     4,     4,     0,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     0,
       1,     0,     9,     0,     2,     0,     3,     0,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     3,     3,     3,     3,     5,
       5,     0,     3,     2,     0,     3,     3,     0,     4,     0,
       2,     1,     1,     1,     1,     4,     1,     0,     5,     1,
       0,     5,     0,     2,     3,     3,     0,     5,     1,     1,
       0,     1,     3,     3,     5,     1,     2,     0,     2,     2,
       1,     1,     0,     1,     2,     1,     1,     3,     2,     1,
       3,     2,     0,     1,     1,     1,     2,     2,     0,     4,
       4,     0,     6,     1,     0,     6,     2,     2,     2,     2,
       1,     1,     1,     1,     0,     1,     1,     1,     1,     1,
       3,     4,     5,     6,     6,     6,     7,     4,     4,     4,
       6,     6,     7,     4,     4,     4,     4,     6,     7,     3,
       0,     9,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       1,     1,     1,     3,     3,     3,     0,     5,     0,     3,
       1,     5,     3,     2,     0,     2,     1,     1,     4,     2,
       3,     5,     1,     3,     0,     1,     1,     6,     5,     4,
       4,     6,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     3,     1,     1,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     2,     0,     2,     1,     3,     0,     4,     1,
       3,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,    11,     0,     0,     0,    50,    51,    20,     0,    43,
       0,     0,     2,     3,    10,     0,     6,     8,     5,     7,
       0,     0,     0,     0,   321,     0,     0,     0,     0,   152,
       9,     1,     4,    13,    15,    12,     0,    18,    19,     0,
      49,     0,     0,    47,   313,   311,   312,   314,    52,   310,
     185,   186,   187,   188,     0,    14,    22,   156,     0,    31,
      30,    34,    33,   152,    26,     0,    32,    35,   153,   155,
      16,    17,    48,     0,   333,   334,   335,   336,   337,   340,
     338,   339,   341,   301,   319,   329,   322,   325,   302,   320,
      87,     0,     0,    29,    27,    44,     0,     0,    37,     0,
       0,   154,   331,   332,   327,     0,    93,    91,    92,    94,
      95,    97,    96,     0,    98,     0,    65,     0,     0,    99,
     100,   101,   102,   103,     0,    88,    89,     0,     0,    39,
       0,    87,    28,   303,   330,     0,   326,     0,    69,     0,
       0,     0,    53,    90,    21,   315,   316,   317,     0,   318,
       0,     0,   323,    36,   319,    42,   304,   306,   307,   328,
       0,     0,    72,    73,    75,    74,    76,    77,   321,     0,
      71,     0,     0,     0,    55,     0,    40,    38,     0,     0,
     321,     0,    64,    63,     0,     0,    62,    66,    67,    68,
      56,   147,    24,    25,    23,   309,   324,     0,   305,    78,
      70,    58,     0,   151,   150,     0,     0,   147,     0,   145,
     308,     0,   149,    57,    54,   146,     0,   184,   148,    59,
       0,   158,     0,     0,     0,     0,     0,     0,     0,   168,
       0,   171,   174,     0,   138,   139,   242,     0,     0,     0,
     259,   260,   261,   303,   210,   173,   181,   182,   183,   129,
       0,     0,   164,   212,   213,   214,   266,   180,   165,   286,
     285,   262,   119,     0,   177,     0,     0,     0,     0,   179,
       0,   166,   167,     0,     0,     0,     0,   342,   343,     0,
     176,   262,     0,    81,   127,   130,   178,   284,   136,   157,
       0,   245,   246,   247,   248,   251,   252,   253,   254,   250,
     249,   255,   256,   257,     0,     0,   321,     0,    60,     0,
       0,   294,   295,   296,   297,   298,   299,   300,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     284,   111,   132,   132,     0,   282,     0,   119,   140,   268,
     264,   265,   263,   215,    50,     0,     0,   340,   341,   303,
     216,   217,   218,     0,   209,   319,   190,     0,   244,   121,
     122,   123,   124,   126,   120,   119,     0,   290,     0,     0,
     289,     0,   206,   162,   169,   159,   170,     0,     0,   205,
       0,    85,     0,     0,     0,     0,     0,   279,   340,     0,
     141,   274,   340,     0,   270,   189,   199,   197,   198,   204,
     203,   258,   191,   224,   233,   234,   238,   227,   228,   229,
     230,   231,   232,   225,   235,   236,   237,   226,   321,   241,
     219,   220,   221,   222,   223,   239,   240,     0,     0,     0,
      61,   292,     0,   288,     0,     0,   321,   163,   161,     0,
       0,     0,   243,     0,     0,     0,     0,   133,     0,   128,
       0,   131,   283,     0,   280,     0,     0,     0,   137,   273,
       0,     0,   267,     0,     0,   321,     0,   321,     0,   192,
       0,     0,   291,   287,   207,     0,   160,   172,   175,   113,
       0,     0,     0,     0,    83,   112,   274,   134,     0,     0,
     142,   340,   143,   276,   277,   275,   272,   340,   269,   200,
     195,     0,   201,     0,   193,   194,   125,   208,    86,     0,
       0,     0,     0,   114,     0,   135,   281,   268,     0,     0,
       0,   196,   202,   105,     0,   106,   108,     0,   107,     0,
       0,    84,     0,   144,     0,   271,     0,     0,     0,   117,
       0,    82,     0,   211,   278,   104,   110,   109,     0,   119,
     115,     0,   116,   118
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    21,    15,    39,    16,    27,
      62,    92,   194,    63,    64,    99,   100,   131,   153,    17,
      29,    65,    18,    25,    19,    26,    90,   174,   191,   205,
     211,   219,   119,   120,   121,   122,   123,   169,   170,   206,
     246,   331,   513,   445,   124,   125,   126,   484,   381,   446,
     530,   542,   548,   308,   364,   247,   332,   248,   333,   382,
     450,   249,   338,   250,   389,   207,   208,   209,    67,    68,
      69,   218,   374,   375,   438,   251,   273,   275,   276,    54,
     397,   252,   287,   353,   427,   253,   282,   254,   307,   255,
     256,   257,   290,   393,   394,   459,   495,   335,   336,   258,
     259,   260,   319,   320,    84,   155,   156,   157,    48,    49,
     147,   158,   391,    41,    42,   178,   179,    86,   135,    87,
      88,    89,   279
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -427
static const yytype_int16 yypact[] =
{
     112,  -427,    36,   -83,   -55,   -61,  -427,  -427,   -31,  -427,
     104,   129,   112,  -427,  -427,   127,  -427,  -427,  -427,  -427,
      30,   144,    78,   -33,    32,   150,    47,   176,   157,    14,
    -427,  -427,  -427,  -427,  -427,  -427,    53,  -427,  -427,    55,
    -427,    42,   484,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,    62,  -427,  -427,  -427,   167,  -427,
    -427,  -427,  -427,    50,  -427,    77,  -427,    21,    87,  -427,
    -427,  -427,  -427,   566,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,   116,   -46,  -427,  -427,  -427,
     556,    69,    85,  -427,  -427,  -427,   566,    90,  -427,   195,
      91,  -427,  -427,   566,  -427,   484,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,    88,  -427,    93,   106,   107,   110,  -427,
    -427,  -427,  -427,  -427,   206,   556,  -427,   132,   552,  -427,
     140,   556,  -427,   498,  -427,   484,  -427,   -34,   126,   124,
     125,   128,  -427,  -427,  -427,  -427,  -427,  -427,   102,  -427,
     139,   159,  -427,  -427,   138,  -427,   179,  -427,  -427,  -427,
     146,   149,  -427,  -427,  -427,  -427,  -427,  -427,  -427,   -25,
    -427,   151,   153,   158,   260,   -70,  -427,  -427,   152,   484,
    -427,   498,  -427,  -427,   161,   126,  -427,  -427,  -427,  -427,
    -427,     4,  -427,  -427,  -427,  -427,   -46,   162,  -427,  -427,
    -427,  -427,   284,  -427,  -427,   285,   217,    54,   229,  -427,
    -427,   176,  -427,  -427,  -427,  -427,   288,   424,  -427,  -427,
      33,  -427,   -68,    80,   355,   566,   273,   185,   189,  -427,
     186,   187,  -427,    22,   292,  -427,  -427,   295,   297,   302,
    -427,  -427,  -427,   498,  -427,  -427,  -427,  -427,  -427,  -427,
     184,   308,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,   516,  -427,   293,  -427,   566,   211,   566,   211,  -427,
     242,  -427,  -427,   176,   244,   176,   176,  -427,  -427,   193,
    -427,   199,   198,  -427,  -427,  -427,  -427,    99,  -427,  -427,
     201,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,   243,   259,  -427,   566,    -2,   212,
     314,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,   -68,
     566,   317,   -68,   566,   566,   220,   273,   221,   223,   566,
      99,  -427,  -427,  -427,   312,  -427,   -23,  -427,   580,   594,
    -427,  -427,  -427,  -427,   518,    22,   232,   218,   231,   498,
    -427,  -427,  -427,   566,  -427,   -79,   452,   233,  -427,  -427,
    -427,  -427,   236,  -427,  -427,  -427,   -68,  -427,   332,   -68,
    -427,   352,   -53,   270,   309,  -427,  -427,   261,   262,  -427,
     -20,     0,    17,     6,   273,   460,   267,    -2,   371,   -19,
    -427,  -427,   372,   -17,  -427,  -427,   322,   -44,   -39,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,   566,   281,   283,
      -2,  -427,   -68,  -427,   -68,   566,  -427,  -427,  -427,   220,
     132,   132,  -427,   566,   566,    -8,   401,  -427,   566,  -427,
     404,  -427,  -427,   391,  -427,   292,   566,   608,  -427,   121,
     566,   622,  -427,   566,   566,  -427,   566,  -427,   289,  -427,
     566,   286,  -427,  -427,  -427,   291,  -427,  -427,  -427,  -427,
     412,   566,   566,   636,    87,  -427,  -427,  -427,   273,   294,
    -427,   400,  -427,  -427,   298,  -427,  -427,   405,  -427,  -427,
    -427,   303,  -427,   305,  -427,  -427,  -427,  -427,  -427,    20,
     422,    23,    28,  -427,   426,   121,  -427,   594,   566,   319,
     566,  -427,  -427,  -427,   566,  -427,  -427,   566,  -427,   566,
      82,  -427,    -7,  -427,   306,  -427,   429,   431,   437,  -427,
     273,  -427,   438,  -427,  -427,  -427,  -427,  -427,   176,  -427,
    -427,   220,    -2,  -427
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -427,  -427,  -427,   432,     5,  -427,  -427,  -427,  -427,  -427,
     226,  -427,  -427,  -427,   383,  -427,  -427,  -427,   100,  -427,
    -427,  -427,     9,   111,  -427,  -427,  -427,  -427,  -427,  -427,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,   265,  -427,
    -427,  -427,  -427,  -427,   320,  -427,   331,  -427,  -427,  -427,
    -427,  -427,  -427,  -329,  -427,  -427,  -427,  -427,  -427,   130,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,   251,   257,  -427,
     -67,  -427,  -427,  -426,  -427,  -427,  -427,  -427,  -427,  -209,
    -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,  -427,
      11,  -222,  -427,   -43,  -331,   -15,  -427,    92,   143,  -427,
    -427,  -427,   207,   213,  -130,   237,  -427,   307,  -427,   175,
    -217,   356,   -42,  -162,  -427,  -427,  -427,   304,  -427,   -75,
    -427,  -123,   147
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -263
static const yytype_int16 yytable[] =
{
      85,   101,   220,   154,   144,   264,   184,   390,   387,   201,
     447,   443,   280,   476,   359,   360,   361,   362,   197,   435,
       2,   447,     3,     4,   523,   -41,   104,   526,   464,    22,
     136,   102,   528,   466,    61,    96,   430,     5,    66,    37,
     145,   304,   192,    20,    56,   193,  -262,   185,   146,   385,
      97,   154,   385,   457,   129,   461,     2,    23,     3,     4,
     159,   134,    24,    85,   325,   461,   327,   328,    61,   481,
     436,   448,    66,     5,   160,   482,   483,   -79,   161,   465,
      56,    28,   448,   354,   467,   444,   149,   261,   451,    38,
     105,   149,   524,    85,   265,   527,   270,   449,   363,    98,
     529,   186,   367,   386,   281,   370,   442,   458,    30,   462,
     539,     8,   479,   154,   202,    57,     1,   -45,     2,   543,
       3,     4,   203,   204,    58,   553,   492,   -80,   277,    31,
     498,    33,    59,    60,   278,     5,   493,    85,     6,   149,
     494,   262,     7,    34,   357,   263,   540,     8,    35,   431,
      36,    57,   433,   -46,    43,    44,    40,   337,   541,    45,
      58,    55,    46,    47,   202,    70,    72,    71,    59,    60,
      91,    93,   203,   204,   341,   355,   162,   163,   164,   165,
      95,   266,   268,   269,    74,    75,    76,    77,    57,    78,
     103,   127,    79,    80,    81,    82,   376,    83,   128,   132,
     337,   149,   130,    74,    75,    76,    77,   133,    78,     8,
     142,   334,   150,   137,     9,   472,    83,   473,   138,   154,
     552,   311,    10,   310,   175,   321,    50,    51,    52,    53,
     216,   139,   140,  -152,   166,   141,   171,   172,   167,  -152,
     173,  -152,  -152,  -152,    79,    80,    81,    82,   176,   168,
    -152,   181,  -152,  -152,   452,   337,   468,  -152,  -152,  -152,
     177,   180,  -152,   356,   190,   358,   312,   313,   314,   315,
     316,   317,   182,   343,   475,   183,   195,   187,   368,   188,
     344,   371,   372,   318,   189,   199,   210,   379,   212,   213,
     214,  -152,   221,   271,  -152,  -152,  -152,   272,   274,   283,
     -22,   284,   398,   501,  -152,   503,   285,   149,  -152,   288,
    -152,   402,   289,   309,   324,   329,   326,   477,   478,   304,
     365,   345,   346,   330,   366,   281,   339,   369,   373,   377,
      57,   378,   384,  -152,  -152,  -152,  -152,  -152,  -152,   551,
     400,  -152,   432,  -260,  -152,  -152,  -152,    74,    75,    76,
      77,    44,    78,   512,  -152,   340,  -261,   428,   516,    47,
      83,   429,   434,    74,    75,    76,    77,   240,    78,   267,
     437,   347,    80,    81,   348,   349,    83,    74,    75,    76,
      77,   439,    78,   440,   441,   469,   350,   351,   352,   455,
      83,   456,   460,   474,   463,   471,    74,    75,    76,    77,
     240,    78,   480,   470,   241,   485,   486,   242,   487,    83,
     549,   488,   506,   504,   490,   507,   508,   514,   496,   517,
     518,   499,   500,   519,   502,   520,   525,   521,   505,   522,
     531,   534,   544,   545,   222,   546,   223,   224,   225,   509,
     510,   547,   550,   245,    32,   226,    94,   227,   228,   401,
     200,   151,   229,   230,   231,   396,   143,   232,   215,    74,
      75,    76,    77,   383,    78,   217,   489,    79,    80,    81,
      82,   515,    83,   380,   532,   322,   533,   454,   535,   342,
     286,   323,   536,   196,   148,   537,   233,   538,   198,   234,
     235,   236,   399,     0,   403,     0,     0,     0,     0,   237,
     404,   405,     0,   238,     0,   239,   406,   407,   408,   409,
     410,   411,   412,     0,     0,     0,     0,     0,     0,     0,
     413,   414,   415,   416,     0,     0,     0,     0,    74,    75,
      76,    77,   240,    78,     0,     0,   241,     0,     0,   242,
     243,    83,     0,     0,     0,     0,     0,     0,     0,   244,
     291,   292,   293,   294,   295,   296,   297,   298,    73,   299,
     300,   301,   302,   303,    74,    75,    76,    77,     0,    78,
       0,     0,   453,   417,     0,   418,     0,    83,     0,     0,
     419,   420,   421,   422,   423,   424,   425,   426,    74,    75,
      76,    77,     0,    78,     0,     0,    79,    80,    81,    82,
       0,    83,    74,    75,    76,    77,   145,    78,     0,     0,
      79,    80,    81,    82,   146,    83,     0,     0,     0,     0,
       0,   152,    74,    75,    76,    77,   395,    78,     0,     0,
      79,    80,    81,    82,     0,    83,   304,     0,   305,   306,
       0,    24,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,     0,   117,   118,    74,    75,    76,    77,
     145,    78,     0,     0,    79,    80,    81,    82,   146,    83,
      74,    75,    76,    77,     0,    78,     0,     0,    79,    80,
      81,    82,     0,    83,    74,    75,    76,    77,     0,    78,
       0,     0,   388,    80,    81,    82,     0,    83,    74,    75,
      76,    77,     0,    78,     0,     0,   392,    80,    81,    82,
       0,    83,    74,    75,    76,    77,     0,    78,     0,     0,
     491,    80,    81,    82,     0,    83,    74,    75,    76,    77,
       0,    78,     0,     0,   497,    80,    81,    82,     0,    83,
      74,    75,    76,    77,     0,    78,     0,     0,   511,     0,
       0,     0,     0,    83
};

static const yytype_int16 yycheck[] =
{
      42,    68,   211,   133,   127,   222,   168,   338,   337,     5,
       4,    11,   234,   439,    16,    17,    18,    19,   180,    72,
       6,     4,     8,     9,     4,     4,    72,     4,    72,   112,
     105,    73,     4,    72,    29,    14,   365,    23,    29,    72,
     108,   120,   112,     7,    30,   115,   125,    72,   116,    72,
      29,   181,    72,    72,    96,    72,     6,   112,     8,     9,
     135,   103,   123,   105,   273,    72,   275,   276,    63,    77,
     123,    65,    63,    23,   108,    83,    84,    73,   112,   123,
      30,   112,    65,   305,   123,    85,   128,   217,    82,   122,
     136,   133,    72,   135,    14,    72,   226,    80,   100,    78,
      72,   126,   319,   126,   234,   322,   126,   126,     4,   126,
      28,    97,   443,   243,   110,   101,     4,   103,     6,   126,
       8,     9,   118,   119,   110,   551,   457,    73,   106,     0,
     461,     4,   118,   119,   112,    23,    15,   179,    26,   181,
      19,   108,    30,   113,   306,   112,    64,    97,     4,   366,
      72,   101,   369,   103,     4,   108,   124,   287,    76,   112,
     110,     4,   115,   116,   110,   112,   124,   112,   118,   119,
     108,     4,   118,   119,   304,   305,    50,    51,    52,    53,
     103,   223,   224,   225,   104,   105,   106,   107,   101,   109,
      74,   122,   112,   113,   114,   115,   326,   117,   113,     4,
     330,   243,   112,   104,   105,   106,   107,   116,   109,    97,
       4,   112,    72,   125,   102,   432,   117,   434,   125,   349,
     549,    10,   110,   265,   122,   267,    50,    51,    52,    53,
       1,   125,   125,     4,   108,   125,   112,   112,   112,    10,
     112,    12,    13,    14,   112,   113,   114,   115,   109,   123,
      21,    72,    23,    24,   384,   385,   418,    28,    29,    30,
     101,   123,    33,   305,     4,   307,    55,    56,    57,    58,
      59,    60,   126,    14,   436,   126,   124,   126,   320,   126,
      21,   323,   324,    72,   126,   124,   124,   329,     4,     4,
      73,    62,     4,   108,    65,    66,    67,   108,   112,     4,
     113,     4,   344,   465,    75,   467,     4,   349,    79,   125,
      81,   353,     4,    20,    72,   122,    72,   440,   441,   120,
     108,    62,    63,   125,    10,   455,   125,    10,   108,   108,
     101,   108,    20,   104,   105,   106,   107,   108,   109,   548,
     108,   112,    10,   125,   115,   116,   117,   104,   105,   106,
     107,   108,   109,   483,   125,   112,   125,   124,   488,   116,
     117,   125,    10,   104,   105,   106,   107,   108,   109,    14,
     100,   112,   113,   114,   115,   116,   117,   104,   105,   106,
     107,    72,   109,   122,   122,   427,   127,   128,   129,   122,
     117,    20,    20,   435,    72,   112,   104,   105,   106,   107,
     108,   109,   444,   122,   112,     4,   448,   115,     4,   117,
     540,    20,   126,   124,   456,   124,     4,   484,   460,   125,
      20,   463,   464,   125,   466,    20,     4,   124,   470,   124,
       4,   112,   126,     4,    10,     4,    12,    13,    14,   481,
     482,     4,     4,   217,    12,    21,    63,    23,    24,   349,
     185,   131,    28,    29,    30,   344,   125,    33,   207,   104,
     105,   106,   107,   333,   109,   208,   455,   112,   113,   114,
     115,   486,   117,   330,   517,   268,   518,   385,   520,   304,
     243,   268,   524,   179,   128,   527,    62,   529,   181,    65,
      66,    67,   345,    -1,    42,    -1,    -1,    -1,    -1,    75,
      48,    49,    -1,    79,    -1,    81,    54,    55,    56,    57,
      58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    69,    70,    71,    -1,    -1,    -1,    -1,   104,   105,
     106,   107,   108,   109,    -1,    -1,   112,    -1,    -1,   115,
     116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
      34,    35,    36,    37,    38,    39,    40,    41,    74,    43,
      44,    45,    46,    47,   104,   105,   106,   107,    -1,   109,
      -1,    -1,   112,   121,    -1,   123,    -1,   117,    -1,    -1,
     128,   129,   130,   131,   132,   133,   134,   135,   104,   105,
     106,   107,    -1,   109,    -1,    -1,   112,   113,   114,   115,
      -1,   117,   104,   105,   106,   107,   108,   109,    -1,    -1,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,
      -1,   123,   104,   105,   106,   107,   108,   109,    -1,    -1,
     112,   113,   114,   115,    -1,   117,   120,    -1,   122,   123,
      -1,   123,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    98,    99,   104,   105,   106,   107,
     108,   109,    -1,    -1,   112,   113,   114,   115,   116,   117,
     104,   105,   106,   107,    -1,   109,    -1,    -1,   112,   113,
     114,   115,    -1,   117,   104,   105,   106,   107,    -1,   109,
      -1,    -1,   112,   113,   114,   115,    -1,   117,   104,   105,
     106,   107,    -1,   109,    -1,    -1,   112,   113,   114,   115,
      -1,   117,   104,   105,   106,   107,    -1,   109,    -1,    -1,
     112,   113,   114,   115,    -1,   117,   104,   105,   106,   107,
      -1,   109,    -1,    -1,   112,   113,   114,   115,    -1,   117,
     104,   105,   106,   107,    -1,   109,    -1,    -1,   112,    -1,
      -1,    -1,    -1,   117
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     4,     6,     8,     9,    23,    26,    30,    97,   102,
     110,   138,   139,   140,   141,   143,   145,   156,   159,   161,
       7,   142,   112,   112,   123,   160,   162,   146,   112,   157,
       4,     0,   140,     4,   113,     4,    72,    72,   122,   144,
     124,   250,   251,     4,   108,   112,   115,   116,   245,   246,
      50,    51,    52,    53,   216,     4,    30,   101,   110,   118,
     119,   141,   147,   150,   151,   158,   159,   205,   206,   207,
     112,   112,   124,    74,   104,   105,   106,   107,   109,   112,
     113,   114,   115,   117,   241,   249,   254,   256,   257,   258,
     163,   108,   148,     4,   151,   103,    14,    29,    78,   152,
     153,   207,   249,    74,    72,   136,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    98,    99,   169,
     170,   171,   172,   173,   181,   182,   183,   122,   113,   249,
     112,   154,     4,   116,   249,   255,   256,   125,   125,   125,
     125,   125,     4,   183,   258,   108,   116,   247,   248,   249,
      72,   181,   123,   155,   241,   242,   243,   244,   248,   256,
     108,   112,    50,    51,    52,    53,   108,   112,   123,   174,
     175,   112,   112,   112,   164,   122,   109,   101,   252,   253,
     123,    72,   126,   126,   250,    72,   126,   126,   126,   126,
       4,   165,   112,   115,   149,   124,   254,   250,   244,   124,
     175,     5,   110,   118,   119,   166,   176,   202,   203,   204,
     124,   167,     4,     4,    73,   204,     1,   205,   208,   168,
     216,     4,    10,    12,    13,    14,    21,    23,    24,    28,
      29,    30,    33,    62,    65,    66,    67,    75,    79,    81,
     108,   112,   115,   116,   125,   147,   177,   192,   194,   198,
     200,   212,   218,   222,   224,   226,   227,   228,   236,   237,
     238,   241,   108,   112,   247,    14,   249,    14,   249,   249,
     241,   108,   108,   213,   112,   214,   215,   106,   112,   259,
     228,   241,   223,     4,     4,     4,   242,   219,   125,     4,
     229,    34,    35,    36,    37,    38,    39,    40,    41,    43,
      44,    45,    46,    47,   120,   122,   123,   225,   190,    20,
     249,    10,    55,    56,    57,    58,    59,    60,    72,   239,
     240,   249,   239,   240,    72,   216,    72,   216,   216,   122,
     125,   178,   193,   195,   112,   234,   235,   241,   199,   125,
     112,   241,   246,    14,    21,    62,    63,   112,   115,   116,
     127,   128,   129,   220,   228,   241,   249,   250,   249,    16,
      17,    18,    19,   100,   191,   108,    10,   247,   249,    10,
     247,   249,   249,   108,   209,   210,   241,   108,   108,   249,
     235,   185,   196,   196,    20,    72,   126,   190,   112,   201,
     231,   249,   112,   230,   231,   108,   160,   217,   249,   259,
     108,   155,   249,    42,    48,    49,    54,    55,    56,    57,
      58,    59,    60,    68,    69,    70,    71,   121,   123,   128,
     129,   130,   131,   132,   133,   134,   135,   221,   124,   125,
     190,   247,    10,   247,    10,    72,   123,   100,   211,    72,
     122,   122,   126,    11,    85,   180,   186,     4,    65,    80,
     197,    82,   241,   112,   234,   122,    20,    72,   126,   232,
      20,    72,   126,    72,    72,   123,    72,   123,   250,   249,
     122,   112,   247,   247,   249,   250,   210,   258,   258,   231,
     249,    77,    83,    84,   184,     4,   249,     4,    20,   227,
     249,   112,   231,    15,    19,   233,   249,   112,   231,   249,
     249,   250,   249,   250,   124,   249,   126,   124,     4,   249,
     249,   112,   241,   179,   207,   232,   241,   125,    20,   125,
      20,   124,   124,     4,    72,     4,     4,    72,     4,    72,
     187,     4,   230,   249,   112,   249,   249,   249,   249,    28,
      64,    76,   188,   126,   126,     4,     4,     4,   189,   241,
       4,   216,   190,   210
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (yyscanner, interp, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, yyscanner, interp)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, yyscanner, interp); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void *yyscanner, Parrot_Interp interp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yyscanner, interp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    void *yyscanner;
    Parrot_Interp interp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yyscanner);
  YYUSE (interp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, void *yyscanner, Parrot_Interp interp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yyscanner, interp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    void *yyscanner;
    Parrot_Interp interp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yyscanner, interp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, void *yyscanner, Parrot_Interp interp)
#else
static void
yy_reduce_print (yyvsp, yyrule, yyscanner, interp)
    YYSTYPE *yyvsp;
    int yyrule;
    void *yyscanner;
    Parrot_Interp interp;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , yyscanner, interp);
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, yyscanner, interp); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, void *yyscanner, Parrot_Interp interp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yyscanner, interp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    void *yyscanner;
    Parrot_Interp interp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yyscanner);
  YYUSE (interp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void *yyscanner, Parrot_Interp interp);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *yyscanner, Parrot_Interp interp)
#else
int
yyparse (yyscanner, interp)
    void *yyscanner;
    Parrot_Interp interp;
#endif
#endif
{
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 707 "compilers/imcc/imcc.y"
    { if (yynerrs) YYABORT; (yyval.i) = 0; ;}
    break;

  case 5:
#line 716 "compilers/imcc/imcc.y"
    { (yyval.i) = (yyvsp[(1) - (1)].i); ;}
    break;

  case 6:
#line 717 "compilers/imcc/imcc.y"
    { (yyval.i) = (yyvsp[(1) - (1)].i); ;}
    break;

  case 7:
#line 719 "compilers/imcc/imcc.y"
    {
           (yyval.i) = (yyvsp[(1) - (1)].i);
           imc_close_unit(interp, IMCC_INFO(interp)->cur_unit);
           IMCC_INFO(interp)->cur_unit = 0;
         ;}
    break;

  case 8:
#line 725 "compilers/imcc/imcc.y"
    {
           (yyval.i) = (yyvsp[(1) - (1)].i);
           imc_close_unit(interp, IMCC_INFO(interp)->cur_unit);
           IMCC_INFO(interp)->cur_unit = 0;
         ;}
    break;

  case 9:
#line 730 "compilers/imcc/imcc.y"
    { (yyval.i) = 0; ;}
    break;

  case 10:
#line 731 "compilers/imcc/imcc.y"
    { (yyval.i) = 0; ;}
    break;

  case 11:
#line 732 "compilers/imcc/imcc.y"
    { (yyval.i) = 0; ;}
    break;

  case 12:
#line 736 "compilers/imcc/imcc.y"
    { (yyval.i) = 0; ;}
    break;

  case 13:
#line 737 "compilers/imcc/imcc.y"
    { (yyval.i) = 0; ;}
    break;

  case 14:
#line 739 "compilers/imcc/imcc.y"
    {
           (yyval.i) = 0;
           do_loadlib(interp, (yyvsp[(2) - (3)].s));
           mem_sys_free((yyvsp[(2) - (3)].s));
         ;}
    break;

  case 15:
#line 748 "compilers/imcc/imcc.y"
    {
           if ((yyvsp[(2) - (2)].s))
               IMCC_INFO(interp)->state->pragmas |= PR_N_OPERATORS;
           else
               IMCC_INFO(interp)->state->pragmas &= ~PR_N_OPERATORS;
         ;}
    break;

  case 16:
#line 758 "compilers/imcc/imcc.y"
    {
            STRING * const hll_name = string_unescape_cstring(interp, (yyvsp[(2) - (4)].s) + 1, '"', NULL);
            CONTEXT(interp)->current_HLL =
                Parrot_register_HLL(interp, hll_name);

            /* don't bother loading the library for an empty string */
            if (strlen((yyvsp[(4) - (4)].s)) > 2) {
                STRING * const hll_lib =
                    string_unescape_cstring(interp, (yyvsp[(4) - (4)].s) + 1, '"', NULL);
                PMC    *ignored        = Parrot_load_lib(interp, hll_lib, NULL);
                UNUSED(ignored);
                Parrot_register_HLL_lib(interp, hll_lib);
            }

            IMCC_INFO(interp)->cur_namespace = NULL;
            (yyval.t) = 0;
         ;}
    break;

  case 17:
#line 776 "compilers/imcc/imcc.y"
    {
            Parrot_Context *ctx           = CONTEXT(interp);
            STRING * const  built_in_name =
                string_unescape_cstring(interp, (yyvsp[(2) - (4)].s) + 1, '"', NULL);
            STRING * const language_name  =
                string_unescape_cstring(interp, (yyvsp[(4) - (4)].s) + 1, '"', NULL);

            int             built_in_type = pmc_type(interp, built_in_name);
            int             language_type = pmc_type(interp, language_name);

            Parrot_register_HLL_type(interp, ctx->current_HLL,
                built_in_type, language_type);
            (yyval.t) = 0;
         ;}
    break;

  case 20:
#line 800 "compilers/imcc/imcc.y"
    { is_def = 1; ;}
    break;

  case 21:
#line 801 "compilers/imcc/imcc.y"
    {
             mk_const_ident(interp, (yyvsp[(4) - (6)].s), (yyvsp[(3) - (6)].t), (yyvsp[(6) - (6)].sr), 1);
             mem_sys_free((yyvsp[(4) - (6)].s));
             is_def = 0;
         ;}
    break;

  case 22:
#line 809 "compilers/imcc/imcc.y"
    { is_def=1; ;}
    break;

  case 23:
#line 810 "compilers/imcc/imcc.y"
    {
           (yyval.i) = mk_pmc_const(interp, IMCC_INFO(interp)->cur_unit, (yyvsp[(3) - (6)].s), (yyvsp[(4) - (6)].sr), (yyvsp[(6) - (6)].s));
           is_def = 0;
         ;}
    break;

  case 28:
#line 826 "compilers/imcc/imcc.y"
    { (yyval.i) = 0;  ;}
    break;

  case 29:
#line 827 "compilers/imcc/imcc.y"
    { (yyval.i) = 0;  ;}
    break;

  case 30:
#line 828 "compilers/imcc/imcc.y"
    { (yyval.i) = 0;  ;}
    break;

  case 31:
#line 829 "compilers/imcc/imcc.y"
    { (yyval.i) = 0;  ;}
    break;

  case 32:
#line 830 "compilers/imcc/imcc.y"
    { (yyval.i) = (yyvsp[(1) - (1)].i); ;}
    break;

  case 35:
#line 835 "compilers/imcc/imcc.y"
    { clear_state(interp); ;}
    break;

  case 36:
#line 837 "compilers/imcc/imcc.y"
    {
           (yyval.i) = INS(interp, IMCC_INFO(interp)->cur_unit,
                    (yyvsp[(2) - (3)].s), 0, IMCC_INFO(interp)->regs,
                    IMCC_INFO(interp)->nargs, IMCC_INFO(interp) -> keyvec, 1);
           /* XXX: can't seem to mem_sys_free($1) here */
         ;}
    break;

  case 37:
#line 844 "compilers/imcc/imcc.y"
    {
           imc_close_unit(interp, IMCC_INFO(interp)->cur_unit);
           IMCC_INFO(interp)->cur_unit = imc_open_unit(interp, IMC_PASM);
         ;}
    break;

  case 38:
#line 849 "compilers/imcc/imcc.y"
    {
           (yyval.i) = iSUBROUTINE(interp,
                    IMCC_INFO(interp)->cur_unit,
                    mk_sub_label(interp, (yyvsp[(4) - (4)].s)));
           IMCC_INFO(interp)->cur_call->pcc_sub->pragma = (yyvsp[(3) - (4)].t);
         ;}
    break;

  case 39:
#line 856 "compilers/imcc/imcc.y"
    {
           (yyval.i) = MK_I(interp, IMCC_INFO(interp)->cur_unit, "null", 1, (yyvsp[(2) - (2)].sr));
         ;}
    break;

  case 40:
#line 860 "compilers/imcc/imcc.y"
    {
           SymReg *r = mk_pasm_reg(interp, (yyvsp[(4) - (4)].s));
           set_lexical(interp, r, (yyvsp[(2) - (4)].s));
           (yyval.i) = 0;
           mem_sys_free((yyvsp[(2) - (4)].s));
           mem_sys_free((yyvsp[(4) - (4)].s));
         ;}
    break;

  case 41:
#line 867 "compilers/imcc/imcc.y"
    { (yyval.i) = 0;;}
    break;

  case 43:
#line 875 "compilers/imcc/imcc.y"
    { IMCC_INFO(interp)->cur_unit = imc_open_unit(interp, IMC_PASM); ;}
    break;

  case 44:
#line 878 "compilers/imcc/imcc.y"
    {
           /* if (optimizer_level & OPT_PASM)
                         imc_compile_unit(interp, IMCC_INFO(interp)->cur_unit);
                         emit_flush(interp);
           */
           (yyval.i) = 0;
         ;}
    break;

  case 47:
#line 894 "compilers/imcc/imcc.y"
    {
           int re_open = 0;
           (yyval.i) = 0;
           if (IMCC_INFO(interp)->state->pasm_file && IMCC_INFO(interp)->cur_namespace) {
               imc_close_unit(interp, IMCC_INFO(interp)->cur_unit);
               re_open = 1;
           }
           IMCC_INFO(interp)->cur_namespace = (yyvsp[(2) - (3)].sr);
           if (re_open)
               IMCC_INFO(interp)->cur_unit = imc_open_unit(interp, IMC_PASM);
         ;}
    break;

  case 48:
#line 909 "compilers/imcc/imcc.y"
    {
            if (IMCC_INFO(interp)->in_slice)
                IMCC_fataly(interp, EXCEPTION_SYNTAX_ERROR,
                    "Slice not allowed in namespace.");

            (yyval.sr) = (yyvsp[(2) - (3)].sr);
        ;}
    break;

  case 49:
#line 916 "compilers/imcc/imcc.y"
    { (yyval.sr) = NULL; ;}
    break;

  case 50:
#line 917 "compilers/imcc/imcc.y"
    { (yyval.sr) = NULL; ;}
    break;

  case 51:
#line 922 "compilers/imcc/imcc.y"
    {
           IMCC_INFO(interp)->cur_unit = imc_open_unit(interp, IMC_PCCSUB);
         ;}
    break;

  case 52:
#line 926 "compilers/imcc/imcc.y"
    {
           iSUBROUTINE(interp, IMCC_INFO(interp)->cur_unit, (yyvsp[(3) - (3)].sr));
         ;}
    break;

  case 53:
#line 929 "compilers/imcc/imcc.y"
    { IMCC_INFO(interp)->cur_call->pcc_sub->pragma = (yyvsp[(5) - (6)].t); ;}
    break;

  case 54:
#line 931 "compilers/imcc/imcc.y"
    { (yyval.i) = 0; IMCC_INFO(interp)->cur_call = NULL; ;}
    break;

  case 55:
#line 935 "compilers/imcc/imcc.y"
    { (yyval.sr) = 0; ;}
    break;

  case 56:
#line 936 "compilers/imcc/imcc.y"
    { (yyval.sr) = 0; ;}
    break;

  case 57:
#line 938 "compilers/imcc/imcc.y"
    {
           if (IMCC_INFO(interp)->adv_named_id) {
                 add_pcc_named_param(interp, IMCC_INFO(interp)->cur_call,
                                     IMCC_INFO(interp)->adv_named_id, (yyvsp[(2) - (3)].sr));
                 IMCC_INFO(interp)->adv_named_id = NULL;
           }
           else
               add_pcc_arg(IMCC_INFO(interp)->cur_call, (yyvsp[(2) - (3)].sr));
         ;}
    break;

  case 58:
#line 950 "compilers/imcc/imcc.y"
    { is_def=1; ;}
    break;

  case 59:
#line 950 "compilers/imcc/imcc.y"
    { (yyval.sr) = (yyvsp[(3) - (3)].sr); is_def=0; ;}
    break;

  case 60:
#line 955 "compilers/imcc/imcc.y"
    {
           if ((yyvsp[(3) - (3)].t) & VT_UNIQUE_REG)
               (yyval.sr) = mk_ident_ur(interp, (yyvsp[(2) - (3)].s), (yyvsp[(1) - (3)].t));
           else
               (yyval.sr) = mk_ident(interp, (yyvsp[(2) - (3)].s), (yyvsp[(1) - (3)].t));
           (yyval.sr)->type |= (yyvsp[(3) - (3)].t);
           mem_sys_free((yyvsp[(2) - (3)].s));
          ;}
    break;

  case 61:
#line 966 "compilers/imcc/imcc.y"
    {
            if ((yyvsp[(5) - (5)].t) & VT_UNIQUE_REG)
                (yyval.sr) = mk_ident_ur(interp, (yyvsp[(4) - (5)].s), (yyvsp[(1) - (5)].t));
            else
                (yyval.sr) = mk_ident(interp, (yyvsp[(4) - (5)].s), (yyvsp[(1) - (5)].t));
            (yyval.sr)->type |= (yyvsp[(5) - (5)].t);
            adv_named_set(interp, (yyvsp[(2) - (5)].s));
            mem_sys_free((yyvsp[(4) - (5)].s));
          ;}
    break;

  case 62:
#line 980 "compilers/imcc/imcc.y"
    { (yyval.t) = 0; ;}
    break;

  case 63:
#line 985 "compilers/imcc/imcc.y"
    {
           (yyval.t) = 0;
           IMCC_INFO(interp)->cur_unit->outer = mk_sub_address_fromc(interp, (yyvsp[(3) - (4)].s));
           mem_sys_free((yyvsp[(3) - (4)].s));
         ;}
    break;

  case 64:
#line 991 "compilers/imcc/imcc.y"
    {
           (yyval.t) = 0;
           IMCC_INFO(interp)->cur_unit->outer = mk_const(interp, (yyvsp[(3) - (4)].s), 'S');
           mem_sys_free((yyvsp[(3) - (4)].s));
         ;}
    break;

  case 65:
#line 1000 "compilers/imcc/imcc.y"
    {
           (yyval.t) = 0;
           IMCC_INFO(interp)->cur_unit->vtable_name = NULL;
           IMCC_INFO(interp)->cur_unit->is_vtable_method = 1;
         ;}
    break;

  case 66:
#line 1006 "compilers/imcc/imcc.y"
    {
           (yyval.t) = 0;
           IMCC_INFO(interp)->cur_unit->vtable_name = (yyvsp[(3) - (4)].s);
           IMCC_INFO(interp)->cur_unit->is_vtable_method = 1;
         ;}
    break;

  case 67:
#line 1015 "compilers/imcc/imcc.y"
    {
           (yyval.t) = 0;
           IMCC_INFO(interp)->cur_unit->instance_of = (yyvsp[(3) - (4)].s);
         ;}
    break;

  case 68:
#line 1023 "compilers/imcc/imcc.y"
    {
           (yyval.t) = 0;
           IMCC_INFO(interp)->cur_unit->lexid = mk_const(interp, (yyvsp[(3) - (4)].s), 'S');
           mem_sys_free((yyvsp[(3) - (4)].s));
         ;}
    break;

  case 69:
#line 1032 "compilers/imcc/imcc.y"
    {
           add_pcc_multi(IMCC_INFO(interp)->cur_call, NULL);
         ;}
    break;

  case 70:
#line 1036 "compilers/imcc/imcc.y"
    {
           (yyval.t) = 0;
           add_pcc_multi(IMCC_INFO(interp)->cur_call, (yyvsp[(3) - (3)].sr));
         ;}
    break;

  case 71:
#line 1041 "compilers/imcc/imcc.y"
    {
           (yyval.t) = 0;
           add_pcc_multi(IMCC_INFO(interp)->cur_call, (yyvsp[(1) - (1)].sr));
         ;}
    break;

  case 72:
#line 1048 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_const(interp, "INTVAL",   'S'); ;}
    break;

  case 73:
#line 1049 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_const(interp, "FLOATVAL", 'S'); ;}
    break;

  case 74:
#line 1050 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_const(interp, "PMC",      'S'); ;}
    break;

  case 75:
#line 1051 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_const(interp, "STRING",   'S'); ;}
    break;

  case 76:
#line 1053 "compilers/imcc/imcc.y"
    {
           SymReg *r;
           if (strcmp((yyvsp[(1) - (1)].s), "_") != 0)
               r = mk_const(interp, (yyvsp[(1) - (1)].s), 'S');
           else {
               r = mk_const(interp, "PMC", 'S');
           }
           mem_sys_free((yyvsp[(1) - (1)].s));
           (yyval.sr) = r;
         ;}
    break;

  case 77:
#line 1064 "compilers/imcc/imcc.y"
    {
           SymReg *r;
           if (strcmp((yyvsp[(1) - (1)].s), "_") != 0)
               r = mk_const(interp, (yyvsp[(1) - (1)].s), 'S');
           else {
               r = mk_const(interp, "PMC", 'S');
           }
           mem_sys_free((yyvsp[(1) - (1)].s));
           (yyval.sr) = r;
         ;}
    break;

  case 78:
#line 1074 "compilers/imcc/imcc.y"
    { (yyval.sr) = (yyvsp[(2) - (3)].sr); ;}
    break;

  case 81:
#line 1084 "compilers/imcc/imcc.y"
    {
           char name[128];
           SymReg *r, *r1;
           Instruction *i;

           snprintf(name, sizeof (name), "%cpcc_sub_call_%d",
                   IMCC_INTERNAL_CHAR, IMCC_INFO(interp)->cnr++);
           (yyval.sr) = r = mk_pcc_sub(interp, name, 0);
           /* this mid rule action has the semantic value of the
            * sub SymReg.
            * This is used below to append args & results
            */
           i = iLABEL(interp, IMCC_INFO(interp)->cur_unit, r);
           IMCC_INFO(interp)->cur_call = r;
           i->type = ITPCCSUB;
           /*
            * if we are inside a pcc_sub mark the sub as doing a
            * sub call; the sub is in r[0] of the first ins
            */
           r1 = IMCC_INFO(interp)->cur_unit->instructions->symregs[0];
           if (r1 && r1->pcc_sub)
               r1->pcc_sub->calls_a_sub |= 1;
         ;}
    break;

  case 82:
#line 1112 "compilers/imcc/imcc.y"
    { (yyval.i) = 0; IMCC_INFO(interp)->cur_call = NULL; ;}
    break;

  case 83:
#line 1116 "compilers/imcc/imcc.y"
    { (yyval.i) = NULL; IMCC_INFO(interp)->cur_call->pcc_sub->label = 0; ;}
    break;

  case 84:
#line 1117 "compilers/imcc/imcc.y"
    { (yyval.i) = NULL; IMCC_INFO(interp)->cur_call->pcc_sub->label = 1; ;}
    break;

  case 85:
#line 1121 "compilers/imcc/imcc.y"
    { (yyval.i) = NULL; ;}
    break;

  case 86:
#line 1122 "compilers/imcc/imcc.y"
    { (yyval.i) = NULL;  IMCC_INFO(interp)->cur_call->pcc_sub->object = (yyvsp[(2) - (3)].sr); ;}
    break;

  case 87:
#line 1126 "compilers/imcc/imcc.y"
    { (yyval.t) = 0; ;}
    break;

  case 89:
#line 1131 "compilers/imcc/imcc.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 90:
#line 1132 "compilers/imcc/imcc.y"
    { (yyval.t) = (yyvsp[(1) - (2)].t) | (yyvsp[(2) - (2)].t); ;}
    break;

  case 91:
#line 1136 "compilers/imcc/imcc.y"
    { (yyval.t) = P_LOAD; ;}
    break;

  case 92:
#line 1137 "compilers/imcc/imcc.y"
    { (yyval.t) = P_INIT; ;}
    break;

  case 93:
#line 1138 "compilers/imcc/imcc.y"
    { (yyval.t) = P_MAIN; ;}
    break;

  case 94:
#line 1139 "compilers/imcc/imcc.y"
    { (yyval.t) = P_IMMEDIATE; ;}
    break;

  case 95:
#line 1140 "compilers/imcc/imcc.y"
    { (yyval.t) = P_POSTCOMP; ;}
    break;

  case 96:
#line 1141 "compilers/imcc/imcc.y"
    { (yyval.t) = P_ANON; ;}
    break;

  case 97:
#line 1142 "compilers/imcc/imcc.y"
    { (yyval.t) = P_METHOD; ;}
    break;

  case 98:
#line 1143 "compilers/imcc/imcc.y"
    { (yyval.t) = P_NEED_LEX; ;}
    break;

  case 104:
#line 1153 "compilers/imcc/imcc.y"
    {
           add_pcc_sub(IMCC_INFO(interp)->cur_call, (yyvsp[(2) - (5)].sr));
           add_pcc_cc(IMCC_INFO(interp)->cur_call, (yyvsp[(4) - (5)].sr));
         ;}
    break;

  case 105:
#line 1158 "compilers/imcc/imcc.y"
    {
           add_pcc_sub(IMCC_INFO(interp)->cur_call, (yyvsp[(2) - (3)].sr));
         ;}
    break;

  case 106:
#line 1162 "compilers/imcc/imcc.y"
    {
           add_pcc_sub(IMCC_INFO(interp)->cur_call, (yyvsp[(2) - (3)].sr));
           IMCC_INFO(interp)->cur_call->pcc_sub->flags |= isNCI;
         ;}
    break;

  case 107:
#line 1167 "compilers/imcc/imcc.y"
    {
           add_pcc_sub(IMCC_INFO(interp)->cur_call, (yyvsp[(2) - (3)].sr));
         ;}
    break;

  case 108:
#line 1171 "compilers/imcc/imcc.y"
    {
           add_pcc_sub(IMCC_INFO(interp)->cur_call, mk_const(interp, (yyvsp[(2) - (3)].s), 'S'));
         ;}
    break;

  case 109:
#line 1175 "compilers/imcc/imcc.y"
    {
           add_pcc_sub(IMCC_INFO(interp)->cur_call, (yyvsp[(2) - (5)].sr));
           add_pcc_cc(IMCC_INFO(interp)->cur_call, (yyvsp[(4) - (5)].sr));
         ;}
    break;

  case 110:
#line 1180 "compilers/imcc/imcc.y"
    {
           add_pcc_sub(IMCC_INFO(interp)->cur_call, mk_const(interp, (yyvsp[(2) - (5)].s), 'S'));
           add_pcc_cc(IMCC_INFO(interp)->cur_call, (yyvsp[(4) - (5)].sr));
         ;}
    break;

  case 111:
#line 1188 "compilers/imcc/imcc.y"
    { (yyval.sr) = 0; ;}
    break;

  case 112:
#line 1189 "compilers/imcc/imcc.y"
    { add_pcc_arg(IMCC_INFO(interp)->cur_call, (yyvsp[(2) - (3)].sr)); ;}
    break;

  case 113:
#line 1193 "compilers/imcc/imcc.y"
    { (yyval.sr) = (yyvsp[(2) - (2)].sr); ;}
    break;

  case 114:
#line 1198 "compilers/imcc/imcc.y"
    { (yyval.sr) = 0; ;}
    break;

  case 115:
#line 1200 "compilers/imcc/imcc.y"
    {
           if ((yyvsp[(2) - (3)].sr))
               add_pcc_result(IMCC_INFO(interp)->cur_call, (yyvsp[(2) - (3)].sr));
         ;}
    break;

  case 116:
#line 1207 "compilers/imcc/imcc.y"
    { (yyval.sr) = (yyvsp[(2) - (3)].sr); (yyval.sr)->type |= (yyvsp[(3) - (3)].t); ;}
    break;

  case 117:
#line 1208 "compilers/imcc/imcc.y"
    { is_def=1; ;}
    break;

  case 118:
#line 1209 "compilers/imcc/imcc.y"
    {
           IdList *l = (yyvsp[(4) - (4)].idlist);
           SymReg *ignored;
           if (l->unique_reg)
               ignored = mk_ident_ur(interp, l->id, (yyvsp[(3) - (4)].t));
           else
               ignored = mk_ident(interp, l->id, (yyvsp[(3) - (4)].t));
           UNUSED(ignored);
           is_def=0;
           (yyval.sr)=0;
         ;}
    break;

  case 119:
#line 1223 "compilers/imcc/imcc.y"
    { (yyval.t) = 0; ;}
    break;

  case 120:
#line 1224 "compilers/imcc/imcc.y"
    { (yyval.t) = (yyvsp[(1) - (2)].t) | (yyvsp[(2) - (2)].t); ;}
    break;

  case 121:
#line 1228 "compilers/imcc/imcc.y"
    { (yyval.t) = VT_FLAT;   ;}
    break;

  case 122:
#line 1229 "compilers/imcc/imcc.y"
    { (yyval.t) = VT_OPTIONAL; ;}
    break;

  case 123:
#line 1230 "compilers/imcc/imcc.y"
    { (yyval.t) = VT_OPT_FLAG; ;}
    break;

  case 124:
#line 1231 "compilers/imcc/imcc.y"
    { (yyval.t) = VT_NAMED; ;}
    break;

  case 125:
#line 1232 "compilers/imcc/imcc.y"
    { adv_named_set(interp, (yyvsp[(3) - (4)].s)); (yyval.t) = 0; ;}
    break;

  case 126:
#line 1233 "compilers/imcc/imcc.y"
    { (yyval.t) = VT_UNIQUE_REG; ;}
    break;

  case 127:
#line 1239 "compilers/imcc/imcc.y"
    {
           begin_return_or_yield(interp, 0);
         ;}
    break;

  case 128:
#line 1243 "compilers/imcc/imcc.y"
    {
           (yyval.i) = 0;
           IMCC_INFO(interp)->asm_state = AsmDefault;
         ;}
    break;

  case 129:
#line 1248 "compilers/imcc/imcc.y"
    {
           IMCC_INFO(interp)->asm_state = AsmDefault;
           (yyval.i) = 0;
         ;}
    break;

  case 130:
#line 1255 "compilers/imcc/imcc.y"
    { begin_return_or_yield(interp, 1); ;}
    break;

  case 131:
#line 1257 "compilers/imcc/imcc.y"
    { (yyval.i) = 0; IMCC_INFO(interp)->asm_state = AsmDefault; ;}
    break;

  case 132:
#line 1261 "compilers/imcc/imcc.y"
    { (yyval.sr) = 0; ;}
    break;

  case 133:
#line 1263 "compilers/imcc/imcc.y"
    {
           if ((yyvsp[(1) - (2)].sr))
               add_pcc_result(IMCC_INFO(interp)->sr_return, (yyvsp[(1) - (2)].sr));
         ;}
    break;

  case 134:
#line 1268 "compilers/imcc/imcc.y"
    {
           if ((yyvsp[(2) - (3)].sr))
               add_pcc_result(IMCC_INFO(interp)->sr_return, (yyvsp[(2) - (3)].sr));
         ;}
    break;

  case 135:
#line 1275 "compilers/imcc/imcc.y"
    { (yyval.sr) = (yyvsp[(2) - (3)].sr); (yyval.sr)->type |= (yyvsp[(3) - (3)].t); ;}
    break;

  case 136:
#line 1280 "compilers/imcc/imcc.y"
    {
          if (IMCC_INFO(interp)->asm_state == AsmDefault)
              begin_return_or_yield(interp, (yyvsp[(1) - (2)].t));
        ;}
    break;

  case 137:
#line 1285 "compilers/imcc/imcc.y"
    {
          IMCC_INFO(interp)->asm_state = AsmDefault;
          (yyval.t) = 0;
        ;}
    break;

  case 138:
#line 1292 "compilers/imcc/imcc.y"
    { (yyval.t) = 0; ;}
    break;

  case 139:
#line 1293 "compilers/imcc/imcc.y"
    { (yyval.t) = 1; ;}
    break;

  case 140:
#line 1297 "compilers/imcc/imcc.y"
    { (yyval.i) = 0; ;}
    break;

  case 141:
#line 1299 "compilers/imcc/imcc.y"
    {
           if (IMCC_INFO(interp)->adv_named_id) {
               add_pcc_named_return(interp, IMCC_INFO(interp)->sr_return,
                                    IMCC_INFO(interp)->adv_named_id, (yyvsp[(1) - (1)].sr));
               IMCC_INFO(interp)->adv_named_id = NULL;
           }
           else
               add_pcc_result(IMCC_INFO(interp)->sr_return, (yyvsp[(1) - (1)].sr));
         ;}
    break;

  case 142:
#line 1309 "compilers/imcc/imcc.y"
    {
           add_pcc_named_return(interp, IMCC_INFO(interp)->sr_return, (yyvsp[(1) - (3)].s), (yyvsp[(3) - (3)].sr));
         ;}
    break;

  case 143:
#line 1313 "compilers/imcc/imcc.y"
    {
           if (IMCC_INFO(interp)->adv_named_id) {
               add_pcc_named_return(interp, IMCC_INFO(interp)->sr_return,
                                    IMCC_INFO(interp)->adv_named_id, (yyvsp[(3) - (3)].sr));
               IMCC_INFO(interp)->adv_named_id = NULL;
             }
             else
                 add_pcc_result(IMCC_INFO(interp)->sr_return, (yyvsp[(3) - (3)].sr));
         ;}
    break;

  case 144:
#line 1323 "compilers/imcc/imcc.y"
    {
           add_pcc_named_return(interp, IMCC_INFO(interp)->sr_return, (yyvsp[(3) - (5)].s), (yyvsp[(5) - (5)].sr));
         ;}
    break;

  case 147:
#line 1343 "compilers/imcc/imcc.y"
    { clear_state(interp); ;}
    break;

  case 148:
#line 1348 "compilers/imcc/imcc.y"
    { (yyval.i) = (yyvsp[(2) - (2)].i); ;}
    break;

  case 149:
#line 1349 "compilers/imcc/imcc.y"
    { (yyval.i) = 0; ;}
    break;

  case 150:
#line 1350 "compilers/imcc/imcc.y"
    { (yyval.i) = 0; ;}
    break;

  case 151:
#line 1351 "compilers/imcc/imcc.y"
    { (yyval.i) = 0; ;}
    break;

  case 152:
#line 1355 "compilers/imcc/imcc.y"
    { (yyval.i) = NULL; ;}
    break;

  case 156:
#line 1366 "compilers/imcc/imcc.y"
    {
           (yyval.i) = iLABEL(interp, IMCC_INFO(interp)->cur_unit, mk_local_label(interp, (yyvsp[(1) - (1)].s)));
         ;}
    break;

  case 157:
#line 1374 "compilers/imcc/imcc.y"
    { (yyval.i) = (yyvsp[(2) - (3)].i); ;}
    break;

  case 158:
#line 1376 "compilers/imcc/imcc.y"
    {
           if (yynerrs >= PARROT_MAX_RECOVER_ERRORS) {
               IMCC_warning(interp, "Too many errors. Correct some first.\n");
               YYABORT;
           }
           yyerrok;
         ;}
    break;

  case 159:
#line 1387 "compilers/imcc/imcc.y"
    {
           IdList* l = (yyvsp[(1) - (1)].idlist);
           l->next = NULL;
           (yyval.idlist) = l;
         ;}
    break;

  case 160:
#line 1394 "compilers/imcc/imcc.y"
    {
           IdList* l = (yyvsp[(3) - (3)].idlist);
           l->next = (yyvsp[(1) - (3)].idlist);
           (yyval.idlist) = l;
         ;}
    break;

  case 161:
#line 1403 "compilers/imcc/imcc.y"
    {
           IdList* const l = mem_allocate_n_zeroed_typed(1, IdList);
           l->id           = (yyvsp[(1) - (2)].s);
           l->unique_reg   = (yyvsp[(2) - (2)].t);
           (yyval.idlist) = l;
         ;}
    break;

  case 162:
#line 1412 "compilers/imcc/imcc.y"
    { (yyval.t) = 0; ;}
    break;

  case 163:
#line 1413 "compilers/imcc/imcc.y"
    { (yyval.t) = 1; ;}
    break;

  case 166:
#line 1420 "compilers/imcc/imcc.y"
    { push_namespace(interp, (yyvsp[(2) - (2)].s)); mem_sys_free((yyvsp[(2) - (2)].s)); ;}
    break;

  case 167:
#line 1421 "compilers/imcc/imcc.y"
    { pop_namespace(interp, (yyvsp[(2) - (2)].s)); mem_sys_free((yyvsp[(2) - (2)].s)); ;}
    break;

  case 168:
#line 1422 "compilers/imcc/imcc.y"
    { is_def=1; ;}
    break;

  case 169:
#line 1423 "compilers/imcc/imcc.y"
    {
           IdList *l = (yyvsp[(4) - (4)].idlist);
           while (l) {
               IdList *l1;
               if (l->unique_reg)
                   mk_ident_ur(interp, l->id, (yyvsp[(3) - (4)].t));
               else
                   mk_ident(interp, l->id, (yyvsp[(3) - (4)].t));
               l1 = l;
               l  = l->next;
               mem_sys_free(l1->id);
               mem_sys_free(l1);
           }
           is_def=0; (yyval.i)=0;
         ;}
    break;

  case 170:
#line 1439 "compilers/imcc/imcc.y"
    {
           set_lexical(interp, (yyvsp[(4) - (4)].sr), (yyvsp[(2) - (4)].s)); (yyval.i) = 0;
         ;}
    break;

  case 171:
#line 1442 "compilers/imcc/imcc.y"
    { is_def=1; ;}
    break;

  case 172:
#line 1443 "compilers/imcc/imcc.y"
    {
           mk_const_ident(interp, (yyvsp[(4) - (6)].s), (yyvsp[(3) - (6)].t), (yyvsp[(6) - (6)].sr), 0);
           is_def=0;
           mem_sys_free((yyvsp[(4) - (6)].s));
         ;}
    break;

  case 174:
#line 1450 "compilers/imcc/imcc.y"
    { is_def=1; ;}
    break;

  case 175:
#line 1451 "compilers/imcc/imcc.y"
    {
           mk_const_ident(interp, (yyvsp[(4) - (6)].s), (yyvsp[(3) - (6)].t), (yyvsp[(6) - (6)].sr), 1);
           is_def=0;
           mem_sys_free((yyvsp[(4) - (6)].s));
         ;}
    break;

  case 176:
#line 1457 "compilers/imcc/imcc.y"
    {
           (yyval.i) = NULL;
           IMCC_INFO(interp)->cur_call->pcc_sub->flags |= isTAIL_CALL;
           IMCC_INFO(interp)->cur_call = NULL;
         ;}
    break;

  case 177:
#line 1462 "compilers/imcc/imcc.y"
    { (yyval.i) = MK_I(interp, IMCC_INFO(interp)->cur_unit, "branch", 1, (yyvsp[(2) - (2)].sr)); ;}
    break;

  case 178:
#line 1464 "compilers/imcc/imcc.y"
    {
           (yyval.i) = INS(interp,
                    IMCC_INFO(interp)->cur_unit,
                    (yyvsp[(1) - (2)].s),
                    0,
                    IMCC_INFO(interp)->regs,
                    IMCC_INFO(interp)->nargs,
                    IMCC_INFO(interp)->keyvec,
                    1);
           mem_sys_free((yyvsp[(1) - (2)].s));
         ;}
    break;

  case 179:
#line 1475 "compilers/imcc/imcc.y"
    { (yyval.i) = MK_I(interp, IMCC_INFO(interp)->cur_unit, "null", 1, (yyvsp[(2) - (2)].sr)); ;}
    break;

  case 180:
#line 1476 "compilers/imcc/imcc.y"
    { (yyval.i) = 0; IMCC_INFO(interp)->cur_call = NULL; ;}
    break;

  case 181:
#line 1477 "compilers/imcc/imcc.y"
    { (yyval.i) = 0; ;}
    break;

  case 184:
#line 1480 "compilers/imcc/imcc.y"
    { (yyval.i) = 0;;}
    break;

  case 185:
#line 1484 "compilers/imcc/imcc.y"
    { (yyval.t) = 'I'; ;}
    break;

  case 186:
#line 1485 "compilers/imcc/imcc.y"
    { (yyval.t) = 'N'; ;}
    break;

  case 187:
#line 1486 "compilers/imcc/imcc.y"
    { (yyval.t) = 'S'; ;}
    break;

  case 188:
#line 1487 "compilers/imcc/imcc.y"
    { (yyval.t) = 'P'; ;}
    break;

  case 189:
#line 1492 "compilers/imcc/imcc.y"
    {
           /* there'd normally be a str_dup() here, but the lexer already
            * copied the string, so it's safe to use directly */
           if ((IMCC_INFO(interp)->cur_pmc_type = pmc_type(interp,
               string_from_cstring(interp, (yyvsp[(1) - (1)].s), 0))) <= 0) {
               IMCC_fataly(interp, EXCEPTION_SYNTAX_ERROR,
                    "Unknown PMC type '%s'\n", (yyvsp[(1) - (1)].s));
           }
         ;}
    break;

  case 190:
#line 1505 "compilers/imcc/imcc.y"
    { (yyval.i) = MK_I(interp, IMCC_INFO(interp)->cur_unit, "set", 2, (yyvsp[(1) - (3)].sr), (yyvsp[(3) - (3)].sr));  ;}
    break;

  case 191:
#line 1507 "compilers/imcc/imcc.y"
    { (yyval.i) = MK_I(interp, IMCC_INFO(interp)->cur_unit, (yyvsp[(3) - (4)].s), 2, (yyvsp[(1) - (4)].sr), (yyvsp[(4) - (4)].sr));  ;}
    break;

  case 192:
#line 1509 "compilers/imcc/imcc.y"
    { (yyval.i) = MK_I(interp, IMCC_INFO(interp)->cur_unit, (yyvsp[(4) - (5)].s), 3, (yyvsp[(1) - (5)].sr), (yyvsp[(3) - (5)].sr), (yyvsp[(5) - (5)].sr));  ;}
    break;

  case 193:
#line 1511 "compilers/imcc/imcc.y"
    { (yyval.i) = iINDEXFETCH(interp, IMCC_INFO(interp)->cur_unit, (yyvsp[(1) - (6)].sr), (yyvsp[(3) - (6)].sr), (yyvsp[(5) - (6)].sr)); ;}
    break;

  case 194:
#line 1513 "compilers/imcc/imcc.y"
    { (yyval.i) = iINDEXSET(interp, IMCC_INFO(interp)->cur_unit, (yyvsp[(1) - (6)].sr), (yyvsp[(3) - (6)].sr), (yyvsp[(6) - (6)].sr)); ;}
    break;

  case 195:
#line 1515 "compilers/imcc/imcc.y"
    { (yyval.i) = iNEW(interp, IMCC_INFO(interp)->cur_unit, (yyvsp[(1) - (6)].sr), (yyvsp[(4) - (6)].s), (yyvsp[(6) - (6)].sr), 1); ;}
    break;

  case 196:
#line 1517 "compilers/imcc/imcc.y"
    { (yyval.i) = iNEW(interp, IMCC_INFO(interp)->cur_unit, (yyvsp[(1) - (7)].sr), (yyvsp[(4) - (7)].s), (yyvsp[(6) - (7)].sr), 1); ;}
    break;

  case 197:
#line 1519 "compilers/imcc/imcc.y"
    { (yyval.i) = iNEW(interp, IMCC_INFO(interp)->cur_unit, (yyvsp[(1) - (4)].sr), (yyvsp[(4) - (4)].s), NULL, 1); ;}
    break;

  case 198:
#line 1521 "compilers/imcc/imcc.y"
    { (yyval.i) = MK_I(interp, IMCC_INFO(interp)->cur_unit, "new", 2, (yyvsp[(1) - (4)].sr), (yyvsp[(4) - (4)].sr)); ;}
    break;

  case 199:
#line 1523 "compilers/imcc/imcc.y"
    { (yyval.i) = MK_I(interp, IMCC_INFO(interp)->cur_unit, "new", 2, (yyvsp[(1) - (4)].sr), (yyvsp[(4) - (4)].sr)); ;}
    break;

  case 200:
#line 1525 "compilers/imcc/imcc.y"
    { (yyval.i) = MK_I(interp, IMCC_INFO(interp)->cur_unit, "new", 3, (yyvsp[(1) - (6)].sr), (yyvsp[(4) - (6)].sr), (yyvsp[(6) - (6)].sr)); ;}
    break;

  case 201:
#line 1527 "compilers/imcc/imcc.y"
    { (yyval.i) = MK_I(interp, IMCC_INFO(interp)->cur_unit, "new", 3, (yyvsp[(1) - (6)].sr), (yyvsp[(4) - (6)].sr), (yyvsp[(6) - (6)].sr)); ;}
    break;

  case 202:
#line 1529 "compilers/imcc/imcc.y"
    { (yyval.i) = MK_I(interp, IMCC_INFO(interp)->cur_unit, "new", 3, (yyvsp[(1) - (7)].sr), (yyvsp[(4) - (7)].sr), (yyvsp[(6) - (7)].sr)); ;}
    break;

  case 203:
#line 1531 "compilers/imcc/imcc.y"
    { (yyval.i) = MK_I(interp, IMCC_INFO(interp)->cur_unit, "set_addr",
                        2, (yyvsp[(1) - (4)].sr), mk_label_address(interp, (yyvsp[(4) - (4)].s))); mem_sys_free((yyvsp[(4) - (4)].s)); ;}
    break;

  case 204:
#line 1534 "compilers/imcc/imcc.y"
    { (yyval.i) = MK_I(interp, IMCC_INFO(interp)->cur_unit, "find_global", 2, (yyvsp[(1) - (4)].sr), (yyvsp[(4) - (4)].sr));;}
    break;

  case 205:
#line 1536 "compilers/imcc/imcc.y"
    { (yyval.i) = MK_I(interp, IMCC_INFO(interp)->cur_unit, "store_global", 2, (yyvsp[(2) - (4)].sr), (yyvsp[(4) - (4)].sr)); ;}
    break;

  case 206:
#line 1540 "compilers/imcc/imcc.y"
    { (yyval.i) = MK_I(interp, IMCC_INFO(interp)->cur_unit, "new", 2, (yyvsp[(2) - (4)].sr), (yyvsp[(4) - (4)].sr)); ;}
    break;

  case 207:
#line 1542 "compilers/imcc/imcc.y"
    { (yyval.i) = MK_I(interp, IMCC_INFO(interp)->cur_unit, "new", 3, (yyvsp[(2) - (6)].sr), (yyvsp[(4) - (6)].sr), (yyvsp[(6) - (6)].sr)); ;}
    break;

  case 208:
#line 1544 "compilers/imcc/imcc.y"
    { (yyval.i) = MK_I(interp, IMCC_INFO(interp)->cur_unit, "new", 3, (yyvsp[(2) - (7)].sr), (yyvsp[(4) - (7)].sr), (yyvsp[(6) - (7)].sr)); ;}
    break;

  case 209:
#line 1547 "compilers/imcc/imcc.y"
    {
           add_pcc_result((yyvsp[(3) - (3)].i)->symregs[0], (yyvsp[(1) - (3)].sr));
           IMCC_INFO(interp)->cur_call = NULL;
           (yyval.i) = 0;
         ;}
    break;

  case 210:
#line 1553 "compilers/imcc/imcc.y"
    {
           (yyval.i) = IMCC_create_itcall_label(interp);
         ;}
    break;

  case 211:
#line 1557 "compilers/imcc/imcc.y"
    {
           IMCC_itcall_sub(interp, (yyvsp[(6) - (9)].sr));
           IMCC_INFO(interp)->cur_call = NULL;
         ;}
    break;

  case 215:
#line 1565 "compilers/imcc/imcc.y"
    {
           (yyval.i) = MK_I(interp, IMCC_INFO(interp)->cur_unit, "null", 1, (yyvsp[(1) - (3)].sr));
         ;}
    break;

  case 216:
#line 1572 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"not"; ;}
    break;

  case 217:
#line 1573 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"bnot"; ;}
    break;

  case 218:
#line 1574 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"neg"; ;}
    break;

  case 219:
#line 1578 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"sub"; ;}
    break;

  case 220:
#line 1579 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"add"; ;}
    break;

  case 221:
#line 1580 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"mul"; ;}
    break;

  case 222:
#line 1581 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"div"; ;}
    break;

  case 223:
#line 1582 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"mod"; ;}
    break;

  case 224:
#line 1583 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"fdiv"; ;}
    break;

  case 225:
#line 1584 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"pow"; ;}
    break;

  case 226:
#line 1585 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"concat"; ;}
    break;

  case 227:
#line 1586 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"iseq"; ;}
    break;

  case 228:
#line 1587 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"isne"; ;}
    break;

  case 229:
#line 1588 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"isgt"; ;}
    break;

  case 230:
#line 1589 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"isge"; ;}
    break;

  case 231:
#line 1590 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"islt"; ;}
    break;

  case 232:
#line 1591 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"isle"; ;}
    break;

  case 233:
#line 1592 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"shl"; ;}
    break;

  case 234:
#line 1593 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"shr"; ;}
    break;

  case 235:
#line 1594 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"lsr"; ;}
    break;

  case 236:
#line 1595 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"and"; ;}
    break;

  case 237:
#line 1596 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"or"; ;}
    break;

  case 238:
#line 1597 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"xor"; ;}
    break;

  case 239:
#line 1598 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"band"; ;}
    break;

  case 240:
#line 1599 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"bor"; ;}
    break;

  case 241:
#line 1600 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"bxor"; ;}
    break;

  case 242:
#line 1606 "compilers/imcc/imcc.y"
    {
           (yyval.i) = IMCC_create_itcall_label(interp);
           (yyval.i)->type &= ~ITCALL;
           (yyval.i)->type |= ITRESULT;
         ;}
    break;

  case 243:
#line 1611 "compilers/imcc/imcc.y"
    {  (yyval.i) = 0; ;}
    break;

  case 244:
#line 1618 "compilers/imcc/imcc.y"
    {
           (yyval.i) = MK_I(interp, IMCC_INFO(interp)->cur_unit, (yyvsp[(2) - (3)].s), 2, (yyvsp[(1) - (3)].sr), (yyvsp[(3) - (3)].sr));
         ;}
    break;

  case 245:
#line 1624 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"add"; ;}
    break;

  case 246:
#line 1625 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"sub"; ;}
    break;

  case 247:
#line 1626 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"mul"; ;}
    break;

  case 248:
#line 1627 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"div"; ;}
    break;

  case 249:
#line 1628 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"mod"; ;}
    break;

  case 250:
#line 1629 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"fdiv"; ;}
    break;

  case 251:
#line 1630 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"concat"; ;}
    break;

  case 252:
#line 1631 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"band"; ;}
    break;

  case 253:
#line 1632 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"bor"; ;}
    break;

  case 254:
#line 1633 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"bxor"; ;}
    break;

  case 255:
#line 1634 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"shr"; ;}
    break;

  case 256:
#line 1635 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"shl"; ;}
    break;

  case 257:
#line 1636 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"lsr"; ;}
    break;

  case 258:
#line 1642 "compilers/imcc/imcc.y"
    {
        (yyval.i) = func_ins(interp, IMCC_INFO(interp)->cur_unit, (yyvsp[(1) - (4)].sr), (yyvsp[(3) - (4)].s),
                      IMCC_INFO(interp) -> regs,
                      IMCC_INFO(interp) -> nargs,
                      IMCC_INFO(interp) -> keyvec, 1);
         mem_sys_free((yyvsp[(3) - (4)].s));
       ;}
    break;

  case 259:
#line 1652 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_sub_address(interp, (yyvsp[(1) - (1)].s));  mem_sys_free((yyvsp[(1) - (1)].s)); ;}
    break;

  case 260:
#line 1653 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_sub_address_fromc(interp, (yyvsp[(1) - (1)].s)); mem_sys_free((yyvsp[(1) - (1)].s)); ;}
    break;

  case 261:
#line 1654 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_sub_address_u(interp, (yyvsp[(1) - (1)].s)); mem_sys_free((yyvsp[(1) - (1)].s)); ;}
    break;

  case 262:
#line 1656 "compilers/imcc/imcc.y"
    {
           (yyval.sr) = (yyvsp[(1) - (1)].sr);
           if ((yyvsp[(1) - (1)].sr)->set != 'P')
               IMCC_fataly(interp, EXCEPTION_SYNTAX_ERROR, "Sub isn't a PMC");
         ;}
    break;

  case 263:
#line 1661 "compilers/imcc/imcc.y"
    { IMCC_INFO(interp)->cur_obj = (yyvsp[(1) - (3)].sr); (yyval.sr) = (yyvsp[(3) - (3)].sr); ;}
    break;

  case 264:
#line 1663 "compilers/imcc/imcc.y"
    {
           IMCC_INFO(interp)->cur_obj = (yyvsp[(1) - (3)].sr); (yyval.sr) = mk_const(interp, (yyvsp[(3) - (3)].s), 'S');
           mem_sys_free((yyvsp[(3) - (3)].s));
         ;}
    break;

  case 265:
#line 1667 "compilers/imcc/imcc.y"
    { IMCC_INFO(interp)->cur_obj = (yyvsp[(1) - (3)].sr); (yyval.sr) = (yyvsp[(3) - (3)].sr); ;}
    break;

  case 266:
#line 1673 "compilers/imcc/imcc.y"
    {
           (yyval.i) = IMCC_create_itcall_label(interp);
           IMCC_itcall_sub(interp, (yyvsp[(1) - (1)].sr));
         ;}
    break;

  case 267:
#line 1677 "compilers/imcc/imcc.y"
    { (yyval.i) = (yyvsp[(2) - (5)].i); ;}
    break;

  case 268:
#line 1681 "compilers/imcc/imcc.y"
    { (yyval.sr) = 0; ;}
    break;

  case 269:
#line 1683 "compilers/imcc/imcc.y"
    {
           (yyval.sr) = 0;
           if (IMCC_INFO(interp)->adv_named_id) {
               add_pcc_named_arg(interp, IMCC_INFO(interp)->cur_call, IMCC_INFO(interp)->adv_named_id, (yyvsp[(3) - (3)].sr));
               IMCC_INFO(interp)->adv_named_id = NULL;
           }
           else
               add_pcc_arg(IMCC_INFO(interp)->cur_call, (yyvsp[(3) - (3)].sr));
         ;}
    break;

  case 270:
#line 1693 "compilers/imcc/imcc.y"
    {
           (yyval.sr) = 0;
           if (IMCC_INFO(interp)->adv_named_id) {
               add_pcc_named_arg(interp, IMCC_INFO(interp)->cur_call, IMCC_INFO(interp)->adv_named_id, (yyvsp[(1) - (1)].sr));
               IMCC_INFO(interp)->adv_named_id = NULL;
           }
           else
               add_pcc_arg(IMCC_INFO(interp)->cur_call, (yyvsp[(1) - (1)].sr));
         ;}
    break;

  case 271:
#line 1703 "compilers/imcc/imcc.y"
    {
           (yyval.sr) = 0;
           add_pcc_named_arg(interp, IMCC_INFO(interp)->cur_call, (yyvsp[(3) - (5)].s), (yyvsp[(5) - (5)].sr));
           mem_sys_free((yyvsp[(3) - (5)].s));
         ;}
    break;

  case 272:
#line 1709 "compilers/imcc/imcc.y"
    {
           (yyval.sr) = 0;
           add_pcc_named_arg(interp, IMCC_INFO(interp)->cur_call, (yyvsp[(1) - (3)].s), (yyvsp[(3) - (3)].sr));
           mem_sys_free((yyvsp[(1) - (3)].s));
         ;}
    break;

  case 273:
#line 1717 "compilers/imcc/imcc.y"
    { (yyval.sr) = (yyvsp[(1) - (2)].sr); (yyval.sr)->type |= (yyvsp[(2) - (2)].t); ;}
    break;

  case 274:
#line 1721 "compilers/imcc/imcc.y"
    { (yyval.t) = 0; ;}
    break;

  case 275:
#line 1722 "compilers/imcc/imcc.y"
    { (yyval.t) = (yyvsp[(1) - (2)].t) | (yyvsp[(2) - (2)].t); ;}
    break;

  case 276:
#line 1726 "compilers/imcc/imcc.y"
    { (yyval.t) = VT_FLAT; ;}
    break;

  case 277:
#line 1727 "compilers/imcc/imcc.y"
    { (yyval.t) = VT_NAMED; ;}
    break;

  case 278:
#line 1730 "compilers/imcc/imcc.y"
    { adv_named_set(interp, (yyvsp[(3) - (4)].s)); (yyval.t) = 0; ;}
    break;

  case 279:
#line 1734 "compilers/imcc/imcc.y"
    { (yyval.sr) = (yyvsp[(1) - (2)].sr); (yyval.sr)->type |= (yyvsp[(2) - (2)].t); ;}
    break;

  case 280:
#line 1739 "compilers/imcc/imcc.y"
    {
           (yyval.sr) = 0;
           if (IMCC_INFO(interp)->adv_named_id) {
               add_pcc_named_result(interp, IMCC_INFO(interp)->cur_call, IMCC_INFO(interp)->adv_named_id, (yyvsp[(3) - (3)].sr));
               IMCC_INFO(interp)->adv_named_id = NULL;
           }
           else
               add_pcc_result(IMCC_INFO(interp)->cur_call, (yyvsp[(3) - (3)].sr));
         ;}
    break;

  case 281:
#line 1749 "compilers/imcc/imcc.y"
    {
           add_pcc_named_result(interp, IMCC_INFO(interp)->cur_call, (yyvsp[(3) - (5)].s), (yyvsp[(5) - (5)].sr));
           mem_sys_free((yyvsp[(3) - (5)].s));
         ;}
    break;

  case 282:
#line 1754 "compilers/imcc/imcc.y"
    {
           (yyval.sr) = 0;
           if (IMCC_INFO(interp)->adv_named_id) {
               add_pcc_named_result(interp, IMCC_INFO(interp)->cur_call, IMCC_INFO(interp)->adv_named_id, (yyvsp[(1) - (1)].sr));
               IMCC_INFO(interp)->adv_named_id = NULL;
           }
           else
               add_pcc_result(IMCC_INFO(interp)->cur_call, (yyvsp[(1) - (1)].sr));
         ;}
    break;

  case 283:
#line 1764 "compilers/imcc/imcc.y"
    {
           add_pcc_named_result(interp, IMCC_INFO(interp)->cur_call, (yyvsp[(1) - (3)].s), (yyvsp[(3) - (3)].sr));
           mem_sys_free((yyvsp[(1) - (3)].s));
         ;}
    break;

  case 284:
#line 1768 "compilers/imcc/imcc.y"
    { (yyval.sr) = 0; ;}
    break;

  case 285:
#line 1772 "compilers/imcc/imcc.y"
    { (yyval.i) = (yyvsp[(1) - (1)].i); ;}
    break;

  case 286:
#line 1773 "compilers/imcc/imcc.y"
    { (yyval.i) = (yyvsp[(1) - (1)].i); ;}
    break;

  case 287:
#line 1778 "compilers/imcc/imcc.y"
    {
           (yyval.i) =MK_I(interp, IMCC_INFO(interp)->cur_unit, inv_op((yyvsp[(3) - (6)].s)), 3, (yyvsp[(2) - (6)].sr), (yyvsp[(4) - (6)].sr), (yyvsp[(6) - (6)].sr));
         ;}
    break;

  case 288:
#line 1782 "compilers/imcc/imcc.y"
    {
           (yyval.i) = MK_I(interp, IMCC_INFO(interp)->cur_unit, "unless_null", 2, (yyvsp[(3) - (5)].sr), (yyvsp[(5) - (5)].sr));
         ;}
    break;

  case 289:
#line 1786 "compilers/imcc/imcc.y"
    {
           (yyval.i) = MK_I(interp, IMCC_INFO(interp)->cur_unit, "unless", 2, (yyvsp[(2) - (4)].sr), (yyvsp[(4) - (4)].sr));
         ;}
    break;

  case 290:
#line 1793 "compilers/imcc/imcc.y"
    {
           (yyval.i) = MK_I(interp, IMCC_INFO(interp)->cur_unit, "if", 2, (yyvsp[(2) - (4)].sr), (yyvsp[(4) - (4)].sr));
         ;}
    break;

  case 291:
#line 1797 "compilers/imcc/imcc.y"
    {
           (yyval.i) =MK_I(interp, IMCC_INFO(interp)->cur_unit, (yyvsp[(3) - (6)].s), 3, (yyvsp[(2) - (6)].sr), (yyvsp[(4) - (6)].sr), (yyvsp[(6) - (6)].sr));
         ;}
    break;

  case 292:
#line 1801 "compilers/imcc/imcc.y"
    {
           (yyval.i) = MK_I(interp, IMCC_INFO(interp)->cur_unit, "if_null", 2, (yyvsp[(3) - (5)].sr), (yyvsp[(5) - (5)].sr));
         ;}
    break;

  case 293:
#line 1807 "compilers/imcc/imcc.y"
    { (yyval.t) = 0; ;}
    break;

  case 294:
#line 1808 "compilers/imcc/imcc.y"
    { (yyval.t) = 0; ;}
    break;

  case 295:
#line 1812 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"eq"; ;}
    break;

  case 296:
#line 1813 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"ne"; ;}
    break;

  case 297:
#line 1814 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"gt"; ;}
    break;

  case 298:
#line 1815 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"ge"; ;}
    break;

  case 299:
#line 1816 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"lt"; ;}
    break;

  case 300:
#line 1817 "compilers/imcc/imcc.y"
    { (yyval.s) = (char *)"le"; ;}
    break;

  case 303:
#line 1826 "compilers/imcc/imcc.y"
    { (yyval.sr) = NULL; ;}
    break;

  case 304:
#line 1827 "compilers/imcc/imcc.y"
    { (yyval.sr) = (yyvsp[(1) - (1)].sr); ;}
    break;

  case 305:
#line 1831 "compilers/imcc/imcc.y"
    { (yyval.sr) = IMCC_INFO(interp)->regs[0]; ;}
    break;

  case 307:
#line 1836 "compilers/imcc/imcc.y"
    { IMCC_INFO(interp)->regs[IMCC_INFO(interp)->nargs++] = (yyvsp[(1) - (1)].sr); ;}
    break;

  case 308:
#line 1838 "compilers/imcc/imcc.y"
    {
           IMCC_INFO(interp) -> regs[IMCC_INFO(interp)->nargs++] = (yyvsp[(1) - (4)].sr);
           IMCC_INFO(interp) -> keyvec |= KEY_BIT(IMCC_INFO(interp)->nargs);
           IMCC_INFO(interp) -> regs[IMCC_INFO(interp)->nargs++] = (yyvsp[(3) - (4)].sr);
           (yyval.sr) = (yyvsp[(1) - (4)].sr);
         ;}
    break;

  case 309:
#line 1845 "compilers/imcc/imcc.y"
    {
           IMCC_INFO(interp) -> regs[IMCC_INFO(interp)->nargs++] = (yyvsp[(2) - (3)].sr);
           (yyval.sr) = (yyvsp[(2) - (3)].sr);
         ;}
    break;

  case 311:
#line 1852 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_sub_address_fromc(interp, (yyvsp[(1) - (1)].s)); mem_sys_free((yyvsp[(1) - (1)].s)); ;}
    break;

  case 312:
#line 1853 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_sub_address_u(interp, (yyvsp[(1) - (1)].s));  mem_sys_free((yyvsp[(1) - (1)].s)); ;}
    break;

  case 313:
#line 1857 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_sub_address(interp, (yyvsp[(1) - (1)].s)); mem_sys_free((yyvsp[(1) - (1)].s)); ;}
    break;

  case 314:
#line 1858 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_sub_address(interp, (yyvsp[(1) - (1)].s)); mem_sys_free((yyvsp[(1) - (1)].s)); ;}
    break;

  case 315:
#line 1862 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_label_address(interp, (yyvsp[(1) - (1)].s)); mem_sys_free((yyvsp[(1) - (1)].s)); ;}
    break;

  case 316:
#line 1863 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_label_address(interp, (yyvsp[(1) - (1)].s)); mem_sys_free((yyvsp[(1) - (1)].s)); ;}
    break;

  case 321:
#line 1877 "compilers/imcc/imcc.y"
    {
           IMCC_INFO(interp)->nkeys    = 0;
           IMCC_INFO(interp)->in_slice = 0;
         ;}
    break;

  case 322:
#line 1882 "compilers/imcc/imcc.y"
    {
           (yyval.sr) = link_keys(interp,
                          IMCC_INFO(interp)->nkeys,
                          IMCC_INFO(interp)->keys, 0);
         ;}
    break;

  case 323:
#line 1890 "compilers/imcc/imcc.y"
    {
           IMCC_INFO(interp)->nkeys = 0;
           IMCC_INFO(interp)->in_slice = 0;
         ;}
    break;

  case 324:
#line 1895 "compilers/imcc/imcc.y"
    {
           (yyval.sr) = link_keys(interp,
                          IMCC_INFO(interp)->nkeys,
                          IMCC_INFO(interp)->keys, 1);
         ;}
    break;

  case 325:
#line 1903 "compilers/imcc/imcc.y"
    { IMCC_INFO(interp)->keys[IMCC_INFO(interp)->nkeys++] = (yyvsp[(1) - (1)].sr); ;}
    break;

  case 326:
#line 1905 "compilers/imcc/imcc.y"
    {
           IMCC_INFO(interp)->keys[IMCC_INFO(interp)->nkeys++] = (yyvsp[(3) - (3)].sr);
           (yyval.sr) = IMCC_INFO(interp)->keys[0];
         ;}
    break;

  case 327:
#line 1909 "compilers/imcc/imcc.y"
    { IMCC_INFO(interp)->in_slice = 1; ;}
    break;

  case 328:
#line 1911 "compilers/imcc/imcc.y"
    {
           IMCC_INFO(interp)->keys[IMCC_INFO(interp)->nkeys++] = (yyvsp[(4) - (4)].sr);
           (yyval.sr) = IMCC_INFO(interp)->keys[0];
         ;}
    break;

  case 329:
#line 1919 "compilers/imcc/imcc.y"
    {
           if (IMCC_INFO(interp)->in_slice)
               (yyvsp[(1) - (1)].sr)->type |= VT_START_SLICE | VT_END_SLICE;
           (yyval.sr) = (yyvsp[(1) - (1)].sr);
         ;}
    break;

  case 330:
#line 1925 "compilers/imcc/imcc.y"
    {
           (yyvsp[(1) - (3)].sr)->type |= VT_START_SLICE;
           (yyvsp[(3) - (3)].sr)->type |= VT_END_SLICE;
           IMCC_INFO(interp)->keys[IMCC_INFO(interp)->nkeys++] = (yyvsp[(1) - (3)].sr);
           (yyval.sr) = (yyvsp[(3) - (3)].sr);
         ;}
    break;

  case 331:
#line 1931 "compilers/imcc/imcc.y"
    { (yyvsp[(2) - (2)].sr)->type |= VT_START_ZERO | VT_END_SLICE; (yyval.sr) = (yyvsp[(2) - (2)].sr); ;}
    break;

  case 332:
#line 1932 "compilers/imcc/imcc.y"
    { (yyvsp[(1) - (2)].sr)->type |= VT_START_SLICE | VT_END_INF; (yyval.sr) = (yyvsp[(1) - (2)].sr); ;}
    break;

  case 333:
#line 1936 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_symreg(interp, (yyvsp[(1) - (1)].s), 'I'); ;}
    break;

  case 334:
#line 1937 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_symreg(interp, (yyvsp[(1) - (1)].s), 'N'); ;}
    break;

  case 335:
#line 1938 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_symreg(interp, (yyvsp[(1) - (1)].s), 'S'); ;}
    break;

  case 336:
#line 1939 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_symreg(interp, (yyvsp[(1) - (1)].s), 'P'); ;}
    break;

  case 337:
#line 1940 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_pasm_reg(interp, (yyvsp[(1) - (1)].s)); mem_sys_free((yyvsp[(1) - (1)].s)); ;}
    break;

  case 338:
#line 1944 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_const(interp, (yyvsp[(1) - (1)].s), 'I'); mem_sys_free((yyvsp[(1) - (1)].s)); ;}
    break;

  case 339:
#line 1945 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_const(interp, (yyvsp[(1) - (1)].s), 'N'); mem_sys_free((yyvsp[(1) - (1)].s)); ;}
    break;

  case 340:
#line 1946 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_const(interp, (yyvsp[(1) - (1)].s), 'S'); mem_sys_free((yyvsp[(1) - (1)].s)); ;}
    break;

  case 341:
#line 1947 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_const(interp, (yyvsp[(1) - (1)].s), 'U'); mem_sys_free((yyvsp[(1) - (1)].s)); ;}
    break;

  case 342:
#line 1951 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_symreg(interp, (yyvsp[(1) - (1)].s), 'S'); mem_sys_free((yyvsp[(1) - (1)].s)); ;}
    break;

  case 343:
#line 1952 "compilers/imcc/imcc.y"
    { (yyval.sr) = mk_const(interp, (yyvsp[(1) - (1)].s), 'S');  mem_sys_free((yyvsp[(1) - (1)].s)); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 4767 "compilers/imcc/imcparser.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (yyscanner, interp, YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yyscanner, interp, yymsg);
	  }
	else
	  {
	    yyerror (yyscanner, interp, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, yyscanner, interp);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yyscanner, interp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (yyscanner, interp, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, yyscanner, interp);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yyscanner, interp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1957 "compilers/imcc/imcc.y"


/* I need this prototype somewhere... */
char *yyget_text(yyscan_t yyscanner);

/* I do not like this function, but, atm, it is the only way I can
 * make the code in yyerror work without segfault on some specific
 * cases.
 */
/* int yyholds_char(yyscan_t yyscanner); */

int yyerror(void *yyscanner, PARROT_INTERP, const char *s)
{
    /* If the error occurr in the end of the buffer (I mean, the last
     * token was already read), yyget_text will return a pointer
     * outside the bison buffer, and thus, not "accessible" by
     * us. This means it may segfault. */
    const char * const chr = yyget_text((yyscan_t)yyscanner);

    /* IMCC_fataly(interp, EXCEPTION_SYNTAX_ERROR, s); */
    /* --- This was called before, not sure if I should call some
           similar function that does not die like this one. */

    /* Basically, if current token is a newline, it mean the error was
     * before the newline, and thus, line is the line *after* the
     * error. Instead of duplicating code for both cases (the 'newline' and
     * non-newline case, do the test twice; efficiency is not important when
     * we have an error anyway.
     */
    if (!at_eof(yyscanner)) {
        if (*chr == '\n') {
            IMCC_INFO(interp)->line--;
        }

        IMCC_warning(interp, "error:imcc:%s", s);
        /* don't print the current token if it is a newline */
        if (*chr != '\n') {
            IMCC_warning(interp, " ('%s')", chr);
        }
        IMCC_print_inc(interp);

        if (*chr == '\n') {
            IMCC_INFO(interp)->line++;
        }

    }
    else { /* scanner is at end of file; just to be sure, do not print "current" token. */
        IMCC_warning(interp, "error:imcc:%s", s);
        IMCC_print_inc(interp);
    }

    return 0;
}

/*
 * Local variables:
 *   c-file-style: "parrot"
 * End:
 * vim: expandtab shiftwidth=4:
 */

