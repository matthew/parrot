/*
Copyright (C) 2001-2007, Parrot Foundation.
$Id$

=head1 NAME

src/nci_test.c - shared library used for testing the Native Call Interface

=head1 DESCRIPTION

From this code a shared library can be compiled and linked with a command like:

   cc -shared -fpic nci_test.c -o libnci_test.so -g

For non-Unix platforms the above command has to be modified appropriately.

The resulting shared library should be copied to a location like:

   parrot/runtime/parrot/dynext/libnci_test.so

At that location the shared library is loadable with the opcode 'loadlib'.
The functions in the library are available with the opcode 'dlfunc'.
The variables in the library are available with the opcode 'dlvar'.

=head2 Functions

The name of a test function is usually 'nci_<signature>'. E.g. the function
'nci_ip' takes a 'pointer' and returns a 'int'.

=over 4

=cut

*/

#define PARROT_IN_EXTENSION
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <parrot/parrot.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Declarations of structs */

typedef struct Nested {
    int y;
} Nested;

typedef struct Outer {
    int x;
    Nested *nested;
} Outer;

typedef struct Rect_Like {
    int x, y;
    int w, h;
} Rect_Like;

typedef struct Opaque {
    int x;
} Opaque;

/* Function declarations.

*** If you add a new test function here,
*** please update src/libnci_test.def and src/call_list.txt too. ***

*/

PARROT_DYNEXT_EXPORT int    call_back(const char *str);
PARROT_DYNEXT_EXPORT char   nci_c(void);
PARROT_DYNEXT_EXPORT char   nci_csc(short, char);
PARROT_DYNEXT_EXPORT double nci_d(void);
PARROT_DYNEXT_EXPORT double nci_dd(double);
PARROT_DYNEXT_EXPORT float  nci_f(void);
PARROT_DYNEXT_EXPORT float  nci_fff(float, float);
PARROT_DYNEXT_EXPORT int    nci_i(void);
PARROT_DYNEXT_EXPORT int    nci_ib(int *);
PARROT_DYNEXT_EXPORT int    nci_iiii(int, int, int);
PARROT_DYNEXT_EXPORT int    nci_ii3(int, int *);
PARROT_DYNEXT_EXPORT int    nci_ip(void *);
PARROT_DYNEXT_EXPORT int    nci_isc(short, char);
PARROT_DYNEXT_EXPORT int    nci_it(void *);
PARROT_DYNEXT_EXPORT int    nci_i33(int *, int *);
PARROT_DYNEXT_EXPORT int    nci_i4i(long *, int);
PARROT_DYNEXT_EXPORT long   nci_l(void);
PARROT_DYNEXT_EXPORT int *  nci_p(void);
PARROT_DYNEXT_EXPORT void * nci_pi(int);
PARROT_DYNEXT_EXPORT void * nci_pii(int, int);
PARROT_DYNEXT_EXPORT void * nci_piiii(int, int, int, int);
PARROT_DYNEXT_EXPORT void   nci_pip(int, Rect_Like *);
PARROT_DYNEXT_EXPORT void * nci_pp(void *);
PARROT_DYNEXT_EXPORT short  nci_s(void);
PARROT_DYNEXT_EXPORT short  nci_ssc(short, char);
PARROT_DYNEXT_EXPORT char * nci_t(void);
PARROT_DYNEXT_EXPORT char * nci_tb(void *);
PARROT_DYNEXT_EXPORT char * nci_tB(void **);
PARROT_DYNEXT_EXPORT char * nci_tt(void *);
PARROT_DYNEXT_EXPORT void   nci_v(void);
PARROT_DYNEXT_EXPORT void   nci_vP(void *);
PARROT_DYNEXT_EXPORT void   nci_vpii(Outer *, int, int);
PARROT_DYNEXT_EXPORT void   nci_vv(void);
PARROT_DYNEXT_EXPORT void   nci_vVi(Opaque**, int);
PARROT_DYNEXT_EXPORT void   nci_vp(Opaque*);
PARROT_DYNEXT_EXPORT char * nci_ttt(char *, char *);
PARROT_DYNEXT_EXPORT void   nci_vfff(float, float, float);
PARROT_DYNEXT_EXPORT void   nci_vV(const char **);
PARROT_DYNEXT_EXPORT void   nci_vVVV(const char **, const char **, const char **);
PARROT_DYNEXT_EXPORT int    nci_i20(int, int, int, int, int, int, int, int, int, int, int, int, int, int,
                             int, int, int, int, int);

