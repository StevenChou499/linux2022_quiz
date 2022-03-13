#include <stdint.h>
#include <stdio.h>

int ilog32(uint32_t v) // v = 34
{
    int ret = v > 0; // ret = 1
    int m = (v > 0xFFFFU) << 4; // 0xFFFFU = 65535, v < 0xFFFFU,m = 0
    v >>= m; // v >> 0
    ret |= m; // ret = 1
    m = (v > 0xFFU) << 3; // 0xFFU = 255, v < 0xFFU, m = 0
    v >>= m; // v >> 0
    ret |= m; // ret = 1
    m = (v > 0xFU) << 2; // 0xFU = 15, v > 0xFU, m = 4
    v >>= m; // v >> 4, v = 2
    ret |= m; // ret = 5
    m = (v > 0x3U) << 1; // 0x3U  = 3, v < 0x3U, m = 0
    v >>= m; // v >> 0, v = 2
    ret |= m; // ret = 5
    ret += (v > 0x1U);
    return ret;
}

int main()
{
    printf("for 8, ilog32(8) = %d\n", ilog32(8));
    for(int i = 0; i < 100; i++){
        printf("for i = %d, ilog32(%d) = %d\n", i, i, ilog32(i));
    }
    return 0;
}