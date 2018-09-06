/*Структура CandyBar содержит три члена. Первый из них хранит название коробки конфет. Второй - ее вес
(который может иметь дробную часть), а третий - число калорий (целое значение). Напишите программу, объявляющую
эту структуру и создающую переменную типа CandyBar по имени snack, инициализируя ее члены значениями "Mocha Munch",
2.3 и 350, соответственно. Инициализация должна быть частью объявдения snack. И, наконец, программа должна отобразить
содержимое этой переменной.*/
#include <iostream>

using namespace std;
struct CandyBar{
    string sweets;
    double weight;
    int calories;

};

CandyBar snack{
    "Mocha Munch",
    2.3,
    350
};



int main()
{
    cout << "Name sweets: " << snack.sweets << "\n"
         << "Weight: " << snack.weight << "\n"
         << "Calories: " << snack.calories;

    return 0;
}







