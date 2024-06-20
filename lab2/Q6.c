#include <stdint.h>
#include <stdio.h>

void printThreshold(uint32_t x)
{
    if (x < 100) {
        printf("x is less than 100\n");
    } else {
        printf("x is not less than 100\n");
    }
}

int main(void)
{
    printThreshold(101);
}

