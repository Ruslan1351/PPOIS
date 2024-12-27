#pragma once
#ifndef DISH_H
#define DISH_H
#include <string>
#include <vector>

using namespace std;

class Dish
{
    public:
        string _name;
        string _category;
        double _price;
        Dish(string name, string category, double price);
};

bool operator == (const Dish& dish1, const Dish& dish2);

int search_dish(vector <Dish> dishes, Dish dish);

#endif