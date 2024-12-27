#include "Client.h"
#include <algorithm> 

Client::Client(char sex, string surname, string name, string patronymic, int age, double salary, double balance, Address address, vector <Order> orders, vector <Dish> favorite_dishes) : Person(sex, name, surname, patronymic, age, salary, balance), _address(address), _orders(orders), _favorite_dishes(favorite_dishes) {}
        
void Client::make_order(vector <Dish> dishes, Organisation organisation, Restaurant restaurant)//
{
    Order order(organisation, restaurant, dishes);
    order.calculate_cost();
    _orders.push_back(order);
}

void Client::add_favorite_dish(Dish dish)
{
    _favorite_dishes.push_back(dish);
}
        
void Client::remove_favorite_dish(Dish dish)
{
    _favorite_dishes.erase(find(_favorite_dishes.begin(), _favorite_dishes.end(), dish));
}

void Client::make_order_from_favorite_dishes(Organisation organisation, Restaurant restaurant)
{
    Order order(organisation, restaurant, _favorite_dishes);
    order.calculate_cost();
    _orders.push_back(order);
}

double Client::calculate_final_cost(Courier courier)//
{
    double final_cost = 0;
    for (int i = 0; i < _orders.size(); i++) {
        courier.calculate_delivery_price(i);
        final_cost += _orders[i]._cost + _orders[i]._organisation._delivery_price;
    }
    return round(100*final_cost)/100; 
}
        
void Client::payment(Courier courier)//
{
    double final_cost = calculate_final_cost(courier);
    if (_balance >= final_cost) {
        _balance -= final_cost;
        for (int i = 0; i < _orders.size(); i++) 
            _orders[i].change_status("Оплачен");
    }
    else
        cout << "Недостаточно средств! Заказ не оплачен!" << endl;
}
        
void Client::give_tips(Courier& courier, double tips)//
{
    if (_balance >= tips) {
        courier._balance += tips;
        _balance -= tips;
    }
    else
        cout << "Недостаточно средств!" << endl;
}

void Client::cancel_order(Order order)//
{
    _orders.erase(find(_orders.begin(), _orders.end(), order));
    order._dishes = {};
    order._cost = 0;
    order.change_status("Отменен");
}

string Client::check_order_status(int id)//
{
    return search_order(_orders, id)._status;
}

void Client::leave_review(Organisation& org, string text, int rating, Date date)
{
    Review review(text, rating, date);
    org._reviews.push_back(review);
}