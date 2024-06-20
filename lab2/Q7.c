#include <stdint.h>
#include <stdio.h>

void meetsCondition(int64_t x)
{

    if (x >= 0 && x%2 == 0 || x <= 0 && x%2 == -1){
        printf("true\n");
    } else {
        printf("false\n");
    }

}
int main(void)
{

     meetsCondition(1642);
     meetsCondition(-20);
     meetsCondition(29);
     meetsCondition(-31);
}
