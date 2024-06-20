#include <stdint.h>
#include <stdio.h>

int32_t gringe(int32_t boink, int32_t flunk)
{
    return  boink==flunk ? 42 : flunk-11;
}

int main(void) {
    printf("%d\n", gringe(23, 23));
    printf("%d\n", gringe(23, 24));
}
