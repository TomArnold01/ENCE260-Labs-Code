#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int16_t *ramp(size_t n) {
    size_t i;
    
    int16_t *data = (int16_t *) malloc(sizeof(int16_t) * n);
    for (i = 0; i < n; i++) {   
        data[i] = i + 1;
    }
    return data;
}

int main(void) 
{
    int16_t* data = ramp(5);
    for (size_t i = 0; i < 5; i++) {
    printf("%d ", data[i]);
}
free(data);
}