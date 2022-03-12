#include <limits.h>
#include <stdio.h>

int divide(int dividend, int divisor) // eg. dividend = 133, divisor = 7
{
    int signal = 1;
    unsigned int dvd = dividend; // dvd = 133
    if (dividend < 0) { // check if dividend is negative
        signal *= -1;
        dvd = ~dvd + 1;
    }

    unsigned int dvs = divisor; // dvs = 7
    if (divisor < 0) { // check if divisor is negative
        signal *= -1;
        dvs = ~dvs + 1;
    }

    int shift = 0;
    while (dvd > (dvs << shift)) // dvd = 133, dvs = 7, 14, 28, 56, 112, 224, shift = 0, 1, 2, 3, 4, 5
        shift++; // shift = 5

    unsigned int res = 0;
    while (dvd >= dvs) {
        while (dvd < (dvs << shift)) // dvd = 133
            shift--; // shift = 4
        res |= (unsigned int) 1 << shift; // res = 1 << 4 = 16
        dvd -= (1 << shift) * dvs;
    }

    if (signal == 1 && res >= INT_MAX)
        return INT_MAX;
    return res * signal;
}


int main()
{
    for(int i = 1; i < 500; i++){
        for(int y = 1; y <= i; y++){
            if(divide(i, y) != (i / y)){
                printf("It isn't the same!!\n");
            }
        }
    }
    return 0;
}