/* Declarations for callback tests */

typedef void (*cb_C1_func)(const char*, void*);
PARROT_DYNEXT_EXPORT void nci_cb_C1(cb_C1_func, void*);

typedef void (*cb_C2_func)(int, void*);
PARROT_DYNEXT_EXPORT void nci_cb_C2(cb_C2_func, void*);

typedef void (*cb_C3_func)(void*, void*);
PARROT_DYNEXT_EXPORT void nci_cb_C3(cb_C3_func, void*);

typedef void (*cb_D1_func)(void*, const char*);
PARROT_DYNEXT_EXPORT void nci_cb_D1(cb_D1_func, void*);

typedef void (*cb_D2_func)(void*, int);
PARROT_DYNEXT_EXPORT void nci_cb_D2(cb_D2_func, void*);

typedef void (*cb_D3_func)(void*, void*);
PARROT_DYNEXT_EXPORT void nci_cb_D3(cb_D3_func, void*);

typedef void (*cb_D4_func)(void*, void*);
PARROT_DYNEXT_EXPORT void nci_cb_D4(cb_D4_func, void*);

/* Variable definitions */

PARROT_DYNEXT_EXPORT int    int_cb_D4           = -55555;
PARROT_DYNEXT_EXPORT int    nci_dlvar_char      = 22;
PARROT_DYNEXT_EXPORT int    nci_dlvar_short     = 333;
PARROT_DYNEXT_EXPORT int    nci_dlvar_int       = -4444;
PARROT_DYNEXT_EXPORT long   nci_dlvar_long      = -7777777;
PARROT_DYNEXT_EXPORT float  nci_dlvar_float     = -333.0;
PARROT_DYNEXT_EXPORT double nci_dlvar_double    = -55555.55555;
PARROT_DYNEXT_EXPORT char   nci_dlvar_cstring[] = "This is a C-string.\n";


/* Function definitions */

/*

=item C<PARROT_DYNEXT_EXPORT char
nci_c(void)>

Returns the value of the variable C<nci_dlvar_char>, which is set to 22 by
default.

=cut

*/

PARROT_DYNEXT_EXPORT char
nci_c(void) {
    return nci_dlvar_char;
}

/*

=item C<PARROT_DYNEXT_EXPORT char
nci_csc(short l1, char l2)>

Multiplies C<l1> and C<l2> together and returns the first byte of the result.

=cut

*/

PARROT_DYNEXT_EXPORT char
nci_csc(short l1, char l2)
{
    return l1 * l2;
}

/*

=item C<PARROT_DYNEXT_EXPORT double
nci_d(void)>

Multiplies the current value of C<nci_dlvar_double> by 10.0, and returns
the new value.

=cut

*/

PARROT_DYNEXT_EXPORT double
nci_d(void)
{
    nci_dlvar_double *= 10.0;

    return nci_dlvar_double;
}

/*

=item C<PARROT_DYNEXT_EXPORT double
nci_dd(double d)>

Returns the value C<d> multiplied by 2.0.

=cut

*/

PARROT_DYNEXT_EXPORT double
nci_dd(double d)
{
    return d * 2.0;
}

/*

=item C<PARROT_DYNEXT_EXPORT float
nci_f(void)>

Multiplies the value C<nci_dlvar_float> by 10.0 and returns the new
value.

=cut

*/

PARROT_DYNEXT_EXPORT float
nci_f(void)
{
    nci_dlvar_float *= 10.0;

    return nci_dlvar_float;
}

