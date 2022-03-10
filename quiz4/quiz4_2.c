#define BITS_PER_BYTE 8
#define BITS_PER_LONG (sizeof(unsigned long) * BITS_PER_BYTE)

#include <stddef.h>
#include <stdio.h>

static inline size_t fuck(unsigned long x) // x = 8 0x0000000000000008
{
    if (x == 0)
        return 0;

    size_t o = 1;
    unsigned long t = ~0UL; // 0xFFFFFFFFFFFFFFFF
    size_t shift = BITS_PER_LONG; // shift = 64

    shift >>= 1; // shift = 32
    t >>= shift; // 0x00000000FFFFFFFF

    int i = 0;
    while (shift) {
        if ((x & t) == 0) {
            i++;
            x >>= shift;
            o += shift;
            printf("%d %ld\n", i, shift);
        }

        shift >>= 1;
        t >>= shift;
    }

    return o;
}

int main()
{
    /*for(unsigned long i = 0; i < 100UL; i++){
        printf("ffs(%lu) = %lu\n", i, fuck(i));
    }*/
    printf("ffs(%lu) = %lu\n", 32768*2, fuck(32768*2));
    return 0;
}