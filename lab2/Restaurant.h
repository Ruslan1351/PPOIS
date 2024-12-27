#pragma once
#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <string>
#include "Address.h"
#include "Schedule.h"
#include "Menu.h"
#include "Dish.h"

using namespace std;

class Restaurant    
{
    public:
        string _name;
        Address _address;
        Schedule _schedule;
        Menu _menu;
        Restaurant(string name, Address address, Schedule schedule, Menu menu);
        void add_dish(Dish dish);
};

bool operator == (const Restaurant& rest1, const Restaurant& rest2);

#endif