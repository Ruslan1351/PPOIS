#include "Date.h"

Date::Date(int day, int month, int year) : _day(day), _month(month), _year(year) {}

bool operator >= (const Date& date1, const Date& date2) 
{
    if (date1._year > date2._year)
        return 1;
    if (date1._year < date2._year)
        return 0;
    if (date1._month > date2._month)
        return 1;
    if (date1._month < date2._month)
        return 0;
    if (date1._day >= date2._day)
        return 1;
    return 0;
}

bool operator == (const Date& date1, const Date& date2) 
{
    return date1._day == date2._day and date1._month == date2._month and date1._year == date2._year;
}