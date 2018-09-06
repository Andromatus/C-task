#include <iostream>
#include <ctime>
#include <cstdlib>
#include<conio.h>
#include<string.h>
#define N 20

using namespace std;
template <typename ArrayType>
struct Array {
public:
    Array(); // конструктор по умолчанию
    Array(const int size); // конструктор с параметром
    Array(const Array &); // конструктор копирования
    virtual ~Array(); // виртуальный деструктор
     
    void insert(const int index, const ArrayType value); // вставить элемент по индексу
    void append(const Array<ArrayType> &); // добавить другой массив
    void resize(const int size); // размер массив
    void remove(const int index); // удалить элемент по индексу
    void clear(); // очистить элемент массива
    int getSize() const; // получить текущий размер массива
     
    ArrayType &operator[] (const int index); //получить элемент по индексу для изменения значения
    const ArrayType &operator[] (const int index) const; // получить только для чтения элемент по индексу
 
    const Array<ArrayType> &operator = (const Array<ArrayType> &); // установить другой массив
     
protected:
    ArrayType *array; 
    int currentSize;
private:    
 
    void shiftLeft(int from, int to); // сворачивает налево для операции удаления
    void shiftRight(int from, int to); // перевод права на операции удаления
};
 // конструктор по умолчанию
template <typename ArrayType>
Array<ArrayType>::Array() {
    currentSize = 0;	//обнуляем размер
	array=NULL;			//и указатель на массив
}
// конструктор с параметром
template <typename ArrayType>
Array<ArrayType>::Array(const int size) {
    currentSize = 0;	//обнуляем размер
	array=NULL;			//и указатель на массив
    resize(size);		//Задаем размер
}
// конструктор копирования 
template <typename ArrayType>
Array<ArrayType>::Array(const Array &object) {
    currentSize = 0;	//обнуляем размер
	array=NULL;			//и указатель на массив
    *this = object;		//Копируем массив
}
// виртуальный деструктор 
template <typename ArrayType>
Array<ArrayType>::~Array() {
    if (array) {		//Если массив выделен
        free(array);	//освобождаем его
    }
}
// добавить другой массив 
template <typename ArrayType>
void Array<ArrayType>::append(const Array<ArrayType> &object) {
    int lastIndex = getSize();	//получить размер текущего массива
    resize(lastIndex + object.getSize());		//изменить его размер с учетом нового
    for (int i = 0; i < object.getSize(); i++) {	//добавить элементы второго массива
        array[lastIndex] = object[i];				//к текущему
        lastIndex++;
    }
}
// вставить элемент по индексу 
template <typename ArrayType>
void Array<ArrayType>::insert(const int index, const ArrayType value) {
    if (index < currentSize)	//Если индекс меньше размера массива
    {
        resize(currentSize+1);	//То увеличиваем массив на 1
        shiftRight(index, currentSize-1);	//сдвигаем часть после вставки вправо
    } else {
        resize(index + 1);		//Если индекс больше или равен размеру увеличиваем массив, чтобы можно было вставить индекс
    }
    array[index] = value;		//вставляем элемент
}
 //изменение размера массива
template <typename ArrayType>
void Array<ArrayType>::resize(const int size) 
{
    if (size == currentSize)	//Если размер тот же
        return;					//то выйти
    if (size == 0)				//если он стал=0
       array = (ArrayType *) malloc(sizeof(ArrayType));	//выделить 1 элемент
    else
       array = (ArrayType *) realloc(array, size * sizeof(ArrayType));	//иначе изменяем размер по кол-ву элементов
    currentSize = size;		//запомнить новый размер массива
}
 // удалить элемент по индексу
template <typename ArrayType>
void Array<ArrayType>::remove(const int index) {
    if (index >= 0 && index < currentSize) {	//если индекс в допустимых пределах
        currentSize--;					//уменьшаем размемр массива
        shiftLeft(index, currentSize);	//слвигаем массив влево
    }
}
 // очистить массив
template <typename ArrayType>
void Array<ArrayType>::clear() {
    for (int i = 0; i < currentSize; i++)	//цикл по элементам массива
        array[i] = ArrayType();				//очистка
}
 
