#include "long_int.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

long_int find_remainder(long_int number1, int number2) //number1 % number2
{
    long_int div = div.dividing_long_int_and_int(number1, number2);
    long_int multipl = multipl.multiplication_long_int_and_int(div, number2);
    long_int remainder = remainder.difference_long_int_and_long_int(number1, multipl);
    return remainder;
}

vector <int> vector_sum(vector <int> vector1, vector <int> vector2)
{
    vector <int> result;
    int memory = 0;
    int i = vector1.size() - 1, j = vector2.size() - 1;
    while (i != -1 and j != -1) {
        int sum = vector1[i--] + vector2[j--] + memory;
        memory = sum / 10;
        result.insert(result.begin(), sum % 10);
    }
    if (i == j and memory != 0)
        result.insert(result.begin(), memory);
    else if (i > j) {
        result.insert(result.begin(), vector1[i--] + memory);
        while (i != -1)
            result.insert(result.begin(), vector1[i--]);
    }
    else if (i < j) {
        result.insert(result.begin(), vector2[j--] + memory);
        while (j != -1)
            result.insert(result.begin(), vector2[j--]);
    }
    return result;
}

bool vector1_bigger(vector <int> vector1, vector <int> vector2)
{
    if (vector1.size() > vector2.size())
        return 1;
    if (vector1.size() < vector2.size())
        return 0;
    if (vector1.size() == vector2.size()) {
        size_t i = 0, j = 0;
        while (i != vector1.size()) {
            if (vector1[i] > vector2[j])
                return 1;
            if (vector1[i] < vector2[j])
                return 0;
            i++;
            j++;
        }
    }
    return 0;
}

vector <int> vector_difference(vector <int> vector1, vector <int> vector2) //vector1 - vector2(vector1 >= vector2)
{
    if (vector1 == vector2)
        return { 0 };
    vector <int> result;
    int memory = 0;
    int i = vector1.size() - 1, j = vector2.size() - 1;
        while (j != -1) {
            if (vector1[i] - memory >= vector2[j]) {
                result.insert(result.begin(), vector1[i--] - memory - vector2[j--]);
                memory = 0;
            }
            else {
                result.insert(result.begin(), vector1[i--] - memory + 10 - vector2[j--]);
                memory = 1;
            }
        }
        while (i != -1) {
            if (vector1[i] - memory >= 0) {
                result.insert(result.begin(), vector1[i--] - memory);
                memory = 0;
            }
            else {
                result.insert(result.begin(), vector1[i--] - memory + 10);
                memory = 1;
            }
        }
    while (result[0] == 0)
        result.erase(result.begin());
    return result;
}

vector <int> vector_multiplication(vector <int> vector1, vector <int> vector2)
{
    vector <int> zero = { 0 };
    if (vector1 == zero or vector2 == zero)
        return zero;
    vector <vector<int>> terms;
    for (int i = vector2.size() - 1; i != -1; i--) {
        vector <int> term;
        int memory = 0;
        for (int j = vector1.size() - 1; j != -1; j--) {
            int multiplication = vector1[j] * vector2[i] + memory;
            memory = multiplication / 10;
            term.insert(term.begin(), multiplication % 10);
        }
        if (memory != 0)
            term.insert(term.begin(), memory);
        terms.push_back(term);
    }
    for (int i = 1; i < terms.size(); i++)
        for (int j = 1; j <= i; j++)
            terms[i].push_back(0);
    if (terms.size() == 1)
        return terms[0];
    else {
        vector <int> result = vector_sum(terms[0], terms[1]);
        for (int i = 2; i < terms.size(); i++)
            result = vector_sum(result, terms[i]);
        return result;
   }
}

