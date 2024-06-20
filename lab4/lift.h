#ifndef LIFT_T
#define LIFT_T

typedef struct {
    int16_t currentFloor;
    int32_t numberPass;
    int32_t limit;
} Lift_t;

Lift_t lift_init(uint8_t maxPassengers, int16_t startFloor);

void lift_onboard(Lift_t* lift, uint8_t peopleOff, uint8_t peopleOn);

int16_t lift_goToFloor(Lift_t* lift, int16_t floor);

#endif