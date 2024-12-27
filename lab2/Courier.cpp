#include "Courier.h"

Courier::Courier(char sex,  string surname, string name, string patronymic, int age, double salary, double balance, Organisation organisation, Transport transport, Schedule schedule, Bag bag, Map map) : Person(sex, name, surname, patronymic, age, salary, balance), _organisation(organisation), _transport(transport), _schedule(schedule), _bag(bag), _map(map) {}
        
void Courier::calculate_delivery_price(int index)//
{
    _organisation._delivery_price = _organisation._delivery_coefficient * _map.calculate_distance(_map._restaurant_coords[index], _map._client_coords);
}

void Courier::took_order(Order order) //
{
    order._status = "В пути";
}

void Courier::delivered_orders(vector <Order> orders)//
{
    for (int i = 0; i < orders.size(); i++)
        orders[i]._status = "Доставлен";
}