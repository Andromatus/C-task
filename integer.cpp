/*Напишите программу, запрашивающую у пользователя ввод двух целых чисел. Затем программа должна вычислять и выдать сумму всех целых
чисел, лежащих между двумя целыми. Предполагается, что меньшее значение вводится первым. Например, если пользователь ввел 2 и 9,
программа должна ссобщить, что сумма всех целых чисел от 2 до 9 равна 44*/

#include <iostream>

using namespace std;

int main()
{
    int integer1, integer2, integer3, sum_integers;
    cout << "Enter two integers: ";
    cin >> integer1 >> integer2;
    integer3 = integer1 +1;
    sum_integers = integer1 + integer3;
    while (integer3 < integer2){
        ++integer3;
        sum_integers += integer3;
    }
    cout << "Sum of integers: " << sum_integers;






    return 0;
}
