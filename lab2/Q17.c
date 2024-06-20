#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

void printPrimesInRange(uint32_t n1, uint32_t n2)
{
    for (int i=n1; i < n2+1; ++i) {
        int flag_var=0;
        for(int j=2; j<=i/2; ++j) {
            if(i%j==0) {
                flag_var=1;
                break;
            }
        }
        if(flag_var==0) {
            printf("%d\n",i);
        }
    }
}

int main(void) {
    printPrimesInRange(100, 101);
    printPrimesInRange(100, 100);

}

