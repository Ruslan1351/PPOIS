#include "long_int.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    setlocale(0, "");
    int flag = 1;
    while (flag == 1) {
        int key;
        cout << "Выберите действие(введите число):" << endl;
        cout << "1 - преобразование длинного целого к целому" << endl;
        cout << "2 - long_int + long_int" << endl;
        cout << "3 - long_int += long_int" << endl;
        cout << "4 - long_int + int" << endl;
        cout << "5 - long_int += int" << endl;
        cout << "6 - long_int - long_int" << endl;
        cout << "7 - long_int -= long_int" << endl;
        cout << "8 - long_int - int" << endl;
        cout << "9 - long_int -= int" << endl;
        cout << "10 - long_int * long_int" << endl;
        cout << "11 - long_int *= long_int" << endl;
        cout << "12 - long_int * int" << endl;
        cout << "13 - long_int *= int" << endl;
        cout << "14 - long_int / long_int" << endl;
        cout << "15 - long_int /= long_int" << endl;
        cout << "16 - long_int / int" << endl;
        cout << "17 - long_int /= int" << endl;
        cout << "18 - ++long_int" << endl;
        cout << "19 - long_int++" << endl;
        cout << "20 - --long_int" << endl;
        cout << "21 - long_int--" << endl;
        cout << "22 - long_int > long_int" << endl;
        cout << "23 - long_int >= long_int" << endl;
        cout << "24 - long_int < long_int" << endl;
        cout << "25 - long_int <= long_int" << endl;
        cout << "26 - long_int > int" << endl;
        cout << "27 - long_int >= int" << endl;
        cout << "28 - long_int < int" << endl;
        cout << "29 - long_int <= int" << endl;
        cout << "30 - выход из меню" << endl;
        cin >> key;
        switch (key) {
        case 1:
        {
            cout << "Введите длинное целое: ";
            string str;
            cin >> str;
            long_int number(str);
            cout << "Целое: " << (int)number << endl;
            break;
        }
        case 2:
        {
            string str1, str2;
            cout << "Введите первое длинное целое(n1): ";
            cin >> str1;
            cout << "Введите второе длинное целое(n2): ";
            cin >> str2;
            long_int n1(str1), n2(str2);
            cout << n1 << " + " << n2 << " = " << n1 + n2 << endl;
            break;
        }
        case 3:
        {
            string str1, str2;
            cout << "Введите первое длинное целое(n1): ";
            cin >> str1;
            cout << "Введите второе длинное целое(n2): ";
            cin >> str2;
            long_int n1(str1), n2(str2);
            cout << n1 << " += " << n2 << ": ";
            n1 += n2;
            cout << n1 << endl;
            break;
        }
        case 4:
        {
            string str1;
            int n2;
            cout << "Введите длинное целое(n1): ";
            cin >> str1;
            cout << "Введите целое(n2): ";
            cin >> n2;
            long_int n1(str1);
            cout << n1 << " + " << n2 << " = " << n1 + n2 << endl;
            break;
        }
        case 5:
        {
            string str1;
            int n2;
            cout << "Введите длинное целое(n1): ";
            cin >> str1;
            cout << "Введите целое(n2): ";
            cin >> n2;
            long_int n1(str1);
            cout << n1 << " += " << n2 << ": ";
            n1 += n2;
            cout << n1 << endl;
            break;
        }
        case 6:
        {
            string str1, str2;
            cout << "Введите первое длинное целое(n1): ";
            cin >> str1;
            cout << "Введите второе длинное целое(n2): ";
            cin >> str2;
            long_int n1(str1), n2(str2);
            cout << n1 << " - " << n2 << " = " << n1 - n2 << endl;
            break;
        }
        case 7:
        {
            string str1, str2;
            cout << "Введите первое длинное целое(n1): ";
            cin >> str1;
            cout << "Введите второе длинное целое(n2): ";
            cin >> str2;
            long_int n1(str1), n2(str2);
            cout << n1 << " -= " << n2 << ": ";
            n1 -= n2;
            cout << n1 << endl;
            break;
        }
        case 8:
        {
            string str1;
            int n2;
            cout << "Введите длинное целое(n1): ";
            cin >> str1;
            cout << "Введите целое(n2): ";
            cin >> n2;
            long_int n1(str1);
            cout << n1 << " - " << n2 << " = " << n1 - n2 << endl;
            break;
        }
        case 9:
        {
            string str1;
            int n2;
            cout << "Введите длинное целое(n1): ";
            cin >> str1;
            cout << "Введите целое(n2): ";
            cin >> n2;
            long_int n1(str1);
            cout << n1 << " -= " << n2 << ": ";
            n1 -= n2;
            cout << n1 << endl;
            break;
        }
        case 10:
        {
            string str1, str2;
            cout << "Введите первое длинное целое(n1): ";
            cin >> str1;
            cout << "Введите второе длинное целое(n2): ";
            cin >> str2;
            long_int n1(str1), n2(str2);
            cout << n1 << " * " << n2 << " = " << n1 * n2 << endl;
            break;
        }
        case 11:
        {
            string str1, str2;
            cout << "Введите первое длинное целое(n1): ";
            cin >> str1;
            cout << "Введите второе длинное целое(n2): ";
            cin >> str2;
            long_int n1(str1), n2(str2);
            cout << n1 << " *= " << n2 << ": ";
            n1 *= n2;
            cout << n1 << endl;
            break;
        }
        case 12:
        {
            string str1;
            int n2;
            cout << "Введите длинное целое(n1): ";
            cin >> str1;
            cout << "Введите целое(n2): ";
            cin >> n2;
            long_int n1(str1);
            cout << n1 << " * " << n2 << " = " << n1 * n2 << endl;
            break;
        }
        case 13:
        {
            string str1;
            int n2;
            cout << "Введите длинное целое(n1): ";
            cin >> str1;
            cout << "Введите целое(n2): ";
            cin >> n2;
            long_int n1(str1);
            cout << n1 << " *= " << n2 << ": ";
            n1 *= n2;
            cout << n1 << endl;
            break;
        }
        case 14:
        {
            string str1, str2;
            cout << "Введите первое длинное целое(n1): ";
            cin >> str1;
            cout << "Введите второе длинное целое(n2): ";
            cin >> str2;
            long_int n1(str1), n2(str2);
            cout << n1 << " / " << n2 << " = " << n1 / n2 << endl;
            break;
        }
        case 15:
        {
            string str1, str2;
            cout << "Введите первое длинное цело4е(n1): ";
            cin >> str1;
            cout << "Введите второе длинное целое(n2): ";
            cin >> str2;
            long_int n1(str1), n2(str2);
            cout << n1 << " /= " << n2 << ": ";
            n1 /= n2;
            cout << n1 << endl;
            break;
        }
        case 16:
        {
            string str1;
            int n2;
            cout << "Введите длинное целое(n1): ";
            cin >> str1;
            cout << "Введите целое(n2): ";
            cin >> n2;
            long_int n1(str1);
            cout << n1 << " / " << n2 << " = " << n1 / n2 << endl;
            break;
        }
        case 17:
        {
            string str1;
            int n2;
            cout << "Введите длинное целое(n1): ";
            cin >> str1;
            cout << "Введите целое(n2): ";
            cin >> n2;
            long_int n1(str1);
            cout << n1 << " /= " << n2 << ": ";
            n1 /= n2;
            cout << n1 << endl;
            break;
        }
        case 18:
        {
            string str;
            cout << "Введите длинное целое(n): ";
            cin >> str;
            long_int n(str);
            cout << "++" << n << ": ";
            cout << ++n << endl;
            break;
        }
        case 19:
        {
            string str;
            cout << "Введите длинное целое(n): ";
            cin >> str;
            long_int n(str);
            cout << n << "++: ";
            cout << n++ << endl;
            cout << "n = " << n << endl;
            break;
        }
        case 20:
        {
            string str;
            cout << "Введите длинное целое(n): ";
            cin >> str;
            long_int n(str);
            cout << "--" << n << ": ";
            cout << --n << endl;
            break;
        }
        case 21:
        {
            string str;
            cout << "Введите длинное целое(n): ";
            cin >> str;
            long_int n(str);
            cout << n << "--: ";
            cout << n-- << endl;
            cout << "n = " << n << endl;
            break;
        }
        case 22:
        {
            string str1, str2;
            cout << "Введите первое длинное целое(n1): ";
            cin >> str1;
            cout << "Введите второе длинное целое(n2): ";
            cin >> str2;
            long_int n1(str1), n2(str2);
            cout << n1 << " > " << n2 << ": " << (n1 > n2) << endl;
            break;
        }
        case 23:
        {
            string str1, str2;
            cout << "Введите первое длинное целое(n1): ";
            cin >> str1;
            cout << "Введите второе длинное целое(n2): ";
            cin >> str2;
            long_int n1(str1), n2(str2);
            cout << n1 << " >= " << n2 << ": " << (n1 >= n2) << endl;
            break;
        }
        case 24:
        {
            string str1, str2;
            cout << "Введите первое длинное целое(n1): ";
            cin >> str1;
            cout << "Введите второе длинное целое(n2): ";
            cin >> str2;
            long_int n1(str1), n2(str2);
            cout << n1 << " < " << n2 << ": " << (n1 < n2) << endl;
            break;
        }
        case 25:
        {
            string str1, str2;
            cout << "Введите первое длинное целое(n1): ";
            cin >> str1;
            cout << "Введите второе длинное целое(n2): ";
            cin >> str2;
            long_int n1(str1), n2(str2);
            cout << n1 << " <= " << n2 << ": " << (n1 <= n2) << endl;
            break;
        }
        case 26:
        {
            string str1;
            int n2;
            cout << "Введите длинное целое(n1): ";
            cin >> str1;
            cout << "Введите целое(n2): ";
            cin >> n2;
            long_int n1(str1);
            cout << n1 << " > " << n2 << ": " << (n1 > n2) << endl;
            break;
        }
        case 27:
        {
            string str1;
            int n2;
            cout << "Введите длинное целое(n1): ";
            cin >> str1;
            cout << "Введите целое(n2): ";
            cin >> n2;
            long_int n1(str1);
            cout << n1 << " >= " << n2 << ": " << (n1 >= n2) << endl;
            break;
        }
        case 28:
        {
            string str1;
            int n2;
            cout << "Введите длинное целое(n1): ";
            cin >> str1;
            cout << "Введите целое(n2): ";
            cin >> n2;
            long_int n1(str1);
            cout << n1 << " < " << n2 << ": " << (n1 < n2) << endl;
            break;
        }
        case 29:
        {
            string str1;
            int n2;
            cout << "Введите длинное целое(n1): ";
            cin >> str1;
            cout << "Введите целое(n2): ";
            cin >> n2;
            long_int n1(str1);
            cout << n1 << " <= " << n2 << ": " << (n1 <= n2) << endl;
            break;
        }
        case 30:
        {
            flag = 2;
            break;
        }
        default:
            cout << "Введено число не от 1 до 30!" << endl;
        }
    }
}