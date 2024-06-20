#ifndef BULB_H
#define BULB_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    uint8_t modelNum;
    uint8_t serialNumber;
} Bulb_t;

Bulb_t bulb_sellModel(uint8_t model);

void bulb_display(Bulb_t bulb);

uint64_t bulb_numSold(uint8_t model);











#endif