/*

=item C<PARROT_DYNEXT_EXPORT float
nci_fff(float l1, float l2)>

Returns the result of C<l1> / C<l2>.

=cut

*/

PARROT_DYNEXT_EXPORT float
nci_fff(float l1, float l2)
{
    return l1 / l2;
}

/*

=item C<PARROT_DYNEXT_EXPORT int
nci_i(void)>

Returns the current value of <nci_dlvar_int>.

=cut

*/

PARROT_DYNEXT_EXPORT int
nci_i(void)
{
   return nci_dlvar_int;
}

/*

=item C<PARROT_DYNEXT_EXPORT int
nci_isc(short l1, char l2)>

Returns the int product of C<l1 * l2>.

=cut

*/

PARROT_DYNEXT_EXPORT int
nci_isc(short l1, char l2)
{
    return l1 * l2;
}

/*

=item C<PARROT_DYNEXT_EXPORT int
nci_ip(void *p)>

Performs a series of operations on values stored at pointer C<p>.

=cut

*/

PARROT_DYNEXT_EXPORT int
nci_ip(void *p)
{
    typedef struct _dfi {
        double d;
        float f;
        int i;
        char *s;
    } dfi;
    dfi *sp = (dfi*) p;
    puts(sp->s);
    fflush(stdout);

    return (int) (sp->d + sp->f + sp->i);
}

/*

=item C<PARROT_DYNEXT_EXPORT int
nci_it(void *p)>

test calls this with a string

=cut

*/

PARROT_DYNEXT_EXPORT int
nci_it(void *p)
{
    fprintf(stderr, "%c%c\n", ((char*) p)[1], ((char *) p)[0]);
    fflush(stderr);

    return 2;
}

/*

=item C<PARROT_DYNEXT_EXPORT long
nci_l(void)>

Returns the value of C<nci_dlvar_long>.

=cut

*/

PARROT_DYNEXT_EXPORT long
nci_l(void)
{
    return nci_dlvar_long;
}

/*

=item C<PARROT_DYNEXT_EXPORT int *
nci_p(void)>

Returns the address of C<nci_dlvar_int>.

=cut

*/

PARROT_DYNEXT_EXPORT int *
nci_p(void)
{
    return &nci_dlvar_int;
}

/*

=item C<PARROT_DYNEXT_EXPORT char *
nci_t(void)>

Returns the value of C<nci_dlvar_cstring>.

=cut

*/

PARROT_DYNEXT_EXPORT char *
nci_t(void)
{
    return nci_dlvar_cstring;
}

/*

=item C<PARROT_DYNEXT_EXPORT char *
nci_tb(void *p)>

Prints "xx worked", where "xx" is replaced with the first two character values
of C<p>, in reverse order.

=cut

*/

static char b[] = "xx worked\n";

PARROT_DYNEXT_EXPORT char *
nci_tb(void *p)
{
    b[0] = ((char*) p)[1];
    b[1] = ((char*) p)[0];

    return b;
}

/*

=item C<PARROT_DYNEXT_EXPORT char *
nci_tt(void *p)>

Prints "xx worked", where "xx" is replaced with the first two character values
of C<p>, in reverse order.

=cut

*/

static char s[] = "xx worked\n";

PARROT_DYNEXT_EXPORT char *
nci_tt(void *p)
{
    s[0] = ((char*) p)[1];
    s[1] = ((char*) p)[0];

    return s;
}

/*

=item C<PARROT_DYNEXT_EXPORT char *
nci_tB(void **p)>

Prints "xx done", where "xx" is replaced with the first two character values
of C<p>, in reverse order.

=cut

*/

static char B[] = "xx done\n";

PARROT_DYNEXT_EXPORT char *
nci_tB(void **p)
{
    B[0] = (*(char**) p)[1];
    B[1] = (*(char**) p)[0];

    return B;
}

/*

=item C<PARROT_DYNEXT_EXPORT void *
nci_pp(void *p)>

Returns the value C<p> directly.

=cut

*/