vector <int> vector_dividing(vector <int> vector1, vector <int> vector2) //vector1 / vector2
{
    vector <int> zero = { 0 };
    if (vector2 == zero)
        return {};
    if (vector1 == vector2)
        return { 1 };
    if (vector1_bigger(vector2, vector1))
        return zero;
    vector <int> current, result;
    int i = 0;
    for (i; vector1_bigger(vector2, current); i++)
        current.push_back(vector1[i]);
    current.pop_back();
    for (i = i - 1; i < vector1.size(); i++) {
        if (current == zero)
            current = {};
        current.push_back(vector1[i]);
        int count = 0;
        while (vector1_bigger(current, vector2) or current == vector2) {
            current = vector_difference(current, vector2);
            count++;
        }
        result.push_back(count);
    }
    return result;
}

long_int::long_int(string str)
{
    if (str[0] == '-' or str[0] == '+') {
        _sign = str[0];
        for (int i = 1; i < str.size(); i++)
            _number.push_back(str[i] - '0');
    }
    else {
        _sign = '+';
        for (int i = 0; i < str.size(); i++)
            _number.push_back(str[i] - '0');
    }
}

char long_int::get_sign()
{
    return _sign;
}

vector <int> long_int::get_number()
{
    return _number;
}

void long_int::print() const
{
    if (_sign == '-') {
        cout << '-';
        for (int i = 0; i < _number.size(); i++)
            cout << _number[i];
    }
    else
        for (int i = 0; i < _number.size(); i++)
            cout << _number[i];
}

long_int long_int::sum_long_int_and_long_int(long_int number1, long_int number2) const
{
    long_int sum("");
    if (number1._sign == number2._sign) {
        sum._sign = number1._sign;
        sum._number = vector_sum(number1._number, number2._number);
        return sum;
    }
    else {
        if (number1._number == number2._number) 
            return long_int("0");
        if (vector1_bigger(number1._number, number2._number) == 1) {
            sum._sign = number1._sign;
            sum._number = vector_difference(number1._number, number2._number);
        }
        else {
            sum._sign = number2._sign;
            sum._number = vector_difference(number2._number, number1._number);
        }
        return sum;
    }
}

long_int long_int::sum_long_int_and_int(long_int long_int_number, int int_number) const
{
    long_int long_int_number2(to_string(int_number));
    return long_int_number.sum_long_int_and_long_int(long_int_number, long_int_number2);
}

long_int long_int::difference_long_int_and_long_int(long_int number1, long_int number2) const //number1-number2
{
    long_int difference("");
    if (number1._sign == '+' and number2._sign == '+') {
        if (number1._number == number2._number) 
            return long_int("0");
        if (vector1_bigger(number1._number, number2._number)) {
            difference._sign = '+';
            difference._number = vector_difference(number1._number, number2._number);
        }
        else {
            difference._sign = '-';
            difference._number = vector_difference(number2._number, number1._number);
        }
        return difference;
    }
    if (number1._sign == '+' and number2._sign == '-') {
        difference._sign = '+';
        difference._number = vector_sum(number1._number, number2._number);
        return difference;
    }
    if (number1._sign == '-' and number2._sign == '+') {
        difference._sign = '-';
        difference._number = vector_sum(number1._number, number2._number);
        return difference;
    }
    if (number1._sign == '-' and number2._sign == '-') {
        long_int example1 = number1, example2 = number2;
        example1._sign = '+';
        example2._sign = '+';
        return difference_long_int_and_long_int(example2, example1);
    }
}

long_int long_int::difference_long_int_and_int(long_int long_int_number, int int_number) const
{
    long_int long_int_number2(to_string(int_number));
    return long_int_number.difference_long_int_and_long_int(long_int_number, long_int_number2);
}

long_int long_int::multiplication_long_int_and_long_int(long_int number1, long_int number2) const
{
    long_int multiplication("");
    multiplication._number = vector_multiplication(number1._number, number2._number);
    vector <int> zero = { 0 };
    if (number1._sign == number2._sign or multiplication._number == zero)
        multiplication._sign = '+';
    else
        multiplication._sign = '-';
    return multiplication;
}

long_int long_int::multiplication_long_int_and_int(long_int long_int_number, int int_number) const
{
    long_int long_int_number2(to_string(int_number));
    return long_int_number.multiplication_long_int_and_long_int(long_int_number, long_int_number2);
}

