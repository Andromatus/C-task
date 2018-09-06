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
    Array(); 
    Array(const int size); 
    Array(const Array &); 
    virtual ~Array(); 
     
    void insert(const int index, const ArrayType value); 
    void append(const Array<ArrayType> &); 
    void resize(const int size); 
    void remove(const int index); 
    void clear(); 
    int getSize() const; 
     
    ArrayType &operator[] (const int index); 
    const ArrayType &operator[] (const int index) const; 
 
    const Array<ArrayType> &operator = (const Array<ArrayType> &); 
     
protected:
    ArrayType *array; 
    int currentSize;
private:    
 
    void shiftLeft(int from, int to); 
    void shiftRight(int from, int to); 
};
 
template <typename ArrayType>
Array<ArrayType>::Array() {
    currentSize = 0;	
	array=NULL;			
}

template <typename ArrayType>
Array<ArrayType>::Array(const int size) {
    currentSize = 0;	
	array=NULL;			
    resize(size);		
}

template <typename ArrayType>
Array<ArrayType>::Array(const Array &object) {
    currentSize = 0;	
	array=NULL;			
    *this = object;		
}

template <typename ArrayType>
Array<ArrayType>::~Array() {
    if (array) {		
        free(array);	
    }
}

template <typename ArrayType>
void Array<ArrayType>::append(const Array<ArrayType> &object) {
    int lastIndex = getSize();	
    resize(lastIndex + object.getSize());		
    for (int i = 0; i < object.getSize(); i++) {	
        array[lastIndex] = object[i];				
        lastIndex++;
    }
}

template <typename ArrayType>
void Array<ArrayType>::insert(const int index, const ArrayType value) {
    if (index < currentSize)	
    {
        resize(currentSize+1);	
        shiftRight(index, currentSize-1);	
    } else {
        resize(index + 1);		
    }
    array[index] = value;		
}
 
template <typename ArrayType>
void Array<ArrayType>::resize(const int size) 
{
    if (size == currentSize)	
        return;					
    if (size == 0)				
       array = (ArrayType *) malloc(sizeof(ArrayType));	
    else
       array = (ArrayType *) realloc(array, size * sizeof(ArrayType));	
    currentSize = size;		
}
 
template <typename ArrayType>
void Array<ArrayType>::remove(const int index) {
    if (index >= 0 && index < currentSize) {	
        currentSize--;					
        shiftLeft(index, currentSize);	
    }
}
 
template <typename ArrayType>
void Array<ArrayType>::clear() {
    for (int i = 0; i < currentSize; i++)	
        array[i] = ArrayType();				
}
 

template <typename ArrayType>
void Array<ArrayType>::shiftLeft(int from, int to) {
    for (int i = from; i < to; i++) {	
        array[i] = array[i + 1];
    }
}

template <typename ArrayType>
void Array<ArrayType>::shiftRight(int from, int to) {
    for (int i = to; i >= from; i--) {	
        array[i] = array[i - 1];
    }
}
 
template <typename ArrayType>
int Array<ArrayType>::getSize() const {
    return currentSize;	
}
 
template <typename ArrayType>
ArrayType &Array<ArrayType>::operator[](const int index) {
    return array[index];	
}

template <typename ArrayType>
const ArrayType &Array<ArrayType>::operator[](const int index) const {
    return array[index];
}

template <typename ArrayType>
const Array<ArrayType> &Array<ArrayType>::operator = (const Array<ArrayType> &object) {
    resize(object.getSize());	
    for (int i = 0; i < currentSize; i++) {	
        array[i] = object[i];
    }
    return *this;	
}

template <typename ArrayType>
std::ostream &operator << (std::ostream &stream, const Array<ArrayType> &array) {
    for (int i = 0; i < array.getSize(); i++) { 
        std::cout << array[i] << " ";	
    }
    return stream;
}

struct MArray 
{
	
	int *Arr; 
	int Size; 
	
	void SetArr(int n)
	{
		Arr=new int[n]; 
		Size=n; 
	}
	
	MArray(int num=10)
	{
		SetArr (num);
	}
	
	MArray (const MArray &a) 
	{
		Size=a.Size;
		Arr=new int [Size];
		for(int i=0; i<Size; i++)
		Arr[i]=a.Arr[i];
	}
	//-----------------------------------------------------------------
	MArray& operator=(const MArray &b) 
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
list <T> *Ins_first(list <T> *head,T n) 
	{
		list <T> *g=new list<T>; 
		g->data=n; 
		if(head!=NULL) g->next=head; 
		else g->next=NULL; 
		return g; 
	}
template <class T>
void Print_list(list <T> *head) //Печать списка
	{
		list <T> *t=head;
		cout << endl << endl << "Massiv:  ";
		while(t!=NULL) 
		{
			cout << t->data;
			t=t->next; 
			if(t != NULL)
				cout << "  -->  ";
		}
	}
template <class T>
list <T>*Ins_end(list <T>*head,T n) 
	{
		list <T> *q=new list <T>,*t=head;
		q->data=n; 
		q->next=NULL; 
		if(head==NULL)return q; 
		while(t->next!=NULL) 
		t=t->next; 
		t->next=q; 
		return head; 
	}
template <class T>
list <T> *Create_list(list<T>* first)
	{
		T num;
		int i=0;
		puts("Vvodi chisla.(0-konez vvoda)");
		while (i<1) 
		{
			cin>>num;
			first=Ins_end(first,num); 
			i++;
		}
		return first; 
	}
template <class T>
list <T> *Del_first(list<T>*head) 
	{
		list <T> *t; 
		if(head==NULL) 
		{
			puts("Spisok pust"); 
			return NULL; 
		}
		if(head->next==NULL) 
		{
			delete head; 
			return NULL; 
		}
		t=head->next; 
		delete head; 
		return t; 
	}
template <class T>
list <T> *Del_end(list <T> *head) 
	{
		list <T> *t;
		if(head==NULL) 
		{
			puts("Spisok pust"); 
			return NULL; 
		}
		if(head->next==NULL) 
		{
			delete head; 
			return NULL; 
		}
		t=head;
		
		while (t->next->next!=NULL) 
		t=t->next;
		delete t->next; 
		t->next=NULL; 
		return head; 
	}
template <class T>
list <T> *Del_znach(list <T> *head,T n) 
	{
		list <T> *t,*y;
		if(head == NULL) 
		{
			puts("Spisok pust"); 
			return NULL; 
		}
		if(head->next == NULL) 
		{
			delete head; 
			return NULL; 
		}
		if(head->data == n) 
		{
			t=head->next; 
			delete head; 
			return t; 
		}
		t=head;
		
		while(t->next!=NULL) 
		if(t->next->data==n) 
		{
			y=t->next; 
			t->next=t->next->next; 
			delete y; 
			return head;
		}
		else
		t=t->next; 
		puts("Znachenie net v spiske"); 
		return head; 
	}
template <class T>
list <T> *Ins_Sort(list <T> *head, T n) 
	{
	list <T> *q=new list <T>, *t; 
	q->data=n; 
	q->next=NULL; 
	if(head==NULL) return q; 
	if(head->data>q->data) 
	{
		q->next=head; 
		return q; 
	}
	t=head;
	
	while(t->next!=NULL) 
	if(t->next->data>q->data) 
	{
		q->next=t->next; 
		t->next=q;
		return head; 
	}
	else t=t->next; 
	t->next=q; 
	return head; 
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

	


    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
   
