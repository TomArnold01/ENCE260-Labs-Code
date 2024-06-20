#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// structure of type Button_t
typedef struct Button_t
{
    uint16_t x; // x-position of the Button_t
    uint16_t y; // y-position of the Button_t
    uint16_t width; // width of the Button_t
    uint16_t height; // height of the Button_t

void (*callback)(void); // callback function of the Button_t
}Button_t;

/**
* function that takes as arguments the button's screen position (x, y), its width, height and callback
* function for the button and create and return the Button_t object with given values
*/
Button_t button_init(uint16_t x, uint16_t y, uint16_t width, uint16_t height, void (*callback)(void))
{
// create a Button_t object
    Button_t button;
// set the position (x, y)
    button.x = x;
    button.y = y;
// set the width and height
    button.width = width;
    button.height = height;
// set the callback function
    button.callback = callback;

    return button; // return the object created
}

/**
* Function which takes as input a pointer to Button_t and calls the callback function for the button
*/
void button_click(Button_t* button)
{
    button->callback();
}

// callback function for the button
void clickFunc(void)
{
    puts("Button Clicked!");
}

int main()
{
// create a Button_t object
Button_t button = button_init(480, 320, 64, 32, &clickFunc);
button_click(&button); // call the callback function for the button
return 0;
}