#include <stdio.h>
#include <stdint.h>

typedef struct Float24_t {
    int16_t mantissa;
    int8_t exponent;

} Float24_t;


int main(void) 
{
    Float24_t val1 = {1, 0};
printf("Mantissa: %hd, Exponent: %hhd\n", val1.mantissa, val1.exponent);
}