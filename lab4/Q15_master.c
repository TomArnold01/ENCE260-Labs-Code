#ifndef BULB_H
#define BULB_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int8_t modelNum;
    uint8_t serialNumber;
} Bulb_t;

Bulb_t bulb_sellModel(uint8_t model);

void bulb_display(Bulb_t bulb);

uint64_t bulb_numSold(uint8_t model);

//---------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define MAX_MODELS  50

static int nextSrNo [MAX_MODELS];
static uint8_t modelNos [MAX_MODELS];

Bulb_t bulb_sellModel(uint8_t model)
{
    Bulb_t v;
    v.modelNum = model;
    int i;
    for (i = 0; i < MAX_MODELS; i++) 
        if ((modelNos [i] == model) || (modelNos [i] == 0)) {
            break;
        }
    modelNos [i] = model;
    v.serialNumber = nextSrNo [i]++;
    return v;
}

void bulb_display(Bulb_t bulb) 
{
    printf ("Model %d, SN%06d\n", bulb.modelNum, bulb.serialNumber);
}
uint64_t bulb_numSold(uint8_t model) 
{
    int i;
    for (i = 0; i < MAX_MODELS; i++) 
        if ((modelNos [i] == model) || (modelNos [i] == 0)) {
            break;
        }
    return nextSrNo [i];    
}
//----------------------------------------------------------------
//MODIFICATIONS HAVE NO EFFECT
#include <stdint.h>
#include <stdio.h>

int main(void)
{
Bulb_t bulbs[10];

for (size_t i = 0; i < 10; i++) {
    bulbs[i] = bulb_sellModel(i*5);
}

for (size_t i = 0; i < 10; i++) {
    bulb_display(bulbs[i]);
    uint8_t modelNumber = i*5;
    printf("Model %u: %lu sold\n", modelNumber, bulb_numSold(modelNumber));
    printf("\n");
}
}



#endif