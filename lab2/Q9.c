#include <stdint.h>
#include <stdio.h>

void printDigitName(uint8_t digit) {

    switch (digit){
        case 1:
            printf("One\n");
            break;
        case 2:
            printf("Two\n");
            break;
        case 3:
            printf("Three\n");
            break;
        case 4:
            printf("Four\n");
            break;
        case 5:
            printf("Five\n");
            break;
        default:
            printf("Out of bounds\n");

    }

}
int main(void) {
    printDigitName(1);
    printDigitName(6);
    printDigitName(5);
}


