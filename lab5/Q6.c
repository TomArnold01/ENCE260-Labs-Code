#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

int main(void)
{
    int c;
    while((c = getchar()) != EOF) {

        if(c == 32) {
            printf("' ': Non-alphanumeric\n");
        }
        if (isdigit(c)) {
            printf("'%c': Digit %c\n", c, c);
        }
        if (isalpha(c)) {
            if (isupper(c)) {
                printf("'%c': Letter %d\n", c,c-64);
            } else {
                printf("'%c': Letter %d\n", c,c-96);
            }
        }
        if (c == 10) {
            printf("'\\n'\n");
        }

        if (!isdigit(c) && !isalpha(c) && c !=32 && c != 10) {
            printf("'%c': Non-alphanumeric\n", c);
        }
    }

}

