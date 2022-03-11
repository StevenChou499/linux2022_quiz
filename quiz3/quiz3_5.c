#include <stdint.h>
#include <stdio.h>

uint8_t rev8(uint8_t x)
{
    x = (x >> 4) | (x << 4); // swap the left and right 4 bits
    x = ((x & 0xCC) >> 2) | ((x & 0x33) << 2);
    x = ((x & 0xAA) >> 1) | ((x & 0x55) << 1);
    return x;
}

int main()
{
    uint8_t x = 99;
    printf("The bits before filpping: %u\n", x);
    printf("The bits after flipping: %u\n", rev8(x));
    return 0;
}