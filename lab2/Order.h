#pragma once
#ifndef ORDER_H
#define ORDER_H
#include <vector>
#include <string>
#include "Dish.h"
#include "Organisation.h"

using namespace std;

class Order
{
    public:
        static vector <int> _ids;
        int _id;
        vector <Dish> _dishes;
        double _cost;
        string _status;
        Organisation _organisation;  
        Restaurant _restaurant;
        Order(Organisation organisation, Restaurant restaurant, vector <Dish> dishes);
        //Order() = default;
        void calculate_cost();
        void add_dish(Dish dish);
        void change_status(string status);
};

Order search_order(vector <Order> orders, int id);
bool operator == (const Order& order1, const Order& order2);

#endif