#include <stdio.h>
#include <stdint.h>
#include <limits.h>

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

int main(void) 
{
Float24_t result0;
result0 = float24_normalise(-32767,0);
float24_print(result0); // -32767 * 2 ^ 0

Float24_t result;
result = float24_normalise(-32768,0);
float24_print(result); // -16384 * 2 ^ 1

Float24_t result2;
result2 = float24_normalise(INT16_MAX*2+1,0);
float24_print(result2); //  32767 * 2 ^ 1

Float24_t result3;
result3 = float24_normalise(INT32_MAX,0);
float24_print(result3); // 32767 * 2 ^ 16

Float24_t result4;
result4 = float24_normalise(INT32_MAX, 80);
float24_print(result4); // 32767 * 2 ^ 96

}