PARROT_DYNEXT_EXPORT void *
nci_pp(void *p)
{
    return p;
}

/*

=item C<PARROT_DYNEXT_EXPORT int
nci_iiii(int i1, int i2, int i3)>

Prints three integers separated by whitespace to C<stderr>.

=cut

*/

PARROT_DYNEXT_EXPORT int
nci_iiii(int i1, int i2, int i3)
{
    fprintf(stderr, "%d %d %d\n", i1, i2, i3);
    fflush(stderr);

    return 2;
}

/*

=item C<PARROT_DYNEXT_EXPORT int
nci_i4i(long * l, int i)>

Returns the product of C<*l> and C<i>, as an int.

=cut

*/

PARROT_DYNEXT_EXPORT int
nci_i4i(long * l, int i)
{

    return (int) (*l * i);
}

/*

=item C<PARROT_DYNEXT_EXPORT int
nci_ii3(int a, int *bp)>

Multiplies C<a> and C<*bp> together and returns the result. Updates C<*bp>
to the value  4711.

=cut

*/

PARROT_DYNEXT_EXPORT int
nci_ii3(int a, int *bp)
{
    int r = a * *bp;
    *bp = 4711;

    return r;
}

/*

=item C<PARROT_DYNEXT_EXPORT int
call_back(const char *str)>

writes the string C<str> to stdout and returns the value 4711.

=cut

*/

PARROT_DYNEXT_EXPORT int
call_back(const char *str)
{
    puts(str);
    fflush(stdout);

    return 4711;
}

/*

=item C<PARROT_DYNEXT_EXPORT void *
nci_pi(int test)>

Performs one from a series of tests, depending on the value given for C<test>.

=cut

*/

PARROT_DYNEXT_EXPORT void *
nci_pi(int test)
{
    switch (test) {
        case 0:
            {
                static struct {
                    int i[2];
                    char c;
                } t = {
                    {42, 100},
                    'B'
                };
                return &t;
            }
        case 1:
            {
                static struct {
                    float f[2];
                    double d;
                } t = {
                    {42.0, 100.0},
                    47.11
                };
                return &t;
            }
        case 2:
            {
                static struct {
                    char c;
                    int i;
                } t = {
                     10,
                     20
                };
                return &t;
            }
        case 3:
            {
                static struct {
                    const char *c;
                    int i;
                } t = {
                     "hello",
                     20
                };
                return &t;
            }
        case 4:
            {
                static struct _x {
                    int i;
                    int j;
                    double d;
                } xx = { 100, 77, 200.0 };
                static struct {
                    char c;
                    struct _x *x;
                } t = {
                     10,
                     &xx
                };
                return &t;
            }
        case 5:
            {
                static struct {
                    int (*f)(const char *);
                } t = {
                     call_back
                };
                return &t;
            }
        case 6:
            {
                static struct xt {
                    int x;
                    struct yt {
                        int i;
                        int  j;
                    } _y;
                    int z;
                } _x = {
                    32,
                    { 127, 12345 },
                    33
                };
                return &_x;
            }
        case 7:
            {
                static struct xt {
                    char x;
                    struct yt {
                        char i;
                        int  j;
                    } _y;
                    char z;
                } _x = {
                    32,
                    { 127, 12345 },
                    33
                };
                return &_x;
            }
        case 8:
            {
                static struct _z {
                    int i;
                    int j;
                } zz = { 100, 77 };
                static struct xt {
                    int x;
                    struct yt {
                        int i;
                        int j;
                        struct _z *z;
                    } _y;
                } _x = {
                    32,
                    { 127, 12345, &zz },
                };
                return &_x;
            }
        case 9:
            {
                static int i = 55555;
                return &i;
            }
        default:
            fprintf(stderr, "unknown test number\n");
    }

    return NULL;
}

/*

=item C<PARROT_DYNEXT_EXPORT short
nci_s(void)>

Returns the value of C<nci_dlvar_short>.

=cut

*/

PARROT_DYNEXT_EXPORT short
nci_s(void)
{
    return nci_dlvar_short;
}

