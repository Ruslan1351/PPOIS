#include "Schedule.h"

Schedule::Schedule(vector <bool> days, vector <bool> hours) : _days(days), _hours(hours) {}

bool Schedule::object_is_working(int day, int hour)//
{
    if (_days[day - 1] == 0)
        return 0;
    if (_hours[hour] == 0)
        return 0;
    return 1;
}

bool operator == (const Schedule& schedule1, const Schedule& schedule2) 
{
    return schedule1._days == schedule2._days and schedule1._hours == schedule2._hours;
}