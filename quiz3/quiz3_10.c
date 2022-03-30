#include <stdio.h>
#include <stdint.h>

#define DIVIDE_ROUND_CLOSEST(x, divisor)                       \
    ({                                                         \
        typeof(x) __x = x;                                     \
        typeof(divisor) __d = divisor;                         \
        (((typeof(x)) -1) > 0 || ((typeof(divisor)) -1) > 0 || \
         (((__x) > 0) == ((__d) > 0)))                         \
            ? ((__x + (__d >> 1)) / (__d))                  \
            : ((__x - (__d >> 1)) / (__d));                 \
    })

int main()
{
    int a = -7;
    int b = 3;
    printf("DIVIDE_ROUND_CLOSEST(%d, %d) = %d\n", a, b, DIVIDE_ROUND_CLOSEST(a, b));
    unsigned int tmp = -1;
    printf("%d\n", ((unsigned int) -1) > 0);
    return 0;
}