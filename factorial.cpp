/*Перепишите код из листинга 5.4 с использованием объекта array вместо встроенного массива и типа long double вместо long long.
Найдите значение 100!*/
#include <iostream>
#include <array>
using namespace std;

int main()
{
    const int ArSize = 101;
    array<long double, ArSize> factorials;
    factorials[1] = factorials[0] = 1LL;
    for (int i = 2; i < ArSize; i++)
        factorials[i] = i * factorials[i-1];
    for (int i = 0; i < ArSize; i++)
        cout << i << "! = " << factorials[i] << endl;


    return 0;
}