long_int long_int::dividing_long_int_and_long_int(long_int number1, long_int number2) const
{
    vector <int> nothing = {};
    if (vector_dividing(number1._number, number2._number) == nothing) {
        cout << "Деление на 0!" << endl;
        return long_int("");
    }
    long_int dividing("");
    dividing._number = vector_dividing(number1._number, number2._number);
    vector <int> zero = { 0 };
    if (number1._sign == number2._sign or dividing._number == zero)
        dividing._sign = '+';
    else
        dividing._sign = '-';
    return dividing;

}

long_int long_int::dividing_long_int_and_int(long_int long_int_number, int int_number) const
{
    long_int long_int_number2(to_string(int_number));
    return long_int_number.dividing_long_int_and_long_int(long_int_number, long_int_number2);
}

char long_int::compare_long_int_and_long_int(long_int number1, long_int number2) const
{
    if (number1._sign == '+' and number2._sign == '-')
        return '>';//
    if (number1._sign == '-' and number2._sign == '+')
        return '<';//
    if (number1._number == number2._number)
        return '=';//
    if (number1._sign == '+' and number2._sign == '+')
        if (vector1_bigger(number1._number, number2._number) == 1)
            return '>';//
        else
            return '<';//
    if (number1._sign == '-' and number2._sign == '-')
        if (vector1_bigger(number1._number, number2._number) == 1)
            return '<';//
        else
            return '>';//
}
char long_int::compare_long_int_and_int(long_int long_int_number, int int_number) const
{
    long_int long_int_number2(to_string(int_number));
    return long_int_number.compare_long_int_and_long_int(long_int_number, long_int_number2);
}

long_int operator + (const long_int& number1, const long_int& number2)
{
    return number1.sum_long_int_and_long_int(number1, number2);
}
long_int& operator += (long_int& number1, const long_int& number2)
{
    number1 = number1.sum_long_int_and_long_int(number1, number2);
    return number1;
}

long_int operator + (const long_int& long_int_number, const int& int_number)
{
    return long_int_number.sum_long_int_and_int(long_int_number, int_number);
}

long_int operator += (long_int& long_int_number, const int& int_number)
{
    long_int_number = long_int_number.sum_long_int_and_int(long_int_number, int_number);
    return long_int_number;
}

long_int operator - (const long_int& number1, const long_int& number2)
{
    return number1.difference_long_int_and_long_int(number1, number2);
}

long_int& operator -= (long_int& number1, const long_int& number2)
{
    number1 = number1.difference_long_int_and_long_int(number1, number2);
    return number1;
}

long_int operator - (const long_int& long_int_number, const int& int_number)
{
    return long_int_number.difference_long_int_and_int(long_int_number, int_number);
}

long_int operator -= (long_int& long_int_number, const int& int_number)
{
    long_int_number = long_int_number.difference_long_int_and_int(long_int_number, int_number);
    return long_int_number;
}

long_int operator * (const long_int& number1, const long_int& number2)
{
    return number1.multiplication_long_int_and_long_int(number1, number2);
}

long_int& operator *= (long_int& number1, const long_int& number2)
{
    number1 = number1.multiplication_long_int_and_long_int(number1, number2);
    return number1;
}

long_int operator * (const long_int& long_int_number, const int& int_number)
{
    return long_int_number.multiplication_long_int_and_int(long_int_number, int_number);
}

long_int& operator *= (long_int& long_int_number, const int& int_number)
{
    long_int_number = long_int_number.multiplication_long_int_and_int(long_int_number, int_number);
    return long_int_number;
}

long_int operator / (const long_int& number1, const long_int& number2)
{
    return number1.dividing_long_int_and_long_int(number1, number2);
}

long_int& operator /= (long_int& number1, const long_int& number2)
{
    number1 = number1.dividing_long_int_and_long_int(number1, number2);
    return number1;
}

long_int operator / (const long_int& long_int_number, const int& int_number)
{
    return long_int_number.dividing_long_int_and_int(long_int_number, int_number);
}

