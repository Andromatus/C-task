/*Напишите программу, которая использует массив char и цикл для чтения по одному слову за раз до тех пор, пока не будет введено слово
done. Затем программа должна сообщить количество введенных слов (исключая done). Пример запуска должен быть таким:
Вводите слова (для завершения введите слово done):
anteater birthday category dumpster
envy finagle geometry done for sure
Вы ввели 7 слов
Вы должны включить заголовочный файл cstring и применять функцию strcmp() для выполнения проверки.*/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char word[80];
    int count = 0;
    cout << "Enter the words (to complete, enter the word done): ";
    while (strcmp(word,"done")){
        cin >> word;
    count++;
}
    cout << "You have entered " << count << " words";

    return 0;
}
