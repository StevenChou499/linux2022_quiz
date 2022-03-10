#include <stdio.h>

#define GENMASK(h, l) \
    (((~0UL) >> (63 - h)) & ((~0UL) >> (l) << (l)))

int main()
{
    printf("GENMASK(%u, %u) = %ld\n", 8, 6, GENMASK(8, 6));
    printf("%ld\n", ~0UL >> 63);
    return 0;
}