#include "Person.h"

Person::Person(char sex, string name, string surname, string patronymic, int age, double salary, double balance) : _sex(sex), _name(name), _surname(surname), _patronymic(patronymic), _age(age), _salary(salary), _balance(balance) {}

void Person::salary_change(double percent)
{
    _salary += _salary * percent / 100;
}

void Person::replenishment_of_balance_by_salary()
{
    _balance += _salary;
}

void Person::replenishment_of_balance(double count)
{
    _balance += count;
}