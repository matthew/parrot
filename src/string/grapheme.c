/*
Copyright (C) 2010, Parrot Foundation.
$Id$
*/

#include "parrot/parrot.h"
#include "grapheme.h"

/* HEADERIZER HFILE: src/string/grapheme.h */

/* HEADERIZER BEGIN: static */
/* HEADERIZER END: static */


#if PARROT_HAS_ICU

grapheme_table *
create_grapheme_table(PARROT_INTERP, UINTVAL n)
{
    ASSERT_ARGS(create_grapheme_table)
    UINTVAL entries = (n > MIN_TABLE_LENGTH) ? n - MIN_TABLE_LENGTH : 0;
    grapheme_table *table = mem_sys_allocate(sizeof (grapheme_table)
                                              + entries * sizeof (grapheme));
    table->size = entries + MIN_TABLE_LENGTH;
    table->used = 0;

    return table;
}

grapheme_table *
clone_grapheme_table(PARROT_INTERP, grapheme_table *src)
{
    ASSERT_ARGS(clone_grapheme_table)
    UINTVAL i;
    grapheme_table * dst = create_grapheme_table(interp, src->used);

    dst->used = src->used;

    for (i = 0; i < src->used; i++) {
        dst->graphemes[i].len =  src->graphemes[i].len;
        dst->graphemes[i].hash = src->graphemes[i].hash;
        dst->graphemes[i].codepoints = mem_gc_allocate_n_typed(interp, src->graphemes[i].len, UChar32);
        memcpy(dst->graphemes[i].codepoints, src->graphemes[i].codepoints, 
               src->graphemes[i].len * sizeof (UChar32));
    }

    return dst;
}

void
destroy_grapheme_table(PARROT_INTERP, grapheme_table *table)
{
    ASSERT_ARGS(destroy_grapheme_table)
    UINTVAL i = 0;
    while (i < table->used) {
        mem_gc_free(interp, table->graphemes[i++].codepoints);
    }
    mem_gc_free(interp, table);
}

UChar32 *
add_grapheme_from_substr(PARROT_INTERP, grapheme_table *table, STRING *src,
                         UINTVAL start, UINTVAL len, UINTVAL hash)
{
    ASSERT_ARGS(add_grapheme_from_substr)
    int32_t i;
    /* Check if it's in the table already... */
    for (i = 0; i < table->used; i++) {
        if (table->graphemes[i].hash == hash)
            return (UChar32) (-1 * (i + 1));
    }

    /* ... and add it if it isn't */
    table->graphemes[table->used].len = len;
    table->graphemes[table->used].hash = hash;
    table->graphemes[table->used].codepoints  = mem_gc_allocate_n_typed(interp, len, UChar32);
    for (i = 0; i < len; i++){
        table->graphemes[table->used].codepoints[i] =
            src->encoding->get_codepoint(interp, src, start + i);
    };
}

#endif /* PARROT_HAS_ICU */

/*
 * Local variables:
 *   c-file-style: "parrot"
 * End:
 * vim: expandtab shiftwidth=4:
 */
