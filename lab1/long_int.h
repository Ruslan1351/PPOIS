#pragma once
#ifndef LONG_INT_H
#define LONG_INT_H
#include <vector>
#include <string>

using namespace std;

class long_int
{
private:
    vector <int> _number;
    char _sign;
public:
    long_int(string str);
    char get_sign();
    vector <int> get_number();
    void print() const;
    operator int() const;
    long_int sum_long_int_and_long_int(long_int number1, long_int number2) const;
    long_int sum_long_int_and_int(long_int long_int_number, int int_number) const;
    long_int difference_long_int_and_long_int(long_int number1, long_int number2) const;
    long_int difference_long_int_and_int(long_int long_int_number, int int_number) const;
    long_int multiplication_long_int_and_long_int(long_int number1, long_int number2) const;
    long_int multiplication_long_int_and_int(long_int long_int_number, int int_number) const;
    long_int dividing_long_int_and_long_int(long_int number1, long_int number2) const;
    long_int dividing_long_int_and_int(long_int long_int_number, int int_number) const;
    char compare_long_int_and_long_int(long_int number1, long_int number2) const;
    char compare_long_int_and_int(long_int long_int_number, int int_number) const;
};

long_int find_remainder(long_int number1, int number2);
vector <int> vector_sum(vector <int> vector1, vector <int> vector2);
bool vector1_bigger(vector <int> vector1, vector <int> vector2);
vector <int> vector_difference(vector <int> vector1, vector <int> vector2);
vector <int> vector_multiplication(vector <int> vector1, vector <int> vector2);
vector <int> vector_dividing(vector <int> vector1, vector <int> vector2);
long_int operator + (const long_int& number1, const long_int& number2);
long_int& operator += (long_int& number1, const long_int& number2);
long_int operator + (const long_int& long_int_number, const int& int_number);
long_int operator += (long_int& long_int_number, const int& int_number);
long_int operator - (const long_int& number1, const long_int& number2);
long_int& operator -= (long_int& number1, const long_int& number2);
long_int operator - (const long_int& long_int_number, const int& int_number);
long_int operator -= (long_int& long_int_number, const int& int_number);
long_int operator * (const long_int& number1, const long_int& number2);
long_int& operator *= (long_int& number1, const long_int& number2);
long_int operator * (const long_int& long_int_number, const int& int_number);
long_int& operator *= (long_int& long_int_number, const int& int_number);
long_int operator / (const long_int& number1, const long_int& number2);
long_int& operator /= (long_int& number1, const long_int& number2);
long_int operator / (const long_int& long_int_number, const int& int_number);
long_int& operator /= (long_int& long_int_number, const int& int_number);
long_int& operator ++ (long_int& number);
long_int operator ++ (long_int& number, int);
long_int& operator -- (long_int& number);
long_int operator -- (long_int& number, int);
bool operator > (const long_int& number1, const long_int& number2);
bool operator >= (const long_int& number1, const long_int& number2);
bool operator < (const long_int& number1, const long_int& number2);
bool operator <= (const long_int& number1, const long_int& number2);
bool operator == (const long_int& number1, const long_int& number2);
bool operator != (const long_int& number1, const long_int& number2);
bool operator > (const long_int& long_int_number, const int& int_number);
bool operator >= (const long_int& long_int_number, const int& int_number);
bool operator < (const long_int& long_int_number, const int& int_number);
bool operator <= (const long_int& long_int_number, const int& int_number);
bool operator == (const long_int& long_int_number, const int& int_number);
bool operator != (const long_int& long_int_number, const int& int_number);
ostream& operator << (ostream& out, const long_int& number);

#endif

#pragma once