/* register.h
 *  Copyright: (When this is determined...it will go here)
 *  CVS Info
 *     $Id$
 *  Overview:
 *     Defines the resource allocation API
 *  Data Structure and Algorithms:
 *  History:
 *  Notes:
 *  References:
 */

#if !defined(PARROT_RESOURCES_H_GUARD)
#define PARROT_RESOURCES_H_GUARD

#include "parrot/parrot.h"

PMC *new_pmc_header(struct Parrot_Interp *);
void free_pmc(PMC *);

STRING *new_string_header(struct Parrot_Interp *);
void free_string(STRING *);

Buffer *new_tracked_header(struct Parrot_Interp *, UINTVAL size);
void free_tracked(Buffer *);

void *new_bigint_header(struct Parrot_Interp *);
void free_bigint(void);

void *new_bignum_header(struct Parrot_Interp *);
void free_bignum(void);

void *Parrot_allocate(struct Parrot_Interp *, UINTVAL size);
void Parrot_alloc_new_block(struct Parrot_Interp *, UINTVAL size);

void buffer_lives(Buffer *);

struct PMC_Arena {
    UINTVAL free;         /* Count of PMCs free in this arena */
    UINTVAL used;         /* Count of PMCs used in this arena */
    struct PMC_Arena *prev;
    struct PMC_Arena *next;
    PMC *next_PMC;        /* Next PMC in the arena ready to allocate */
    UINTVAL *GC_data;     /* Actually an array with one element per PMC */
};

struct STRING_Arena {
    UINTVAL free;
    UINTVAL used;
    struct STRING_Arena *prev;
    struct STRING_Arena *next;
    STRING *next_STRING;
};

struct Memory_Pool {
    UINTVAL free;
    UINTVAL size;
    struct Memory_Pool *prev;
    struct Memory_Pool *next;
    char *start;
    char *top;
};

struct Arenas {
    struct PMC_Arena *last_PMC_Arena;
    struct STRING_Arena *last_STRING_Arena;
    struct Memory_Pool *memory_pool;
    UINTVAL collections;
};

struct Stash {
    struct PMC *stash_hash;
    struct Stash *parent_stash;
};


#endif /* PARROT_RESOURCES_H */

/*
 * Local variables:
 * c-indentation-style: bsd
 * c-basic-offset: 4
 * indent-tabs-mode: nil 
 * End:
 *
 * vim: expandtab shiftwidth=4:
*/
