#pragma once
#ifndef DISCOUNT_H
#define DISCOUNT_H
#include <vector>
#include "Dish.h"
#include "Date.h"

using namespace std;

class Discount
{
    public:
        Dish _dish;
        int _procent;
        Date _start_date;
        Date _end_date;
        Discount(Dish dish, int procent, Date start_date, Date end_date);
        bool discount_is_available(Date date);
};

bool operator == (const Discount& discount1, const Discount& discount2);

#endif