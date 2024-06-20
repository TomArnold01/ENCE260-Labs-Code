#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

uint8_t intLog2(uint32_t value)
{
    int32_t count = 0;
    while (value > 1) {
        count++;
        value = value / 2;
    }
    return count;
}

int main(void) {
    printf("%d\n", intLog2(32));
    printf("%d\n", intLog2(31));
}
