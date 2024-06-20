#include "bulb.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define MAX_MODELS  255

static int nextSrNo [MAX_MODELS];
static uint8_t modelNos [MAX_MODELS];

Bulb_t bulb_sellModel(uint8_t model)
{

    int i;
    for (i = 0; i < MAX_MODELS; i++) 
        if ((modelNos [i] == model) || (modelNos [i] == 0)) {
            break;
        }
    modelNos [i] = model;

    Bulb_t v;
    v.modelNum = model;
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