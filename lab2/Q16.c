#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

uint32_t countRushes(float screeHeight, float rushHeight, float slideBack) {
    float currentHeight = 0;
    int count = 0;
    while (currentHeight < screeHeight) {
        count = count + 1;
        currentHeight = currentHeight + rushHeight;
        if (currentHeight >= screeHeight) {
            break;
        }else {
            currentHeight = currentHeight - slideBack;
        }
    }
    return (count);
}
int main(void) {
    printf("%d\n", countRushes(100, 50, 10));

    printf("%d\n", countRushes(100, 100, 90));

    printf("%d\n", countRushes(0, 100, 30));

}
