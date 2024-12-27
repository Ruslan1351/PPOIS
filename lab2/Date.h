#pragma once
#ifndef DATE_H
#define DATE_H

class Date
{
    public:
        int _day;
        int _month;
        int _year;
        Date(int day, int month, int year);
};

bool operator >= (const Date& date1, const Date& date2);
bool operator == (const Date& date1, const Date& date2);

#endif