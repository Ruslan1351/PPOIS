#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <string>

using namespace std;

class Person
{
    public:
        char _sex;
        string _name;
        string _surname;
        string _patronymic;
        int _age;  
        double _salary;
        double _balance;
        Person(char sex, string name, string surname, string patronymic, int age, double salary, double balance);
        void salary_change(double percent);
        void replenishment_of_balance_by_salary();
        void replenishment_of_balance(double count);
};

#endif