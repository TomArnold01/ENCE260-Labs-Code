#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "temp.h"

void temp_set(Temp_t* temp, float value, Unit_t unit) 
{
    temp->temp = value;
    temp->unit = unit;
}

static Temp_t convert(Temp_t temp, Unit_t toUnit)
{
    switch (temp.unit) {
        case 0:// C going to...
            switch (toUnit) {
                case 0: // C
                    temp.unit = toUnit;
                    break;
                case 1:  //F
                    temp.temp = (temp.temp*1.8) + 32; // to switch from C to F
                    temp.unit = toUnit;
                    break;
                case 2:  //K
                    temp.temp = temp.temp + 273.15; // to switch from C to K
                    temp.unit = toUnit;
                    break;
            }
            break;
        case 1: // F going to...
            switch (toUnit) {
                case 0: // C
                    temp.temp = (temp.temp - 32)/1.8; // to switch from F to C
                    temp.unit = toUnit;
                    break;
                case 1:  // F
                    temp.unit = toUnit;
                    break;
                case 2:  // K
                    temp.temp = (temp.temp+459.67)/1.8; // to switch from F to K
                    temp.unit = toUnit;
                    break;
            }
            break;
        case 2:  // K going to...
            switch (toUnit) {
                case 0:  // C
                    temp.temp = temp.temp - 273.15;  // to siwtch from K to C
                    temp.unit = toUnit;
                    break;
                case 1:  // F
                    temp.temp = (temp.temp * 1.8) - 459.67; // to switch from K to f
                    temp.unit = toUnit;
                    break;
                case 2: // K
                    temp.unit = toUnit;
                    break;
            }
            break;
    }
    return temp;
}

void temp_print(const Temp_t* temp, Unit_t unit)
{
    Temp_t newTemp = convert(*temp, unit);

    switch (newTemp.unit) {
        
        case 0: 
            // if old unit is C
            printf("%.2f deg C\n", newTemp.temp);
            break;
        
        case 1:
            // if old unit is F
            printf("%.2f deg F\n", newTemp.temp);
            break;
        
        case 2:
            // if old unit is K
            printf("%.2f K\n", newTemp.temp);
            break;
    }
}
