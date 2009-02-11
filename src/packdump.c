/*
Copyright (C) 2001-2008, The Perl Foundation.
This program is free software. It is subject to the same license as
Parrot itself.
$Id$

=head1 NAME

src/packdump.c - Functions for dumping packfile structures

=head1 DESCRIPTION

This is only used by the PBC dumper C<pbc_dump>.

=head2 Functions

=over 4

=cut

*/

#include "parrot/parrot.h"
#include "parrot/packfile.h"

/* HEADERIZER HFILE: include/parrot/packfile.h */

/* HEADERIZER BEGIN: static */
/* Don't modify between HEADERIZER BEGIN / HEADERIZER END.  Your changes will be lost. */

static void PackFile_Constant_dump(PARROT_INTERP,
    ARGIN(const PackFile_ConstTable *ct),
    ARGIN(const PackFile_Constant *self))
        __attribute__nonnull__(1)
        __attribute__nonnull__(2)
        __attribute__nonnull__(3);

static void pobj_flag_dump(PARROT_INTERP, ARGIN_NULLOK(long flags))
        __attribute__nonnull__(1);

#define ASSERT_ARGS_PackFile_Constant_dump __attribute__unused__ int _ASSERT_ARGS_CHECK = \
       PARROT_ASSERT_ARG(interp) \
    || PARROT_ASSERT_ARG(ct) \
    || PARROT_ASSERT_ARG(self)
#define ASSERT_ARGS_pobj_flag_dump __attribute__unused__ int _ASSERT_ARGS_CHECK = \
       PARROT_ASSERT_ARG(interp)
/* Don't modify between HEADERIZER BEGIN / HEADERIZER END.  Your changes will be lost. */
/* HEADERIZER END: static */


/*

=item C<void PackFile_ConstTable_dump>

Dumps the constant table C<self>.

=cut

*/

PARROT_EXPORT
void
PackFile_ConstTable_dump(PARROT_INTERP, ARGIN(const PackFile_ConstTable *self))
{
    ASSERT_ARGS(PackFile_ConstTable_dump)
    opcode_t i;

    for (i = 0; i < self->const_count; i++) {
        Parrot_io_printf(interp, "    # %ld:\n", (long)i);
        PackFile_Constant_dump(interp, self, self->constants[i]);
    }
}

/*

=item C<static void PackFile_Constant_dump>

Dumps the constant C<self>.

=cut

*/

/* [this desperately needs better abstraction, so we're not duplicating the enum
 * PObj_enum definition in the include/parrot/pobj.h file.  -- rgr, 1-Mar-08.]
 */
static const char *flag_bit_names[] =
{
    "private0",
    "private1",
    "private2",
    "private3",
    "private4",
    "private5",
    "private6",
    "private7",
    "is_string",
    "is_PMC",
    "is_PMC_EXT",
    "is_shared",
    "constant",
    "external",
    "aligned",
    "sysmem",
    "COW",
    "is_COWable",
    "live",
    "on_free_list",
    "custom_mark",
    "custom_GC",
    "active_destroy",
    "report",
    "data_is_PMC_array",
    "need_finalize",
    "is_special_PMC",
    "high_priority_DOD",
    "needs_early_gc",
    "is_class",
    "is_object"
};

/* Given a word of flags, generate a dump line of the whole word in hex,
 * followed by individual bits.
 */
static void
pobj_flag_dump(PARROT_INTERP, ARGIN_NULLOK(long flags))
{
    ASSERT_ARGS(pobj_flag_dump)
    INTVAL idx = 0;
    int printed_flag_p = 0;

    Parrot_io_printf(interp, "\tFLAGS => 0x%04lx (", flags);
    while (flags) {
        if (flags & 1) {
            if (printed_flag_p)
                Parrot_io_printf(interp, ",");
            Parrot_io_printf(interp, "%s", flag_bit_names[idx]);
            printed_flag_p++;
        }
        idx++;
        flags >>= 1;
    }
    Parrot_io_printf(interp, ")\n");
}

