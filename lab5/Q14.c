#include <stdio.h>

typedef struct Meas_s Meas_t;
struct Meas_s
{
    double value;
    void (*dispFunc)(const Meas_t*);
};

void meas_print(const Meas_t* meas)
{
// calling function pointed by meas with meas as argument.
    meas->dispFunc(meas);
}

void disp(const Meas_t* meas)
{
    printf("%.3f m/s\n",meas->value);
}
int main()
{
    Meas_t meas = {2.7777,&disp};
    meas_print(&meas);

return 0;
}  