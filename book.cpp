/*Предположим, что вы продаете книгу по программированию на языке C++ для начинающих. Напишите программу, которая позволит внести
емемесячные объемы продаж в течение года (в количестве книг, а не в деньгах). Программа должна использовать цикл, в котором выводится
приглашение с названием месяца, применяя массив указателей на char (или массив объектов string, если вы предпочитаете его),
инициализированный строками - названиями месяцев, и сохраняя введенные значениями в массиве int. Затем программа должна найти сумма
содержимого массива и выдать общий объем продаж за год.*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string months1;
    string months[13];
    int sales[13];
    int sales1;
    int sum;

    for (int i = 1; i < 13; i++){
        cout << "Enter the months " << i << " month: ";
        cin >> months1;
        months[i] = months1;
        cout << "Enter the number of books sold " << i << " month: ";
        cin >> sales1;
        sales[i] = sales1;
        sum += sales[i];


    }
    cout << "Total sales for the year: " << sum;

    return 0;
}



