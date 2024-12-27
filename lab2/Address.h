#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>

using namespace std;

class Address
{
    public:
        string _city;
        string _street;
        int _home;
        int _flat;
        Address(string city, string street, int home, int flat);
};

bool operator == (const Address& addr1, const Address& addr2);

#endif