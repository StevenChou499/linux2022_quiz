#include <stdio.h>

/* maximum alignment needed for any type on this platform, rounded up to a
   power of two */
#define MAX_ALIGNMENT 16

/* Given a size, round up to the next multiple of sizeof(void *) */
#define ROUND_UP_TO_ALIGNMENT_SIZE(x) \
    (((x) + MAX_ALIGNMENT - 1U) & ~(MAX_ALIGNMENT - 1U))

int main()
{
    printf("%d\n", ROUND_UP_TO_ALIGNMENT_SIZE(1));
    return 0;
}