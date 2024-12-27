#include "Transport.h"
#include <cmath>

Transport::Transport(string type, int speed, string mark) : _type(type), _speed(speed), _mark(mark) {}

double Transport::calculate_fuel_consumption(double distance) //
{
    double fuel_rate = 0.1; 
    return round(100*distance * fuel_rate)/100;
}

double Transport::calculate_travel_time(double distance)//
{
    return round(100*distance/_speed)/100;
}

bool operator == (const Transport& transport1, const Transport& transport2)
{
    return transport1._type == transport2._type and transport1._speed == transport2._speed and transport1._mark == transport2._mark;
}