/*

=item C<PARROT_DYNEXT_EXPORT short
nci_ssc(short l1, char l2)>

Returns the product of C<l1 * l2>.

=cut

*/

PARROT_DYNEXT_EXPORT short
nci_ssc(short l1, char l2)
{
    return l1 * l2;
}

/*

=item C<PARROT_DYNEXT_EXPORT void
nci_vP(void *pmc)>

Prints "ok" if C<PMC> is not null, prints "got null" otherwise.

=cut

*/

PARROT_DYNEXT_EXPORT void
nci_vP(void *pmc)
{
    if (!PMC_IS_NULL(pmc))
        puts("ok");
    else
        puts("got null");
}


/*

=back

=head2 Functions used for pdd16 tests

=over 4

=cut

*/

/*

=item C<PARROT_DYNEXT_EXPORT void
nci_cb_C1(cb_C1_func cb, void* user_data)>

Calls C<cb> function with the string "result" and the given C<user_data>.
No return value.

=cut

*/

PARROT_DYNEXT_EXPORT void
nci_cb_C1(cb_C1_func cb, void* user_data)
{
    const char *result = "succeeded";
    /* call the cb synchronously */
    (cb)(result, user_data);

    return;
}

/*

=item C<PARROT_DYNEXT_EXPORT void
nci_cb_C2(cb_C2_func cb, void* user_data)>

Calls the function C<cb> with the pointer C<user_data>. No return value.

=cut

*/

PARROT_DYNEXT_EXPORT void
nci_cb_C2(cb_C2_func cb, void* user_data)
{
    /* call the cb synchronously */
    (cb)(77, user_data);

    return;
}

/*

=item C<PARROT_DYNEXT_EXPORT void
nci_cb_C3(cb_C3_func cb, void* user_data)>

Calls function C<cb> with data C<user_data>. No return value.

=cut

*/

static int int_cb_C3 = 99;

PARROT_DYNEXT_EXPORT void
nci_cb_C3(cb_C3_func cb, void* user_data)
{
    /* call the cb synchronously */
    (cb)(&int_cb_C3, user_data);

    return;
}

/*

=item C<PARROT_DYNEXT_EXPORT void
nci_cb_D1(cb_D1_func cb, void* user_data)>

Calls function C<cb> with data C<user_data>. No return value.

=cut

*/

PARROT_DYNEXT_EXPORT void
nci_cb_D1(cb_D1_func cb, void* user_data)
{
    const char *result = "succeeded";
    /* call the cb synchronously */
    (cb)(user_data, result);

    return;
}

/*

=item C<PARROT_DYNEXT_EXPORT void
nci_cb_D2(cb_D2_func cb, void* user_data)>

Calls function C<cb> with data C<user_data>.

=cut

*/

PARROT_DYNEXT_EXPORT void
nci_cb_D2(cb_D2_func cb, void* user_data)
{
    /* call the cb synchronously */
    (cb)(user_data, 88);

    return;
}

/*

=item C<PARROT_DYNEXT_EXPORT void
nci_cb_D3(cb_D3_func cb, void* user_data)>

Calls function C<cb> with data C<user_data>.

=cut

*/

static int int_cb_D3 = 111;

PARROT_DYNEXT_EXPORT void
nci_cb_D3(cb_D3_func cb, void* user_data)
{
    /* call the cb synchronously */
    (cb)(user_data, &int_cb_D3);

    return;
}

/*

=item C<PARROT_DYNEXT_EXPORT void
nci_cb_D4(cb_D4_func times_ten, void* user_data)>

Calls function C<times_ten> with data C<user_data> 10 times in a loop.

=cut

*/

PARROT_DYNEXT_EXPORT void
nci_cb_D4(cb_D4_func times_ten, void* user_data)
{
    int cnt;
    for (cnt = 0; cnt < 9; cnt++)
    {
        (times_ten)(user_data, &int_cb_D4);
        int_cb_D4++;
    }

    return;
}

