#include <stdio.h>
/*
 * ALIGNOF - get the alignment of a type
 * @t: the type to test
 *
 * This returns a safe alignment for the given type.
 */
#define ALIGNOF(t) \
    ((char *)(&((struct { char c; t _h; } *)0)->_h) - (char *)0)

int main()
{
    printf("The alignof int is: %lu\n", ALIGNOF(int));
    return 0;
}