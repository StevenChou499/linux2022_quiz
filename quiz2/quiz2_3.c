#include <stdint.h>
#include <stdio.h>

uint64_t gcd64(uint64_t u, uint64_t v)
{
    if (!u || !v) return u | v;
    int shift;
    for (shift = 0; !((u | v) & 1); shift++) {
        u /= 2, v /= 2;
    }
    while (!(u & 1))
        u /= 2;
    do {
        while (!(v & 1))
            v /= 2;
        if (u < v) {
            v -= u;
        } else {
            uint64_t t = u - v;
            u = v;
            v = t;
        }
    } while (v);
    return u << shift;
}

int main()
{
    uint64_t a = 178;
    uint64_t b = 96;
    printf("The GCD of %lu and %lu is %lu\n", a, b, gcd64(a, b));
    return 0;
}