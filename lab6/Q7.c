#include <stdio.h>
#include <stdlib.h>

int main()
{
    // initialize array and size to store count
    
    int cap = 10;
    int *arr = (int *)calloc(cap, sizeof(int));
    
    int size = 0;

    int number=0;
    while (number != -10000) {
        scanf("%d ", &number);

        // dont read after -10000 is encountered
        if (number == -10000) {
            break;
        }

        // if current size of array is equal to capacity
        if (size == cap) {
            cap += 10; // inrease the cap by 10
            arr = (int *)realloc(arr, sizeof(int) * (cap));
        }
        arr[size++] = number;
    }
    printf("Numbers read = %d\n", size);
    free(arr);
}