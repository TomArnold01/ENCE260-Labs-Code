#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int32_t number1;
    int32_t number2;
    int32_t total;

    number1 = 10;
    number2 =20;
    total = number1 + number2;
    printf("The sum of %d and %d is %d\n", number1, number2, total);

    return 0;
}
