template <class T>
class stack
{
	int size, i;
	T* mem;
public:
	stack(int s)
	{
		size=s;
		i=-1;
		mem = new T[size];
	}
	stack(const stack &b)
	{
		size=b.size;
		i=b.i;
		mem = new T[size];
		for (int k=0; i<=k; k++)
		{
			b.mem[k]=mem[k];
		}
	}
	T get(T j)
	{
		return mem[j];
	}
	bool isFull()
	{
		return (i==(size-1));
	}
	bool isEmpty()
	{
		return i=-1;
	}
	void push(T a)
	{
		if (isFull()==true) throw -1;
		i++;
		mem[i]=a;
	}
	T pop()
	{
		i--;
		return mem[i+1];
	}
	void print()
	{
		for (int k=0; k<=i; k++)
			cout<<mem[k]<<" ";
		cout<<endl;
	}
};
	
#include <iostream>
using namespace std;

int main()
{
	stack <int> M(100);
	int a, b, cal, i=0;
	cout<<"enter a ";
	cin>>a;
	M.push(a);
	cal=a;
	cout<<"enter action ";
	char g;
	cin>>g;
	while (g!=32)
	{	
		switch (g)
		{
		case 43:
			cout<<"enter b ";
			cin>>b;
			i++;
			M.push(b);
			cal=cal+b;
			cout<<cal<<endl;
			break;
		case 45:
			cout<<"enter b ";
			cin>>b;
			i++;
			M.push(-b);
			cal=cal-b;
			cout<<cal<<endl;
			break;
		case 42:
			cal=cal+M.get(i+1);
			M.push(M.get(i+1));
			i++;
			cout<<cal<<endl;
			break;
		case 47:
			cal=cal-M.get(i);
			M.pop();
			i--;
			cout<<cal<<endl;
			break;
		case 36:
			M.print();
			return 0;
		}
		cout<<"enter action ";
		cin>>g;
	}
	M.print();
	return 0;
}