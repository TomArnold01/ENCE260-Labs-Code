#include <stdio.h>
#include <stdint.h>

int main()
{
    size_t objSize;

    objSize = sizeof(int32_t);
    printf("The object size is %d bytes\n", objSize);
}
