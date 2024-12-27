#pragma once
#ifndef COURIER_H
#define COURIER_H
#include <vector>
#include <string>
#include "Coordinates.h"
#include "Person.h"
#include "Organisation.h"
#include "Transport.h"
#include "Bag.h"
#include "Map.h"
#include "Order.h"


using namespace std;

class Courier : public Person
{
    public:
        Organisation _organisation;
        Transport _transport;
        Schedule _schedule;
        Bag _bag;
        Map _map;
        Courier(char sex,  string surname, string name, string patronymic, int age, double salary, double balance, Organisation organisation, Transport transport, Schedule schedule, Bag bag, Map map);  
        void calculate_delivery_price(int index);
        void took_order(Order order);
        void delivered_orders(vector <Order> orders);
};

#endif