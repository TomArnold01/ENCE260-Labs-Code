#include <stdint.h>
#include <stdio.h>

int main(void)
{
    int32_t c;
    int32_t array[100];
    int32_t i = 0;

    do {
        scanf("%d", &c);
        array[i] = c;
        
        if(c != -1) {
            i++;
        }

        if (i == 100) {
            break;
        }
    } while (c != -1);

    
    printf("%d numbers entered\n", i);
    for(size_t index=0; index<i; index++) {
        if (array[index] != -1) {
            printf("%d\n", array[index]);
        }
    }
    
}