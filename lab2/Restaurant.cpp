#include "Restaurant.h"

Restaurant::Restaurant(string name, Address address, Schedule schedule, Menu menu) : _name(name), _address(address), _schedule(schedule), _menu(menu) {}

void Restaurant::add_dish(Dish dish) //
{
    _menu._dishes.push_back(dish);
}

bool operator == (const Restaurant& rest1, const Restaurant& rest2) 
{
    return rest1._name == rest2._name and rest1._address == rest2._address and rest1._schedule == rest2._schedule and rest1._menu == rest2._menu;
}