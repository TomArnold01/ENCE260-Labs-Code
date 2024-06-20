#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    float lat;
    float lon;
    float alt; 
} Coord_t;

bool isBelowSeaLevel(const Coord_t coord) 
{
    if (coord.alt < 0) {
        return true;
    } else {
        return false;
    }
}

uint64_t numBelowSeaLevel(const Coord_t coords[], size_t n) 
{
    int count=0;
    for (size_t i=0; i<n; i++) {
        if (isBelowSeaLevel(coords[i])==true) {
            count++;
        }
    } 
    return count;
}


int main(void) 
{
Coord_t coords[5];
for (size_t i = 0; i < 5; i++) {
    coords[i].lat = ((float)i - 2)*15;
    coords[i].lon = ((float)i - 2)*-15;
    coords[i].alt = ((float)i - 2)*100;
}
printf("%ld\n", numBelowSeaLevel(coords, 5));
}