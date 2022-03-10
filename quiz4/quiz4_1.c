#include <stdio.h>
#include <stdint.h>

int ceil_log2(uint32_t x) // x = 4;
{
    uint32_t r, shift;

    x--; // x = 3;
    r = (x > 0xFFFF) << 4; // 0 or 1, -> 0 or 16
    x >>= r; // delete the last 16 bits
    shift = (x > 0xFF) << 3; // 0 or 1, -> 0 or 8
    x >>= shift; // delete the last 8 bits
    r |= shift; // r = r + shift
    shift = (x > 0xF) << 2;
    x >>= shift; // delete the last 4 bits
    r |= shift; // r = r + shift
    shift = (x > 0x3) << 1; // 0 or 1, -> 0 or 2
    x >>= shift;
    return (r | shift | x >> 1) + 1; // x >> 1 + r + shift
}

int main()
{
    for(uint32_t i = 0; i < 100; i++){
        printf("The ceil_log2 of %2u is %d\n", i, ceil_log2(i));
    }
    return 0;
}