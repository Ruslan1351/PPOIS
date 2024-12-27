#pragma once
#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <vector>

using namespace std;

class Schedule
{
    public:
        vector <bool> _days;
        vector <bool> _hours;
        Schedule(vector <bool> days, vector <bool> hours);
        bool object_is_working(int day, int hour);
};

bool operator == (const Schedule& schedule1, const Schedule& schedule2);

#endif