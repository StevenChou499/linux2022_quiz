#include <limits.h>
#include <stdio.h>

int divide(int dividend, int divisor) // eg. dividend = 10, divisor = 3
{
    int signal = 1;
    unsigned int dvd = dividend; // dvd = 10
    if (dividend < 0) { // check if dividend is negative
        signal *= -1;
        dvd = ~dvd + 1;
    }

    unsigned int dvs = divisor; // dvs = 3
    if (divisor < 0) { // check if divisor is negative
        signal *= -1;
        dvs = ~dvs + 1;
    }

    int shift = 0;
    while (dvd > (dvs << shift)) // dvd = 10, dvs << shift = 3, shift++, dvd = 10, dvs << shift = 6, shift++
        shift++; // shift = 2

    unsigned int res = 0;
    while (dvd >= dvs) {
        while (dvd < (dvs << shift)) // dvd = 10, dvs << shift = 12, shift--
            shift--; // shift = 1
        res |= (unsigned int) 1 << shift;
        dvd -= res;
    }

    if (signal == 1 && res >= INT_MAX)
        return INT_MAX;
    return res * signal;
}

int main()
{
    int a = 133;
    int b = 3;
    /*for(int i = 1; i < 100; i++){
        if(divide(133, i) != (133 / i)){
            printf("It isn't the same!!\n");
        }
        printf("%d\n", i);
    }*/
    printf("%d / %d = %d by divide and %d by /\n", a, b, divide(a, b), a / b);
    return 0;
}