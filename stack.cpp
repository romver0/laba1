//last_in_first_out или LIFO
/*
#include<iostream>
#include<ctime>
#include<string>

using namespace std;


void input(int *&arr,int size)
{srand(time(0));
    for(int i=0;i<size;i++)
        arr[i]=rand()%156-78;
}
void output(int *&arr,int size)
{
    for(int i=0;i<size;i++)
        cout<<"arr["<<i<<"] = "<<arr[i]<<endl;
}
void push_back(int *&arr,int &size,int value)
{
    int *newArray=new int [size+1];
    for(int i=0;i<size;i++)
        newArray[i]=arr[i];
    newArray[size]=value;
    size++;
    delete []arr;
    arr=newArray;

}

void pop_back(int *&arr,int &size,bool &Bool)
{
    size--;
    if(size>=0)
    {
        
        int *newArray=new int[size];
        for(int i=0;i<size;i++)
            newArray[i]=arr[i];
        delete []arr;
        arr=newArray;
        if(size==0)
        {
            cout<<"Последний элемент уничтожен"<<endl;
            Bool=true;
        }
    }
    else
    {
         Bool=true;
        cout<<"pop_back() не работает для пустого списка"<<endl;
    }
}

bool empty(bool &Bool)
{
    return Bool;
}

string stack_top(int *&arr,int &size,bool &Bool)
{
    if(Bool==false)
        return to_string(arr[size-1]);
    else
        return "Верхушки нет.Не определена для пустого стека.";
}

int main()
{srand(time(0));

    int size=5;
    int *arr=new int[size];
    bool Bool=false;


    input(arr,size);
    
    //push_back(arr,size,-1354);
    //output(arr,size);

    
    pop_back(arr,size,Bool);
    pop_back(arr,size,Bool);
    
    
    
    
    if(empty(Bool)==true)
        cout<<"Стек пуст!"<<endl;
    else 
        cout<<"Нихера он не пуст,иди глянь ещё раз"<<endl;
    cout<<"Если тут верхушка?"<<stack_top(arr,size,Bool)<<endl;
    output(arr,size);

    delete[]arr;
    return 0;
}
*/

//Условие: 2 стека идут навстречу друг другу
/*
#include<iostream>
using namespace std;

void output(int *&arr,int &size)
{
    for(int i=0;i<size;i++)
        cout<<arr[i]<<endl;   
}
void input(int *&arr,int size)
{
    for(int i=0;i<size;i++)
        arr[i]=0;
}
void push1(int *&arr,int &size,int &shag1,int &shag2)
{
    if(size-shag2==shag1)
    {
        cout<<"полномочия push1() закончились"<<endl;
        exit(0);
    }
    arr[shag1]=1;
    shag1++;

}
void pop1(int *&arr,int &size,int &shag1,int &shag2)
{
    if(shag1>-1)
    {   if(shag1==0)
        {
            cout<<"полномочия pop1() закончились"<<endl;
            exit(0);
        }
        shag1--;
        arr[shag1]=0;
    }
}
void push2(int *&arr,int &size,int &shag1,int &shag2)
{
    if(size-shag2==shag1)
    {
        cout<<"полномочия push2() закончились"<<endl;
        exit(0);
    }
    shag2++;
    arr[size-shag2]=-1;
}
void pop2(int *&arr,int &size,int &shag1,int &shag2)
{
    if(shag2>-1)
    {
        if(shag2==0)
        {
            cout<<"полномочия pop2() закончились"<<endl;
            exit(0);
        }
        arr[size-shag2]=0;
        shag2--; 
    }
}
int main()
{
    int size=5;
    int shag1=0;
    int shag2=0;
    int *arr=new int[size];

    input(arr,size);
    push2(arr,size,shag1,shag2);
    push2(arr,size,shag1,shag2);
    push2(arr,size,shag1,shag2);
    push1(arr,size,shag1,shag2);
    pop2(arr,size,shag1,shag2);
    pop2(arr,size,shag1,shag2);
    pop1(arr,size,shag1,shag2);
    pop2(arr,size,shag1,shag2);
    
    
    output(arr,size);


    delete []arr;
    return 0;
}
*/

//Условие:  Реализовать очередь на базе двух стеков. 
//Определить время работы операций с очередью.
/*
#include<iostream>
#include<ctime>

using namespace std;
void push_back(int *&arr,int &size,int value)
{
    int *newArray=new int [size+1];
    for(int i=0;i<size;i++)
        newArray[i]=arr[i];
    newArray[size]=value;
    size++;
    delete []arr;
    arr=newArray;
    //delete []newArray;
}

void pop_back(int *&arr,int &size,bool &Bool)
{
    size--;
    if(size>=0)
    {
        
        int *newArray=new int[size];
        for(int i=0;i<size;i++)
            newArray[i]=arr[i];
        delete []arr;
        arr=newArray;
        if(size==0)
        {
            cout<<"Последний элемент уничтожен"<<endl;
            Bool=true;
        }
    }
    else
    {
         Bool=true;
        cout<<"pop_back() не работает для пустого списка"<<endl;
    }
}

bool empty(bool &Bool)
{
    return Bool;
}

string stack_top(int *&arr,int &size,bool &Bool)
{
    if(Bool==false)
        return to_string(arr[size-1]);
    else
        return "Верхушки нет.Не определена для пустого стека.";
}

void input(int *&arr,int &size)
{
    for(int i=0;i<size;i++)
        arr[i]=i+1;

}
void output(int *&arr,int &size)
{
    for(int i=0;i<size;i++)
        cout<<arr[i]<<endl;
    cout<<endl<<endl;
}
void coup(int *&arr,int &size)
{
    int *newArray=new int[size];
    for(int i=0;i<size;i++)
        newArray[i]=arr[size-i-1];
    delete[]arr;
    arr=newArray;
    
}
int main()
{
    int size=5;
    int *arr=new int[size];
    bool Bool=false;

    input(arr,size);
    push_back(arr,size,19);
    push_back(arr,size,19234);
    output(arr,size);
    coup(arr,size);
    output(arr,size);
    pop_back(arr,size,Bool);
    pop_back(arr,size,Bool);
    pop_back(arr,size,Bool);
    output(arr,size);
    cout << "runtime = " << clock()/1000.0 << endl; // время работы программы 
    delete []arr;

    return 0;
}
*/

//Условие: Реализовать стек на базе 2ух очередей
#include<iostream>
#include<ctime>

using namespace std;

void  queue_straight(int *&arr,int &size) //создание очереди
{
    for(int i=size-1;0<i;i--)
        arr[i]=i;
}
void output(int *&arr,int &size)
{
    for(int i=1;i<size;i++)
        cout<<arr[i]<<endl;
    cout<<endl<<endl;
}
void queue_reverse(int *&arr,int &size)
{
    int *newArray=new int[size];
    for(int i=1;i<size;i++)
        newArray[i]=arr[size-i];
    delete []arr;
    arr=newArray;
     
}

int main()
{srand(time(0));

    int size=5;
    int *arr=new int[size];
    queue_straight(arr,size);
    output(arr,size);
    queue_reverse(arr,size);
    output(arr,size);
    delete []arr;
    return 0;
}

