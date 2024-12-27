#include "Menu.h"

Menu::Menu(vector <Dish> dishes ,vector <Discount> discounts) : _dishes(dishes), _discounts(discounts) {}

void Menu::calculate_price_with_discount(Date date)//
{
    for (int i = 0; i < _discounts.size(); i++) {
        int j = search_dish(_dishes, _discounts[i]._dish);
        if (_discounts[i].discount_is_available(date))
            _dishes[j]._price -= _dishes[j]._price * _discounts[i]._procent / 100;
    }
}

void Menu::return_price(Date date)//
{
    for (int i = 0; i < _discounts.size(); i++) {
        int j = search_dish(_dishes, _discounts[i]._dish);
        if (_discounts[i].discount_is_available(date))
            _dishes[j]._price += _dishes[j]._price * _discounts[i]._procent / 100;
    }
}

bool operator == (const Menu& menu1, const Menu& menu2) 
{
    return menu1._dishes == menu2._dishes and menu1._discounts == menu2._discounts;
}