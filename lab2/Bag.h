#pragma once
#ifndef BAG_H
#define BAG_H
#include <iostream>
#include <vector>
#include "Dish.h"

using namespace std;

class Bag
{
    public:
        int _capacity;
        vector <Dish> _content;
        Bag(int capacity);
        void add_dish(Dish dish);
        void remove_dish(Dish dish);
};

bool operator ==( const Bag& bag1, const Bag& bag2);

#endif