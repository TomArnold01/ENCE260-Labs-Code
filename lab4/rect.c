#include <stdint.h>
#include <stdio.h>

#include "rect.h"


void rect_set(Rect_t* rect, uint32_t width, uint32_t height)
{
    rect->height = height;
    rect->width =width;   
}
uint32_t rect_area(const Rect_t* rect)
{
    return rect->width * rect->height;
}

uint32_t rect_perimeter(const Rect_t* rect)
{
    return (rect->height *2) + (rect->width *2);
}