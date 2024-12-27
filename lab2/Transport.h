#pragma once
#ifndef TRANSPORT_H
#define TRANSPORT_H
#include <string>

using namespace std;

class Transport
{
    public:
        string _type;
        int _speed;
        string _mark;   
        Transport(string type, int speed, string mark);
        double calculate_fuel_consumption(double distance);
        double calculate_travel_time(double distance);
};

bool operator == (const Transport& transport1, const Transport& transport2);

#endif