//MODIFYING HAS NO EFFECT
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "temp.h"


int main(void)
{
Temp_t temp;
float value = 0;
temp_set(&temp, value, CELSIUS);
temp_print((const Temp_t*)&temp, CELSIUS);
temp_print((const Temp_t*)&temp, FAHRENHEIT);
temp_print((const Temp_t*)&temp, KELVIN);
}