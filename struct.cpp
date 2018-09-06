/*Вильям Вингейт (Wiliam Wingate) заведует службой анализа рынка пиццы. О каждой пицце он записывает следующую информацию:
* наименрвание компании - производителя пиццы, которое может состоять из более чем одного слова;
* диаметр пиццы;
* вес пиццы;
* Разработайте структуру, которая может содержать всю эту информацию, и напишите программу, использующую структурную переменную этого
типа. Программа должна запрашивать у пользователя каждый их перечисленных показателей и затем отображать введенную информацию.
Применяйте cin (или его методы) и cout. */
#include <iostream>

using namespace std;

int main()
{
    struct pizza{
        string name_product;
        int diametr;
        int weight;
    };
    pizza pizza1;
    cout << "Enter company name: ";
    getline (cin, pizza1.name_product);
    cout << "Enter the diameter of the pizza: ";
    cin >> pizza1.diametr;
    cout << "Enter the weight of the pizza: ";
    cin >> pizza1.weight;

    cout << "Company name: " << pizza1.name_product << endl
         << "Diameter of the pizza: " << pizza1.diametr << endl
         << "Weight of the pizza: " << pizza1.weight;

    return 0;
}
