#include <stdio.h>
#include <stdint.h>

void swap(uint8_t* address1, uint8_t* address2)
{
    
    int temp;
    temp = *address1;
    *address1 = *address2;
    *address2 = temp;

}

int main(void) 
{
    uint8_t i = 10, j = 20;
    swap(&i, &j);
    printf("%d %d\n", i, j);
}