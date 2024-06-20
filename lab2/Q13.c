#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int32_t count;
    char c;
    do {
        c = getchar();
        count++;
    } while (c != 'q');
    printf("%d",count);
}
