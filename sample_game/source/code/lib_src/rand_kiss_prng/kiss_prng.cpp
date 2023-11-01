//https://zuttobenkyou.wordpress.com/2012/05/01/kiss-2011-version-in-c-and-haskell/
//C implementation (adapted from Marsaglia’s own code):

/* AUTHOR: Shinobu (zuttobenkyou.wordpress.com) */
/* LICENSE: PUBLIC DOMAIN */
#include <stdint.h>
 
typedef uint64_t u64;
 
#define QSIZE 0x200000
#define CNG (cng = 6906969069ULL * cng + 13579)
#define XS (xs ^= (xs << 13), xs ^= (xs >> 17), xs ^= (xs << 43))
#define KISS (B64MWC() + CNG + XS)
 
static u64 QARY[QSIZE];
static int j;
static u64 carry;
static u64 xs;
static u64 cng;
 
void randk_reset(void)
{
    j = QSIZE - 1;
    carry = 0;
    xs = 362436069362436069ULL;
    cng = 123456789987654321ULL; /* use this as the seed */
}
 
u64 B64MWC(void)
{
    u64 t, x;
    j = (j + 1) & (QSIZE - 1);
    x = QARY[j];
    t = (x << 28) + carry;
    carry = (x >> 36) - (t < x);
    return (QARY[j] = t - x);
}
 
/* Initialize PRNG with default seed */
void randk_seed(void)
{
    u64 i;
    /* Seed QARY[] with CNG+XS: */
    for (i = 0; i < QSIZE; i++)
        QARY[i] = CNG + XS;
}
 
void randk_seed_manual(u64 seed)
{
    cng ^= seed;
    xs ^= cng;
    randk_seed();
}
 
/* Generate a pseudorandom 64-bit unsigned integer. */
u64 randk(void)
{
    return KISS;
}

void randk_warmup(int rounds)
{
    int i;
    /* Run through several rounds to warm up the state */
    for (i = 0; i < rounds; i++)
        randk();
}
 
