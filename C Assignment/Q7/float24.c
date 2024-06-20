#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "float24.h"

Float24_t float24_init(int16_t mantissa, int8_t exponent) 
{
    Float24_t holder = {mantissa, exponent};
    return holder;
}

void float24_print(Float24_t value) 
{
    printf("%d * 2 ^ %d\n", value.mantissa, value.exponent);
}


static Float24_t float24_normalise(int32_t oversizeMantissa, int8_t exponent)
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

Float24_t float24_read(void) 
{
    char input[100];
    int numInput = 0;
    int exp = 0;
    int c = 0;
    int i = 0;
    while((input[i] = getchar()) != EOF && input[i] != '\n' && input[i] != ' ') {
        i++;
    }

    for (int i = 0; i < strlen(input); i++) {
        
        if (isdigit(input[i])) {
            numInput = numInput * 10 + (input[i] - '0');
            c = i;
        } else if (input[i] == '-' || input[i] == '+') {
            c = i;
        } else {
            
            break;
        }
    }
    if (input[0] == '-') {
        numInput = numInput * -1;
    }
    
    for (int i = c+2; i < strlen(input); i++) {
        if (isdigit(input[i])) {
            exp = exp * 10 + (input[i] - '0');
        } else if (input[i] == '-' || input[i] == '+') {
            c = c + 1;
        } else {
            break;
        }
    }
    if (input[c+1] == '-') {
        exp = exp * -1;
    }
    
    if (c == 0) {
        exp = -128;
    }
  
    if (exp > 127) {
        exp = 127;
    }
    
    return float24_init(numInput, exp);
}
 

void float24_max(Float24_t* num1, Float24_t* num2, Float24_t** max) 
{
    
    Float24_t neg = float24_normalise(-1,0);
    Float24_t negNum2 = float24_multiply(*num2, neg);
    Float24_t addition = float24_add(*num1, negNum2);

    if (addition.mantissa < 0) { 
        *max = num2;
       
    } else if (addition.mantissa > 0) { 
        *max = num1;
       
    } else {
        if (num1->exponent < num2->exponent) { 
            *max = num2;
        } else if (num1->exponent > num2->exponent) { 
            *max = num1;
        } else {
            *max = num1;
        }
    }
}
