#include "Address.h"

Address::Address(string city, string street, int home, int flat) : _city(city), _street(street), _home(home), _flat(flat) {}

bool operator == (const Address& addr1, const Address& addr2) 
{
    return addr1._city == addr2._city and addr1._street == addr2._street and addr1._home == addr2._home and addr1._flat == addr2._flat;
}