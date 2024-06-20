#include <stdio.h>
#include <stdint.h>

int main(void) 
{
    int c;
    while((c = getc(stdin)) != EOF) 
    {
        printf("%d\n", c);
    }
}
