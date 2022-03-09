#include <stdint.h>
#include <stdio.h>

uint32_t average(uint32_t a, uint32_t b)
{
    return (a & b) + ((a ^ b) >> 1);
}

int main(void)
{
    uint32_t a = 65;
    uint32_t b = 44;
    printf("The average between %u and %u is %u\n", a, b, average(a, b));
    return 0;
}