#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

typedef struct Float24_t {
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


Float24_t float24_normalise(int32_t oversizeMantissa, int8_t exponent)
{
    if (oversizeMantissa > INT16_MIN && oversizeMantissa < INT16_MAX) {
        Float24_t holder = {oversizeMantissa, exponent};
        return holder;
    } else {
        int32_t count=0;
        if (oversizeMantissa > INT16_MAX) {
            while (oversizeMantissa > INT16_MAX) {
                oversizeMantissa = oversizeMantissa / 2;
                count++;
            }
        } else {
            while (oversizeMantissa <= INT16_MIN) {
                oversizeMantissa = oversizeMantissa / 2;
                count++;
            }
        }
        
        exponent = exponent+count;
        Float24_t holder = {oversizeMantissa, exponent};
        return holder;
    }
}


Float24_t float24_multiply(Float24_t num1, Float24_t num2) 
{
    int32_t mantissa = num1.mantissa * num2.mantissa;
    int32_t exponent = num1.exponent + num2.exponent;
    return float24_normalise(mantissa, exponent);
}

Float24_t float24_add(Float24_t num1, Float24_t num2)
{
    int32_t c = num1.exponent > num2.exponent? num1.exponent : num2.exponent;

    int32_t m = (int32_t)round((int32_t)(1.0 * num1.mantissa / pow(2, c - num1.exponent)) + 
                           (int32_t)(1.0 * num2.mantissa / pow(2, c - num2.exponent)));
    return float24_normalise (m, c); 
}


int main(void)
{
Float24_t number_a = float24_init(1, 0);
Float24_t number_b = float24_init(1, 0);
Float24_t sum = float24_add(number_a, number_b);
Float24_t product = float24_multiply(number_a, number_b);
float24_print(sum);
float24_print(product);
}