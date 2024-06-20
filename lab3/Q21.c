#include <stdint.h>
#include <stdio.h>


void printSquaredArray(const int32_t array[], size_t n)
{
    for(size_t i=0; i<n; i++) {
        printf("%d\n", array[i]*array[i]);
    }
}

int main(void) 
{
    const int32_t array[3] = {1, 2, 3};
    printSquaredArray(array, 3);
}