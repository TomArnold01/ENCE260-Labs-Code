#include "float24.h"

int main(void) 
{ 
    Float24_t x = float24_read();
    Float24_t y = float24_read();
    Float24_t z = float24_add(x, y);

    float24_print(z);
    printf("%.4f + %.4f = %.4f\n", float24_asIEEE(x), float24_asIEEE(y), float24_asIEEE(z));
}
