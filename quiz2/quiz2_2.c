#include <stdint.h>
#include <stdio.h>

uint32_t max(uint32_t a, uint32_t b)
{
    return a ^ ((a ^ b) & -(a < b));
}

int main()
{
    uint32_t a = 65;
    uint32_t b = 123;
    printf("The greater number between %u and %u is %u\n", a, b, max(a, b));
    return 0;
}