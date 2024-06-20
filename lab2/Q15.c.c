#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

void printSquares(uint32_t n)
{

    for (int32_t t = 1; n+1!=t; t++) {
        printf("%d\n",t*t);
    }

}


int main(void) {
    printSquares(1);
}