long_int& operator /= (long_int& long_int_number, const int& int_number)
{
    long_int_number = long_int_number.dividing_long_int_and_int(long_int_number, int_number);
    return long_int_number;
}

long_int& operator ++ (long_int& number)
{
    long_int increment("1");
    number = number.sum_long_int_and_long_int(number, increment);
    return number;
}

long_int operator ++ (long_int& number, int)
{
    long_int copy = number;
    ++number;
    return copy;
}

long_int& operator -- (long_int& number)
{
    long_int decrement("1");
    number = number.difference_long_int_and_long_int(number, decrement);
    return number;
}

long_int operator -- (long_int& number, int)
{
    long_int copy = number;
    --number;
    return copy;
}

bool operator > (const long_int& number1, const long_int& number2)
{
    if (number1.compare_long_int_and_long_int(number1, number2) == '>')
        return 1;
    else
        return 0;
}

bool operator >= (const long_int& number1, const long_int& number2)
{
    if (number1.compare_long_int_and_long_int(number1, number2) == '>' or number1.compare_long_int_and_long_int(number1, number2) == '=')
        return 1;
    else
        return 0;
}

bool operator < (const long_int& number1, const long_int& number2)
{
    if (number1.compare_long_int_and_long_int(number1, number2) == '<')
        return 1;
    else
        return 0;
}

bool operator <= (const long_int& number1, const long_int& number2)
{
    if (number1.compare_long_int_and_long_int(number1, number2) == '<' or number1.compare_long_int_and_long_int(number1, number2) == '=')
        return 1;
    else
        return 0;
}
bool operator == (const long_int& number1, const long_int& number2)
{
    if (number1.compare_long_int_and_long_int(number1, number2) == '=')
        return 1;
    else
        return 0;
}
bool operator != (const long_int& number1, const long_int& number2)
{
    if (number1.compare_long_int_and_long_int(number1, number2) == '=')
        return 0;
    else
        return 1;
}

bool operator > (const long_int& long_int_number, const int& int_number)
{
    if (long_int_number.compare_long_int_and_int(long_int_number, int_number) == '>')
        return 1;
    else
        return 0;
}

bool operator >= (const long_int& long_int_number, const int& int_number)
{
    if (long_int_number.compare_long_int_and_int(long_int_number, int_number) == '>' or long_int_number.compare_long_int_and_int(long_int_number, int_number) == '=')
        return 1;
    else
        return 0;
}

bool operator < (const long_int& long_int_number, const int& int_number)
{
    if (long_int_number.compare_long_int_and_int(long_int_number, int_number) == '<')
        return 1;
    else
        return 0;
}

bool operator <= (const long_int& long_int_number, const int& int_number)
{
    if (long_int_number.compare_long_int_and_int(long_int_number, int_number) == '<' or long_int_number.compare_long_int_and_int(long_int_number, int_number) == '=')
        return 1;
    else
        return 0;
}
bool operator == (const long_int& long_int_number, const int& int_number)
{
    if (long_int_number.compare_long_int_and_int(long_int_number, int_number) == '=')
        return 1;
    else
        return 0;
}
bool operator != (const long_int& long_int_number, const int& int_number)
{
    if (long_int_number.compare_long_int_and_int(long_int_number, int_number) == '=')
        return 0;
    else
        return 1;
}

ostream& operator << (ostream& out, const long_int& number)
{
    number.print();
    return out;
}

long_int::operator int() const
{
    int int_number = 0;
    int min_int = -2147483648, max_int = 2147483647;
    if ((*this) >= min_int and (*this) <= max_int) {
        int size = _number.size() - 1;
        for (int i = 0; i < _number.size(); i++)
            int_number += _number[i] * pow(10, size--);
    }
    else {
        long_int remainder = find_remainder(*this, pow(2, 31) - 1);
        int size = remainder._number.size() - 1;
        for (int i = 0; i < remainder._number.size(); i++)
            int_number += remainder._number[i] * pow(10, size--);
    }
    if (_sign == '+')
        return int_number;
    else
        return -int_number;

}