static void
PackFile_Constant_dump(PARROT_INTERP, ARGIN(const PackFile_ConstTable *ct),
                       ARGIN(const PackFile_Constant *self))
{
    ASSERT_ARGS(PackFile_Constant_dump)
    PMC *key;
    size_t i;

    switch (self->type) {

    case PFC_NUMBER:
        Parrot_io_printf(interp, "    [ 'PFC_NUMBER', %g ],\n", self->u.number);
        break;

    case PFC_STRING:
        Parrot_io_printf(interp, "    [ 'PFC_STRING', {\n");
        pobj_flag_dump(interp, (long)PObj_get_FLAGS(self->u.string));
        Parrot_io_printf(interp, "        CHARSET  => %ld,\n",
                   self->u.string->charset);
        i = self->u.string->bufused;
        Parrot_io_printf(interp, "        SIZE     => %ld,\n",
                   (long)i);

        Parrot_io_printf(interp, "        DATA     => \"%Ss\"\n",
                       Parrot_str_escape(interp, self->u.string));
        Parrot_io_printf(interp, "    } ],\n");
        break;

    case PFC_KEY:
        for (i = 0, key = self->u.key; key; key = (PMC*)PMC_data(key), i++)
            ;
        /* number of key components */
        Parrot_io_printf(interp, "    [ 'PFC_KEY' (%ld items)\n", i);
        /* and now type / value per component */
        for (key = self->u.key; key; key = (PMC*)PMC_data(key)) {
            opcode_t type = PObj_get_FLAGS(key);

            Parrot_io_printf(interp, "       {\n");
            if ((type & (KEY_start_slice_FLAG|KEY_inf_slice_FLAG)) ==
                (KEY_start_slice_FLAG|KEY_inf_slice_FLAG))
                Parrot_io_printf(interp, "        SLICE_BITS  => PF_VT_END_INF\n");
            if ((type & (KEY_end_slice_FLAG|KEY_inf_slice_FLAG)) ==
                (KEY_end_slice_FLAG|KEY_inf_slice_FLAG))
                Parrot_io_printf(interp, "        SLICE_BITS  => PF_VT_START_ZERO\n");
            if (type & KEY_start_slice_FLAG)
                Parrot_io_printf(interp, "        SLICE_BITS  => PF_VT_START_SLICE\n");
            if (type & KEY_end_slice_FLAG)
                Parrot_io_printf(interp, "        SLICE_BITS  => PF_VT_END_SLICE\n");

            type &= KEY_type_FLAGS;
            pobj_flag_dump(interp, (long)PObj_get_FLAGS(key));
            switch (type) {
                case KEY_integer_FLAG:
                    Parrot_io_printf(interp, "        TYPE        => INTEGER\n");
                    Parrot_io_printf(interp, "        DATA        => %ld\n", PMC_int_val(key));
                    Parrot_io_printf(interp, "       },\n");
                    break;
                case KEY_number_FLAG:
                    {
                    const PackFile_Constant *detail;
                    size_t ct_index;

                    Parrot_io_printf(interp, "        TYPE        => NUMBER\n");
                    ct_index = PackFile_find_in_const(interp, ct, key, PFC_NUMBER);
                    Parrot_io_printf(interp, "        PFC_OFFSET  => %ld\n", ct_index);
                    detail = ct->constants[ct_index];
                    Parrot_io_printf(interp, "        DATA        => %ld\n", detail->u.number);
                    Parrot_io_printf(interp, "       },\n");
                    }
                    break;
                case KEY_string_FLAG:
                    {
                    const PackFile_Constant *detail;
                    size_t ct_index;

                    Parrot_io_printf(interp, "        TYPE        => STRING\n");
                    ct_index = PackFile_find_in_const(interp, ct, key, PFC_STRING);
                    Parrot_io_printf(interp, "        PFC_OFFSET  => %ld\n", ct_index);
                    detail = ct->constants[ct_index];
                    Parrot_io_printf(interp, "        DATA        => '%.*s'\n",
                              (int)detail->u.string->bufused,
                              (char *)detail->u.string->strstart);
                    Parrot_io_printf(interp, "       },\n");
                    }
                    break;
                case KEY_integer_FLAG | KEY_register_FLAG:
                    Parrot_io_printf(interp, "        TYPE        => I REGISTER\n");
                    Parrot_io_printf(interp, "        DATA        => %ld\n", PMC_int_val(key));
                    Parrot_io_printf(interp, "       },\n");
                    break;
                case KEY_number_FLAG | KEY_register_FLAG:
                    Parrot_io_printf(interp, "        TYPE        => N REGISTER\n");
                    Parrot_io_printf(interp, "        DATA        => %ld\n", PMC_int_val(key));
                    Parrot_io_printf(interp, "       },\n");
                    break;
                case KEY_string_FLAG | KEY_register_FLAG:
                    Parrot_io_printf(interp, "        TYPE        => S REGISTER\n");
                    Parrot_io_printf(interp, "        DATA        => %ld\n", PMC_int_val(key));
                    Parrot_io_printf(interp, "       },\n");
                    break;
                case KEY_pmc_FLAG | KEY_register_FLAG:
                    Parrot_io_printf(interp, "        TYPE        => P REGISTER\n");
                    Parrot_io_printf(interp, "        DATA        => %ld\n", PMC_int_val(key));
                    Parrot_io_printf(interp, "       },\n");
                    break;
                default:
                    Parrot_io_eprintf(NULL, "PackFile_Constant_pack: "
                            "unsupported constant type\n");
                    Parrot_exit(interp, 1);
            }
        }
        Parrot_io_printf(interp, "    ],\n");
        break;
    case PFC_PMC:
        Parrot_io_printf(interp, "    [ 'PFC_PMC', {\n");
        {
            PMC * const pmc = self->u.key;
            Parrot_sub *sub;
            STRING * const null = Parrot_str_new_constant(interp, "(null)");
            STRING *namespace_description;

            pobj_flag_dump(interp, (long)PObj_get_FLAGS(pmc));
            switch (pmc->vtable->base_type) {
                case enum_class_FixedBooleanArray:
                case enum_class_FixedFloatArray:
                case enum_class_FixedPMCArray:
                case enum_class_FixedStringArray:
                case enum_class_ResizableBooleanArray:
                case enum_class_ResizableIntegerArray:
                case enum_class_ResizableFloatArray:
                case enum_class_ResizablePMCArray:
                case enum_class_ResizableStringArray:
                    {
                    const int n = VTABLE_get_integer(interp, pmc);
                    STRING* const out_buffer = VTABLE_get_repr(interp, pmc);
                    Parrot_io_printf(interp,
                            "\tclass => %Ss,\n"
                            "\telement count => %d,\n"
                            "\telements => %Ss,\n",
                            pmc->vtable->whoami,
                            n,
                            out_buffer);
                    }
                    break;
                case enum_class_Sub:
                case enum_class_Closure:
                case enum_class_Coroutine:
                    sub = PMC_sub(pmc);
                    if (sub->namespace_name) {
                        switch (sub->namespace_name->vtable->base_type) {
                            case enum_class_String:
                                namespace_description = Parrot_str_new(interp, "'", 1);
                                namespace_description = Parrot_str_append(interp,
                                        namespace_description,
                                        PMC_str_val(sub->namespace_name));
                                namespace_description = Parrot_str_append(interp,
                                        namespace_description,
                                        Parrot_str_new(interp, "'", 1));
                                break;
                            case enum_class_Key:
                                namespace_description =
                                    key_set_to_string(interp, sub->namespace_name);
                                break;
                            default:
                                namespace_description = sub->namespace_name->vtable->whoami;
                        }
                    }
                    else {
                        namespace_description = null;
                    }
                    Parrot_io_printf(interp,
                            "\tclass => %Ss,\n"
                            "\tstart_offs => %d,\n"
                            "\tend_offs => %d,\n"
                            "\tname    => '%Ss',\n"
                            "\tsubid   => '%Ss',\n"
                            "\tmethod  => '%Ss',\n"
                            "\tnsentry => '%Ss',\n"
                            "\tnamespace => %Ss\n"
                            "\tHLL_id => %d,\n",
                            pmc->vtable->whoami,
                            sub->start_offs,
                            sub->end_offs,
                            sub->name,
                            sub->subid,
                            sub->method_name,
                            sub->ns_entry_name,
                            namespace_description,
                            sub->HLL_id);
                    break;
                case enum_class_FixedIntegerArray:
                    Parrot_io_printf(interp,
                            "\tclass => %Ss,\n"
                            "\trepr => '%Ss'\n",
                            pmc->vtable->whoami,
                            VTABLE_get_repr(interp, pmc));
                    break;
                default:
                    Parrot_io_printf(interp, "\tno dump info for PMC %ld %Ss\n",
                            pmc->vtable->base_type, pmc->vtable->whoami);
                    Parrot_io_printf(interp, "\tclass => %Ss,\n", pmc->vtable->whoami);
            }
        }
        Parrot_io_printf(interp, "    } ],\n");
        break;
    default:
        Parrot_io_printf(interp, "    [ 'PFC_\?\?\?', type '0x%x' ],\n",
                self->type);
        break;
    }
}

/*

=item C<void PackFile_Fixup_dump>

Dumps the fix-up table C<ft>.

=cut

*/

PARROT_EXPORT
void
PackFile_Fixup_dump(PARROT_INTERP, ARGIN(const PackFile_FixupTable *ft))
{
    ASSERT_ARGS(PackFile_Fixup_dump)
    opcode_t i;

    for (i = 0; i < ft->fixup_count; i++) {
        Parrot_io_printf(interp, "\t#%d\n", (int) i);
        switch (ft->fixups[i]->type) {
            case enum_fixup_label:
            case enum_fixup_sub:
                Parrot_io_printf(interp,
                        "\ttype => %d offs => %8d name => '%s',\n",
                        (int)ft->fixups[i]->type,
                        (int)ft->fixups[i]->offset,
                        ft->fixups[i]->name);
                    break;
            default:
                Parrot_io_printf(interp, "\ttype => %d ???,\n",
                        (int) ft->fixups[i]->type);
                break;
        }
    }
}

/*

=back

=head1 SEE ALSO

F<src/pbc_dump.c>.

=cut

*/


/*
 * Local variables:
 *   c-file-style: "parrot"
 * End:
 * vim: expandtab shiftwidth=4:
 */