// сворачивает налево для операции удаления 
template <typename ArrayType>
void Array<ArrayType>::shiftLeft(int from, int to) {
    for (int i = from; i < to; i++) {	//Цикл перестановки элементов слева направо
        array[i] = array[i + 1];
    }
}
//сдвиг вправо для вставки 
template <typename ArrayType>
void Array<ArrayType>::shiftRight(int from, int to) {
    for (int i = to; i >= from; i--) {	//Цикл перестановки элементов справа налево
        array[i] = array[i - 1];
    }
}
 //получить размер массива
template <typename ArrayType>
int Array<ArrayType>::getSize() const {
    return currentSize;	//вернуть размер
}
 //получить элемент по индексу для изменения значения
template <typename ArrayType>
ArrayType &Array<ArrayType>::operator[](const int index) {
    return array[index];	
}
// получить только для чтения элемент по индексу 
template <typename ArrayType>
const ArrayType &Array<ArrayType>::operator[](const int index) const {
    return array[index];
}
//поместить один массив в другой 
template <typename ArrayType>
const Array<ArrayType> &Array<ArrayType>::operator = (const Array<ArrayType> &object) {
    resize(object.getSize());	//Изменить размер меняемого массива
    for (int i = 0; i < currentSize; i++) {	//Перенос значений в новый массив
        array[i] = object[i];
    }
    return *this;	//вернуть указатель на измененный массив
}
//вывод массива 
template <typename ArrayType>
std::ostream &operator << (std::ostream &stream, const Array<ArrayType> &array) {
    for (int i = 0; i < array.getSize(); i++) { //Цикл по элементам массива
        std::cout << array[i] << " ";	//вывести очередной элемент
    }
    return stream;
}

struct MArray //объявление структуры массив
{
	//--------элементы данные--------
	int *Arr; //указатель (адрес начала памяти, выделенной для массива)
	int Size; //количество элементов
	//------------"Установка" значений элементов-данных------------
	void SetArr(int n)
	{
		Arr=new int[n]; //выделение памяти
		Size=n; //определение количества
	}
	//---------Конструктор по умолчанию, выделяем память под 10 элементов---------
	MArray(int num=10)
	{
		SetArr (num);
	}
	//------------------Конструктор копирования------------------
	MArray (const MArray &a) //передача по ссылке, const "защищает" от изменений
	{
		Size=a.Size;
		Arr=new int [Size];
		for(int i=0; i<Size; i++)
		Arr[i]=a.Arr[i];
	}
	//-----------------------------------------------------------------
	MArray& operator=(const MArray &b) //перезагрузка оператора присвания
	{
		if(&b!=this)
		{
			Size=b.Size;
			delete []Arr;
			Arr=new int[Size];
			for (int i=0; i<Size; i++) 
			Arr[i]=b.Arr[i];
		}
		return *this;
	}
	//-----------------------------------------------------------------
	// Перегрузка операторов сравнения
	int operator>(MArray &right)		
	{
	
		if (Size > right.Size) return 1;	
		if (Size == right.Size)				
			for(int i = 0; i<Size; i++)		
				if(Arr[i] > right.Arr[i])	
					return 1;				
		return 0;	
	}
	int operator<(MArray &right)		
	{
		if (Size < right.Size) return 1;		
		if (Size == right.Size)           		                              
			for(int i = 0; i<right.Size; i++)	                                   
				if(Arr[i] < right.Arr[i])          
					return 1;                                                  
		return 0;	
	}
	int operator==(MArray &right)	
	{
		if (Size != right.Size) return 0;	
		for(int i = 0; i<Size; i++)       	                            
			if(Arr[i] != right.Arr[i])                                  
				return 0;                   
		return 1;                                   
	}
	//-------------------------------------------------------------
	friend ostream &operator<<(ostream &output, const MArray &m)
	{
		int i=0;
		while (i<m.Size)
		{
			output<<*(m.Arr+i);
			i++;
			if(i<m.Size) output << ",";
		}
		return output;
	}
	//-----------------------------------------------------------------
	friend istream &operator>>(istream &input, MArray &m)
	{
		int i=0;
		cout<<"\nSkolko elemenotv: "<<endl;
		cin >> m.Size;
		cout<<"\nVvedite "<<m.Size<<" elementov:"<<endl;
		while(i<m.Size)
		{
			input>>*(m.Arr+i);
			i++;
		}
		return input;
	}
};
template <class T>
struct list
	{
		T data;
		list *next;
	};
