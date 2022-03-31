#include <stdio.h>

static inline unsigned long fls(unsigned long word)
{
    int num = 64 - 1;
        
    if (!(word & (~0ul << 32))) {
        num -= 32;
        word <<= 32;
    }
    if (!(word & (~0ul << (64 - 16)))) {
        num -= 16;
        word <<= 16;
    }
    if (!(word & (~0ul << (64 - 8)))) {
        num -= 8;
        word <<= 8;
    }
    if (!(word & (~0ul << (64 - 4)))) {
        num -= 4;
        word <<= 4;
    }   
    if (!(word & (~0ul << (64 - 2)))) {
        num -= 2;
        word <<= 2;
    }   
    if (!(word & (~0ul << (64 - 1))))
        num -= 1;
    return num;
} 

unsigned long i_sqrt(unsigned long x) // x = 4
{
    unsigned long b, m, y = 0;

    if (x <= 1)
        return x;

    m = 1UL << (fls(x) & ~1UL); // fls() = 2, 2 & ~1UL = 2, m = 4
    while (m) {
        b = y + m; // b = 4
        y >>= 1; // x = 0, b = 4

        if (x >= b) {
            x -= b;
            y += m; // y += 4;
        }
        m >>= 2;
        printf("y = %ld\n", y);
    }

    return y;
}

int main()
{
    unsigned long a = 4;
    printf("fls(%ld) = %ld\n", a, fls(a));
    printf("i_sqrt(%ld) = %ld\n", a, i_sqrt(a));
    /*for(unsigned long i = 0UL; i < 100UL; i++){
        printf("i_sqrt(%ld) = %ld\n", i, i_sqrt(i));
    }*/
    return 0;
}