/*

=item C<PARROT_DYNEXT_EXPORT void
nci_pip(int count, Rect_Like *rects)>

Prints a count integer and the coordinates of 4 rectangles.

=cut

*/

PARROT_DYNEXT_EXPORT void
nci_pip(int count, Rect_Like *rects)
{
    int i;
    printf("Count: %d\n", count);
    for (i = 0; i < 4; ++i)
        printf("X: %d\nY: %d\nW: %d\nH: %d\n",
        rects[i].x, rects[i].y, rects[i].w, rects[i].h);
}

/*

=item C<PARROT_DYNEXT_EXPORT int
nci_i33(int *double_me, int *triple_me)>

Returns the result C<*double_me * 2 + *triple_me * 3>.

=cut

*/

PARROT_DYNEXT_EXPORT int
nci_i33(int *double_me, int *triple_me)
{
    *double_me *= 2;
    *triple_me *= 3;

    return (*double_me + *triple_me);
}

/*

=item C<PARROT_DYNEXT_EXPORT void
nci_vpii(Outer *my_data, int my_x, int my_y)>

Updates data in structure pointer C<my_data> with the given data C<my_x> and
C<my_y>.

=cut

*/

PARROT_DYNEXT_EXPORT void
nci_vpii(Outer *my_data, int my_x, int my_y)
{
    my_data->x            = my_x;
    my_data->nested->y    = my_y;
}

/*

=item C<PARROT_DYNEXT_EXPORT void *
nci_piiii(int alpha, int beta, int gamma, int delta)>

Stores 4 integer values into an array structure, and returns the address
of that structure.

=cut

*/

static int my_array[4];

PARROT_DYNEXT_EXPORT void *
nci_piiii(int alpha, int beta, int gamma, int delta)
{
    static struct array_container
    {
        int   x;
        int *array;
    } container;

    my_array[0] = alpha;
    my_array[1] = beta;
    my_array[2] = gamma;
    my_array[3] = delta;

    container.x = 4;
    container.array = my_array;

    return &container;
}

/*

=item C<PARROT_DYNEXT_EXPORT void *
nci_pii(int fac1, int fac2)>

Returns the address of global variable C<nci_dlvar_int> whose value is set
to the product of C<fac1 * fac2>.

=cut

*/

PARROT_DYNEXT_EXPORT void *
nci_pii(int fac1, int fac2)
{
   nci_dlvar_int = fac1 * fac2;

   return &nci_dlvar_int;
}

/*

=item C<PARROT_DYNEXT_EXPORT void
nci_v(void)>

Multiplies the global variable C<nci_dlvar_int> times 10.

=cut

*/

PARROT_DYNEXT_EXPORT void
nci_v(void)
{
    nci_dlvar_int *= 10;
}

/*

=item C<PARROT_DYNEXT_EXPORT void
nci_vv(void)>

Multiplies the global variable C<nci_dlvar_int> by 3.

=cut

*/

PARROT_DYNEXT_EXPORT void
nci_vv(void)
{
    nci_dlvar_int *= 3;
}

/*

=item C<PARROT_DYNEXT_EXPORT void
nci_vVi(Opaque**, int)>

Test an NCI opaque struct out value.

=cut

*/

PARROT_DYNEXT_EXPORT void
nci_vVi(Opaque **outOpaque, int x)
{
    static Opaque opaque;
    opaque.x = x;
    *outOpaque = &opaque;
}

/*

=item C<PARROT_DYNEXT_EXPORT int
nci_vp(Opaque*)>

Test that a previously generated opaque struct gets passed back
to an NCI function correctly.

=cut

*/

PARROT_DYNEXT_EXPORT void
nci_vp(Opaque *inOpaque)
{
    if (inOpaque)
        printf("got %d\n", inOpaque->x);
    else
        printf("got null");
}

/*

=item C<PARROT_DYNEXT_EXPORT char *
nci_ttt(void *p)>

Prints "s2, s1, s1d"

=cut

*/

