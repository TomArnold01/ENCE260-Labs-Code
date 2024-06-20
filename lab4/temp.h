#ifndef TEMP_H
#define TEMP_H

typedef enum {
    CELSIUS=0,
    FAHRENHEIT,
    KELVIN
}Unit_t;

typedef struct {
    Unit_t unit;
    float temp;
}Temp_t;

void temp_set(Temp_t* temp, float value, Unit_t unit);

void temp_print(const Temp_t* temp, Unit_t unit);


#endif