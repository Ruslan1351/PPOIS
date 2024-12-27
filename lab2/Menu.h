#pragma once
#ifndef MENU_H
#define MENU_H
#include <vector>
#include "Dish.h"
#include "Discount.h"
#include "Date.h"

using namespace std;

class Menu
{
    public:
        vector <Dish> _dishes;
        vector <Discount> _discounts;
        Menu(vector <Dish> dishes ,vector <Discount> discounts);
        void calculate_price_with_discount(Date date);
        void return_price(Date date);
};

bool operator == (const Menu& menu1, const Menu& menu2);

#endif