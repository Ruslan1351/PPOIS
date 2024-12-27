#include "Bag.h"
#include <algorithm> 

using namespace std;

Bag::Bag(int capacity) : _capacity(capacity) 
{
    _content = {};
}

void Bag::add_dish(Dish dish)
{
    if (_content.size() < _capacity)
        _content.push_back(dish);
    else
        cout << "Сумка переполнена! Блюдо " << dish._name << " не добавлено!" << endl;
}

void Bag::remove_dish(Dish dish)
{
    _content.erase(find(_content.begin(), _content.end(), dish));
}

bool operator == ( const Bag& bag1, const Bag& bag2) 
{
    return bag1._capacity == bag2._capacity and bag1._content == bag2._content;
}