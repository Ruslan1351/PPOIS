#include "Dish.h"

Dish::Dish(string name, string category, double price) : _name(name), _category(category), _price(price) {}


bool operator == (const Dish& dish1, const Dish& dish2)
{
    return dish1._name == dish2._name and dish1._category == dish2._category and dish1._price == dish2._price;
}

int search_dish(vector <Dish> dishes, Dish dish)
{
    for (int i = 0; i < dishes.size(); i++)
        if (dishes[i] == dish)
            return i;
    return -1;        
}