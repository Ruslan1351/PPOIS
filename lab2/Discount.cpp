#include "Discount.h"


Discount::Discount(Dish dish, int procent, Date start_date, Date end_date) : _dish(dish), _procent(procent), _start_date(start_date), _end_date(end_date) {}

bool Discount::discount_is_available(Date date)//
{
    return (date >= _start_date and _end_date >= date);
}

bool operator == (const Discount& discount1, const Discount& discount2)
{
    return discount1._dish == discount2._dish and discount1._procent == discount2._procent and discount1._start_date == discount2._start_date and discount1._end_date == discount2._end_date;
}