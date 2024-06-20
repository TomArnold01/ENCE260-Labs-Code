#include <stdio.h>
#include <stdint.h>

typedef struct Float24_t { // this struct is not needed in the quiz sever 
    int16_t mantissa;
    int8_t exponent;

} Float24_t;

Float24_t float24_init(int16_t mantissa, int8_t exponent) 
{
    Float24_t holder = {mantissa, exponent};
    return holder;
}

void float24_print(Float24_t value) 
{
    printf("%d * 2 ^ %d\n", value.mantissa, value.exponent);
}


int main(void) {
    Float24_t val1 = float24_init(1, 0);
    Float24_t val2 = float24_init(2, 1);
    float24_print(val1);
    float24_print(val2);
}