#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    uint64_t* prt = malloc(sizeof(uint64_t));
    scanf("%lu", prt);
    printf("%lu", *prt);
    free(prt);
}
//Note that %lu works for the quiz sever not on windows,
//run without -Werror and -Wall