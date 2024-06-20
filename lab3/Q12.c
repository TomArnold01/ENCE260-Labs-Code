#include <stdio.h>
#include <stdint.h>

int32_t accumulator(int32_t value)
{
    static int32_t accumulator_sum;
    accumulator_sum += value;
    return accumulator_sum;
}

int main(void)
{
    accumulator(3);
    accumulator(2);
    printf("%d\n", accumulator(5));
}