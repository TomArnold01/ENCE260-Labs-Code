#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "lift.h"

Lift_t lift_init(uint8_t maxPassengers, int16_t startFloor)
{
    Lift_t v;
    v.numberPass = 0;
    v.limit = maxPassengers;
    v.currentFloor = startFloor;
    return v;
}

void lift_onboard(Lift_t* lift, uint8_t peopleOff, uint8_t peopleOn)
{

    lift->numberPass += peopleOn;
    lift->numberPass -= peopleOff;
}

int16_t lift_goToFloor(Lift_t* lift, int16_t floor)
{
    if (lift->numberPass > lift->limit) {
        return lift->currentFloor;
    } else {
        lift->currentFloor = floor;
        return lift->currentFloor;
    }
}