PARROT_DYNEXT_EXPORT char *
nci_ttt(char *s1, char *s2)
{
    char* s = (char*) malloc(strlen(s2) + (2 * strlen(s1)) + 5);
    sprintf(s, "%s, %s, %s", s2, s2, s1);
    printf("%s\n", s);
    return s;
}


static void validate_float(float f, double checkval) {
    int valid;
    double error_ratio;
    error_ratio = (((double)f) - checkval) / checkval;
    valid = error_ratio <= 0.01 && error_ratio >= -0.01;
    printf("%i\n", valid);
}

/*

=item C<PARROT_DYNEXT_EXPORT float
nci_fff(float l1, float l2)>

Returns the result of C<l1> / C<l2>.

=cut

*/

PARROT_DYNEXT_EXPORT void
nci_vfff(float l1, float l2, float l3)
{
  validate_float(l1, 3456.54);
  validate_float(l2, 10.1999);
  validate_float(l3, 14245.567);
}


/*

=item C<PARROT_DYNEXT_EXPORT float
nci_fff(float l1, float l2)>

Returns the result of C<l1> / C<l2>.

=cut

*/

PARROT_DYNEXT_EXPORT void
nci_vV(const char **ptr)
{
  *ptr = "Hello bright new world\n";
}

/*

=item C<PARROT_DYNEXT_EXPORT float
nci_fff(float l1, float l2)>

Returns the result of C<l1> / C<l2>.

=cut

*/

PARROT_DYNEXT_EXPORT void
nci_vVVV(const char **ptr1, const char **ptr2, const char **ptr3)
{
  *ptr1 = "Hello bright new world!\n";
  *ptr2 = "It is a beautiful day!\n";
  *ptr3 = "Go suck a lemon.\n";
}

/*

=item C<int
nci_i20(int sel, int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10,
        int v11, int v12, int v13, int v14, int v15, int v16, int v17, int v18)>

Prints and returns the nth value in a list of integers. First argument is the selector; subsequents,
the list.

This function is designed to be outside of the range of the static frame builder as an excercise for
the dynamic frame builder.

=cut

*/
PARROT_DYNEXT_EXPORT int
nci_i20(int sel, int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8, int v9, int v10,
        int v11, int v12, int v13, int v14, int v15, int v16, int v17, int v18) {
    int *selected;
    switch ((sel < 0 ? -sel : sel) % 18) {
        case 0: selected = &v1; break;
        case 1: selected = &v2; break;
        case 2: selected = &v3; break;
        case 3: selected = &v4; break;
        case 4: selected = &v5; break;
        case 5: selected = &v6; break;
        case 6: selected = &v7; break;
        case 7: selected = &v8; break;
        case 8: selected = &v9; break;
        case 9: selected = &v10; break;
        case 10: selected = &v11; break;
        case 11: selected = &v12; break;
        case 12: selected = &v13; break;
        case 13: selected = &v14; break;
        case 14: selected = &v15; break;
        case 15: selected = &v16; break;
        case 16: selected = &v17; break;
        case 17: selected = &v18; break;
        default: printf("default case reached (should never happen)"); return -1;
    }
    printf("%d\n", *selected);
    return *selected;
}

#ifdef TEST

char l2 = 4;
float f2 = 4.0;

/*

=item C<int
main(void)>

Calls test functions C<nci_ssc> and C<nci_fff> and prints their results.

=cut

*/

int
main(void)
{
    short l1 = 3;
    float f, f1 = 3.0;
    int l = nci_ssc(l1, l2);
    printf("%d\n", l);
    f = nci_fff(f1, f2);
    printf("%f\n", f);

    return 0;
}

#endif

#ifdef __cplusplus
}
#endif

/*

=back

=head1 SEE ALSO:

  F<docs/pdds/pdd16_native_call.pod>
  F<config/gen/makefiles/root.in>
  F<t/pmc/nci.t>

=cut

*/


/*
 * Local variables:
 *   c-file-style: "parrot"
 * End:
 * vim: expandtab shiftwidth=4:
 */
