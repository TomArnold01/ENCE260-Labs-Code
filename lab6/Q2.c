#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    char random;
    int8_t junk;
} Data_t;


Data_t* newData(char random, int8_t junk)
{
    Data_t* ptr;
    ptr = (Data_t*)malloc(sizeof(Data_t));
    if(ptr == NULL) {
        return NULL;
    }
    ptr->random= random;
    ptr->junk = junk;
    return ptr;
}

void freeData(Data_t* data)
{
    if(data != NULL) {
        free(data);
    }
}

int main(void) 
{
    Data_t* data = newData('A', 1);
    printf("%c %d\n", data->random, data->junk);
    freeData(data);
}