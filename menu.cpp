/*Напишите предшественник программы, управляемой меню. Она должна отображать меню из четырех пунктов, каждый из них помечен буквой.
Если пользователь вводит букву, отличающуюся от четырех допустимых, программа должна повторно приглашать его ввести правильное
значение до тех пор, пока он этого не сделает. Затем она должна выполнить некоторое простое действие на основе пользовательского выбора.
Работа программы должна выглядеть примерно так:
Please enter one of the following choises:
c) carnivore p) pianist
t) tree g) game
f
Please enter a c, p, t, or g: q
Please enter a c, p, t, or g: t
A maple is a tree.*/
#include <iostream>

using namespace std;
void showmenu();
int main()
{
     showmenu();
     cout << endl;
     char choise;
     cin >> choise;
     while (choise)
     {
         switch (choise){
         case 'c':
         case 'C': cout << "A maple is a carnivore" << endl;
             break;
         case 'p':
         case 'P': cout << "A maple is a pianist" << endl;
             break;
         case 't':
         case 'T': cout << "A maple is a tree" << endl;
             break;
         case 'g':
         case 'G': cout << "A maple is a game" << endl;
             break;
         default : showmenu(); cout << endl;
         }
      cin >> choise;
     }
    return 0;
}

void showmenu()
{
    cout << "Please enter one of the following choises: " << endl
         << "c) carnivore " << "\t" << "p) pianist" << endl
         << "t) tree " << "\t" << "g) game";
}
