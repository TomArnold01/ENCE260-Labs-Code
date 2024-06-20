//MODIFICATIONS HAVE NO EFFECT
#include <stdint.h>
#include <stdio.h>

#include "bulb.h"


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
