#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

size_t improved(uint64_t *bitmap, size_t bitmapsize, uint32_t *out)
{
    size_t pos = 0;
    uint64_t bitset;
    for (size_t k = 0; k < bitmapsize; ++k) {
        bitset = bitmap[k];
        while (bitset != 0) {
            uint64_t t = bitset & -bitset;
            int r = __builtin_ctzll(bitset);
            out[pos++] = k * 64 + r;
            bitset ^= t;
        }
    }
    return pos;
}

int main()
{
    uint64_t a = 78;
    printf("For a = %lu, %lu & -%lu = %lu", a, a, a, a & -a);
    return 0;
}