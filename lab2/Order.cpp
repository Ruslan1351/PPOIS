#include "Order.h"
#include <algorithm> 
#include <optional>
#include <stdexcept>

vector<int> Order::_ids;

Order::Order(Organisation organisation, Restaurant restaurant, vector <Dish> dishes) : _organisation(organisation), _restaurant(restaurant), _dishes(dishes)  
{
    do {
        _id = rand();
    }
    while (find(_ids.begin(), _ids.end(), _id) != _ids.end());
     _ids.push_back(_id);
     _cost = 0;
    _status = "Ждет оплаты";
}  

void Order::calculate_cost()//
{
    for (int i = 0 ; i < _dishes.size(); i++)
        _cost += _dishes[i]._price;
}

void Order::add_dish(Dish dish)//
{
    _dishes.push_back(dish);    
    _cost += dish._price;
}

void Order::change_status(string status)//
{
    _status = status;
}

Order search_order(vector <Order> orders, int id)//
{
    for (int i = 0; i < orders.size(); i++)
        if (orders[i]._id == id)
            return orders[i];

    throw std::runtime_error("Some shit heppend");
}

bool operator == (const Order& order1, const Order& order2)
{
    return (order1._id == order2._id);
}