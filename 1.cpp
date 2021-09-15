#include<iostream>

using namespace std;

struct A
{
	int key;
};
struct List
{
	A a;
	List* next;
};

void print(List* b)
{
	List* print = b;
	while (print)
	{
		cout << print->a.key << "->";
		print = print->next;
	}
	cout << "NULL"<<endl;
}


int main()
{
    int size=16;
    int N=9;

	List* begin = NULL;
	begin = new List;
	A a[] = { 10,20,3,40,50,58,1,1,2,4,3,1,2,4,5,3};
	begin->a.key = -123;
	begin->next = NULL;
	List* end = begin;
	for (int i = 0; i <size ; i++)
	{
		end->next = new List;
		end = end->next;
		end->a = a[i];
		end->next = NULL;
	}
	print(begin);
    
    end=begin;
    
    //end=end->next;
    //cout<<end->a.key<<endl;
    //end=end->next;
    //cout<<end->a.key;
    
    for(int i=0;i<size+1;i++)
    {
        end->a.key=N*end->a.key;
        end=end->next;    
    }
    
    print(begin);

	return 0;
}