#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

typedef enum {
    MONDAY=0,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATARDAY,
    SUNDAY
} Weekday_t;

typedef struct {
    Weekday_t weekday;
    uint8_t day;
    uint8_t month;
    uint16_t year;
} Date_t;
    
Date_t setDate(Weekday_t weekday, uint8_t day, uint8_t month, uint16_t year)
{
    Date_t v;
    v.weekday = weekday;
    v.day = day;
    v.month = month;
    v.year = year;

    return v;
}

void printDate(const Date_t* date)
{
    switch ( date->weekday) {
        case 0:
            printf("Monday %d/%d/%d\n", date->day, date->month, date->year);
            break;

        case 1:
            printf("Tuesday %d/%d/%d\n", date->day, date->month, date->year);
            break;

        case 2:
            printf("Wednesday %d/%d/%d\n", date->day, date->month, date->year);
            break;

        case 3:
            printf("Thursday %d/%d/%d\n", date->day, date->month, date->year);
            break;

        case 4:
            printf("Friday %d/%d/%d\n", date->day, date->month, date->year);
            break;

        case 5:
            printf("Saturday %d/%d/%d\n", date->day, date->month, date->year);
            break;

        case 6:
            printf("Sunday %d/%d/%d\n", date->day, date->month, date->year);
            break;
    }
}

int main(void) {
    Date_t date = setDate(MONDAY, 20, 7, 1969);
    printDate(&date);
}