#pragma once
#ifndef CLIENT_H
#define CLIENT_H
#include "Courier.h"

using namespace std;

class Client : public Person
{
    public:
        Address _address;
        vector <Order> _orders;
        vector <Dish> _favorite_dishes;
        Client(char sex, string surname, string name, string patronymic, int age, double salary, double balance, Address address, vector <Order> orders, vector <Dish> favorite_dishes);
        void make_order(vector <Dish> dishes, Organisation organisation, Restaurant restaurant);
        void add_favorite_dish(Dish dish);
        void remove_favorite_dish(Dish dish);
        void make_order_from_favorite_dishes(Organisation organisation, Restaurant restaurant);
        double calculate_final_cost(Courier courier);
        void payment(Courier courier);
        void give_tips(Courier& courier, double tips);
        void cancel_order(Order order);
        string check_order_status(int id);
        void leave_review(Organisation& org, string text, int rating, Date date);
};

#endif
