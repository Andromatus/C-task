/*Напишите программу, которая приглашает пользователя вводить числа. После каждого введенного значения программа должна выдавать накопленную
сумму введенных значений. Программа должна завершиться при вводе 0.*/
#include <iostream>

using namespace std;

int main()
{
    int number;
    int sum = 0;
    cout << "Enter number: ";
    do{
        cin >> number;
        sum += number;
    } while (number != 0);
    cout << "sum: " << sum;

    return 0;
}
