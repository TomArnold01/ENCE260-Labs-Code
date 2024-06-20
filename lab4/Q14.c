#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "lift.h"


#define MAX_PASSENGERS 12

int main(void)
{
    Lift_t lift = lift_init(MAX_PASSENGERS, 1);
    lift_onboard(&lift, 0, 5);
    puts(-2 == lift_goToFloor(&lift, -2) ? "true" : "false");

    lift_onboard(&lift, 5, 15);
    
    int16_t current = lift_goToFloor(&lift, 4);
    while (current != 4) { //If too full
        lift_onboard(&lift, 1, 0);
        current = lift_goToFloor(&lift, 4);
        puts(4 == current ? "true" : "false");
    }
}