#include<iostream>
#include<ctime>
#include<cmath>

using namespace std;

void input(double *&arr,int &size)
{srand(time(0));
    
    double timer=0,value=0;
    
    for(int i=0;i<size;i++)
    {   
        value=double(rand())/RAND_MAX;
        timer= round(value*100)/100;
        arr[i]=timer;
    }
}
void output(double *&arr,int &size,int &k)
{
    if(size-k>=0)
    {
    cout<<"Очередь состоит из "<<size-k<<":"<<endl;
        for(int i=0+k;i<size;i++)
            cout<<"Клиент№"<<i+1<<" и его время: "<<arr[i]<<endl;
    }
    else
        cout<<"Список пуст!"<<endl;
    
 cout<<endl;
}
void pop_back(double *&arr,int &size,bool &queue,int &k)
{
    
    if(size-k>=0)
    {   
        double *newArray=new double[size];
        
        for(int i=size;0<i-k;i--)
            newArray[i]=arr[i];
        k++;

        delete []arr;
        arr=newArray;
        if(size-k==0)
        {
            queue=false;
            cout<<"Последний клиент обслужен"<<endl;
        }
    }
    else
    {
    
        cout<<"pop_back() не работает для пустого списка"<<endl;
    }
}

void InsQueue(double *&arr,bool &queue,int &size,double value)
{   
    queue=true;
    double *newArray=new double [size+1];
    for(int i=0;i<size;i++)
        newArray[i]=arr[i];
    newArray[size]=value;
    size++;
    delete []arr;
    arr=newArray;
}

bool EmptyQueue(bool &queue)
{
    return queue;
}

int main()
{
    int size=10;
    int k=0;
    bool queue=true;
    double *arr=new double[size];

    input(arr,size);
    output(arr,size,k);
    pop_back(arr,size,queue,k);
    pop_back(arr,size,queue,k);
    pop_back(arr,size,queue,k); 
    pop_back(arr,size,queue,k);
    pop_back(arr,size,queue,k);
    pop_back(arr,size,queue,k);
    pop_back(arr,size,queue,k); 
    pop_back(arr,size,queue,k);
    pop_back(arr,size,queue,k);
    pop_back(arr,size,queue,k);
    //InsQueue(arr,queue,size,-1000);
    //InsQueue(arr,size,-100);
    //InsQueue(arr,size,-100);
    //InsQueue(arr,size,-100);
    //InsQueue(arr,size,-100);
    output(arr,size,k);
    cout<<"EmptyQueue: "<<EmptyQueue(queue)<<endl;
    
    delete []arr;
    return 0;
}