template <class T>
list <T> *Ins_first(list <T> *head,T n) // Включение в начало
	{
		list <T> *g=new list<T>; //создание нового элемента списка
		g->data=n; //запомнить данные
		if(head!=NULL) g->next=head; //если список не пуст, вставить в начало
		else g->next=NULL; //иначе это будет первый элемент списка
		return g; //вернуть новую голову списка
	}
template <class T>
void Print_list(list <T> *head) //Печать списка
	{
		list <T> *t=head;
		cout << endl << endl << "Massiv:  ";
		while(t!=NULL) //Перебор пока не достигнем конца списка
		{
			cout << t->data;
			t=t->next; //переход к след элементу
			if(t != NULL)
				cout << "  -->  ";
		}
	}
template <class T>
list <T>*Ins_end(list <T>*head,T n)  //Включение в конец
	{
		list <T> *q=new list <T>,*t=head; //создание нового элемента списка
		q->data=n; //запомнить данные
		q->next=NULL; //следующего элемента нет
		if(head==NULL)return q; //Если это первый элемент в списке, вернуть его
		while(t->next!=NULL) //перебор пока не будет найден последний элемент
		t=t->next; //переход к след элементу
		t->next=q; //Дописать элемент в хвост списка
		return head; //и вернуть старую голову
	}
template <class T>
list <T> *Create_list(list<T>* first)
	{
		T num;
		int i=0;
		puts("Vvodi chisla.(0-konez vvoda)");
		while (i<1) //Цикл ввода чисел
		{
			cin>>num;
			first=Ins_end(first,num); //добавление в хвост
			i++;
		}
		return first; //вернуть голову
	}
template <class T>
list <T> *Del_first(list<T>*head) //Удаление из начала списка
	{
		list <T> *t; 
		if(head==NULL) //если список пуст
		{
			puts("Spisok pust"); //вывести сообщение
			return NULL; //и вернуть 0
		}
		if(head->next==NULL) //Если в списке один элемент
		{
			delete head; //удалить его
			return NULL; //и вернуть 0
		}
		t=head->next; //иначе новой головой будет следующий за ней эдемент
		delete head; //удалить старую голову
		return t; //и вернуть новую
	}
template <class T>
list <T> *Del_end(list <T> *head) //Удаление из конца списка
	{
		list <T> *t;
		if(head==NULL) //если список пуст
		{
			puts("Spisok pust"); //вывести сообщение
			return NULL; //и вернуть 0
		}
		if(head->next==NULL) //Если в списке один элемент
		{
			delete head; //удалить его
			return NULL; //и вернуть 0
		}
		t=head;
		//Поиск предпоследнего элемента
		while (t->next->next!=NULL) //перебор пока не будет найден предпоследний элемент
		t=t->next; //перейти к следующему
		delete t->next; //удалить последний элемент
		t->next=NULL; //сделать его последним
		return head; //вернуть голову списка
	}
template <class T>
list <T> *Del_znach(list <T> *head,T n) //Удаление по значению
	{
		list <T> *t,*y;
		if(head == NULL) //если список пуст
		{
			puts("Spisok pust"); //вывести сообщение
			return NULL; //и вернуть 0
		}
		if(head->next == NULL) //Если в списке один элемент
		{
			delete head; //удалить его
			return NULL; //и вернуть 0
		}
		if(head->data == n) //если удаляемое значение в голове
		{
			t=head->next; //новой головой будет следующий за ней элемент
			delete head; //удалить старую голову
			return t; //и вернуть новую
		}
		t=head;
		//Поиск элемента по значению
		while(t->next!=NULL) //пока не достигнем конца списка
		if(t->next->data==n) //если данный найдены в следующем элементе
		{
			y=t->next; //запомнить его указатель
			t->next=t->next->next; //убрать его из списка
			delete y; //и удалить из памяти
			return head;//вернуть голову
		}
		else
		t=t->next; //иначе переход к следующему элементу
		puts("Znachenie net v spiske"); //если дошли сюда, то не нашли
		return head; //вернуть голову
	}
