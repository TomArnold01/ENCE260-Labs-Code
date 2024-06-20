#include <stdio.h>
#include <stdint.h>

typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
} Heading_t;

int main(void) 
{
    Heading_t dir = NORTH;
printf("%d\n", dir == NORTH);
}