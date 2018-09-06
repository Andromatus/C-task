#include <iostream>
/*Напишите программу C++, которая запрашивает и отображает информацию, как показано в следующем
примере вывода:
What is your first name? Betty Sue
What is your last name? Yewe
What letter grade do you deserve? B
What is your age? 22
Name: Yewe, Betty Sue
Grade: C
Age: 22
Обратите внимание, что программа должна принимать имена, состоящие из более чем одного слова. Кроме того, программа должна уменьшать
значение grade на одну градацию - т.е. на одну букву выше. Предполагается, что пользователь может ввести А, В и С, поэтому вам не
нужно беспокоиться о пропуске между D и F*/
using namespace std;

int main()
{
    const int ArSize = 20;
    char first_name[ArSize];
    char last_name[ArSize];
    cout << "What is your fist name? ";
    cin.getline(first_name,ArSize);
    cout << "What is your last name? ";
    cin.getline(last_name, ArSize);
    cout << "What letter grade do you deserve? ";
    char grade;
    cin >> grade;
    grade = ++grade;
    cout << "What is your age? ";
    int age;
    cin >> age;
    cout << "Name: " << last_name << ", " << first_name << endl;
    cout << "Grade: " << grade << endl;
    cout << "Age: " << age;
    return 0;
}