template <class T>
list <T> *Ins_Sort(list <T> *head, T n) //Включение с сохранением упорядоченности 
	{
	list <T> *q=new list <T>, *t; //создание нового элемента списка
	q->data=n; //запомнить данные
	q->next=NULL; //обнулить указатель на след элемент
	if(head==NULL) return q; //Если это первый элемент в списке, вернуть его
	if(head->data>q->data) //Если его нужно вставлять в голову списка
	{
		q->next=head; //то вставить в голову
		return q; //и вернуть новую голову
	}
	t=head;
	//ищем место вставки
	while(t->next!=NULL) //Перебор пока не достигнем конца списка
	if(t->next->data>q->data) //Если нашли место вставки
	{
		q->next=t->next; //вставляем
		t->next=q;
		return head; //и возвращаем старую голову
	}
	else t=t->next; //иначе переходим к след элементу
	t->next=q; //Если дошли сюда, то вставляем в конец списка
	return head; //и возвращаем старую голову
}
void menuList()
{
	cout <<"1 - Add Head"<<endl
	<<"2 - Add End"<<endl
	<<"3 - Delete Head"<<endl
	<<"4 - Delete End"<<endl
	<<"5 - Delete Znach"<<endl
	<<"6 - Ins Sort"<<endl
	<<"7 - Compare"<<endl;
}
int main()
{
	{
           srand(time(0));
     
    Array<int> first;
    int size;
    std::cout << "Enter amount of elements for first array" << std::endl;
    std::cin >> size;
    first.resize(size);
    std::cout << "Enter " << size << " elements" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> first[i];
    }
     
    std::cout << "First array before deleting item:" << std::endl;
    std::cout << first << std::endl;
     
    int index, value;
    std::cout << "Enter index and value of item for inserting" << std::endl;
    std::cin >> index >> value;
    first.insert(index, value);
    std::cout << "First array after inserting item:" << std::endl;
    std::cout << first << std::endl;
 
     
    std::cout << "Enter index of item for deleting" << std::endl;
    std::cin >> index;
    first.remove(index);
    std::cout << "First array after deleting item:" << std::endl;
    std::cout << first << std::endl;
     
     
    Array<int> second;
    std::cout << "Enter amount of elements for second array" << std::endl;
    std::cin >> size;
    second.resize(size);
    std::cout << "Enter " << size << " elements" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> second[i];
    }
    std::cout << "Second array:" << std::endl;
    std::cout << second << std::endl;
     
     
    first.append(second);
    std::cout << "First array after appending second array:" << std::endl;
    std::cout << first << std::endl;
    system("pause");
	list <MArray>*my_list=NULL;
	int choice;
	MArray val;
	int arra, arrb;
	list <MArray>*A=NULL;
	list <MArray>*B=NULL;
	menuList();
	do {
		cout<<"\n?";
		cin>>choice;
		switch(choice) 
	{
		case 1:
			cout<<"Insert First:";
			cin>>val;
			my_list=Ins_first(my_list,val);
			Print_list(my_list);
			break;
		case 2:
			cout<<"Insert Last:";
			cin>>val;
			my_list=Ins_end(my_list,val);
			Print_list(my_list);
		    break;
        case 3:
			cout<<"Delete Znach:";
			cin>>val;
			my_list=Del_znach(my_list,val);
			Print_list(my_list);
		    break;             
	    case 4:
			cout<<"Delete first:";
			my_list=Del_first(my_list);
			Print_list(my_list);
		    break;
		case 5:
			cout<<"Delete Last:";
			my_list=Del_end(my_list);
			Print_list(my_list);
		    break;
		case 6:
			cout<<"Insert Sort:";
			cin>>val;
			my_list=Ins_Sort(my_list,val);
			Print_list(my_list);
		    break;   
		case 7:
			cout<<"Pervyi massiv to compare:";
			cin>>arra;								
			cout<<"Second array to compare:";
			cin>>arrb;								
			A = my_list;				
			B = my_list;				
			for(int i=0; i<arra; i++)	
				if(A != NULL)			
					A = A->next;		
				else					
				{
					cout << "First array bad index"; 
					break;							 
				}
			for(int i=0; i<arrb; i++)	
				if(B != NULL)
					B = B->next;
				else
				{
					cout << "Second array bad index";
					break;
				}
			if(A->data > B->data) cout << "Mas" << arra << " > Mas" << arrb;
			else 
				if(A->data == B->data) cout << "Mas" << arra << " = Mas" << arrb;
			else 
				if(A->data < B->data) cout << "Mas" << arra << " < Mas" << arrb;
			Print_list(my_list);
		    break;
	}
} 	
while (choice!=8); getch();
}
}

	


    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
   
