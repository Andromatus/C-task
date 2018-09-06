/*Напишите программу, которая приглашает пользователя ввести его имя и фамилию, а затем построит, сохранит и отобразит
третье строку, состоящую из фамилии, за которой следует запятая, пробел и имя. Используйте объекты string и методы из заголовочного
файла string и методы из заголовочного файла string. Пример запуска должен выглядеть так:
Enter your first name: Flip
Enter your last name: Fleming
Here's the information in a single string: Fleming, Flip*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Enter your first name: ";
    string s1;
    cin >> s1;
    cout << "Enter your last name: ";
    string s3;
    cin >> s3;
    s3 += ", ";
    cout << "Here's the information in a single string: "
         << s3 << s1;

    return 0;
}
