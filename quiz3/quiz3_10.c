#include <stdio.h>
#include <stdint.h>

#define DIVIDE_ROUND_CLOSEST(x, divisor)                       \
    ({                                                         \
        typeof(x) __x = x;                                     \
        typeof(divisor) __d = divisor;                         \
        (((typeof(x)) -1) > 0 || ((typeof(divisor)) -1) > 0 || \
         (((__x) > 0) == ((__d) > 0)))                         \
            ? 1                  \
            : 0;                 \
    })

int main()
{
    int a = -5;
    int b = 5;
    printf("DIVIDE_ROUND_CLOSEST(%d, %d) = %d\n", a, b, DIVIDE_ROUND_CLOSEST(a, b));
    return 0;
}