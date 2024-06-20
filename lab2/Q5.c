#include <stdint.h>
#include <stdio.h>

uint32_t increment(uint32_t x)
{
    x++;
    return x;
}

int main(void)
{
    uint32_t x = 0;
    uint32_t y = 0;

    increment(x);
    y = increment(y);
    printf("%d %d\n", x, y);
}
