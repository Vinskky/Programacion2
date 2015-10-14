#include <stdio.h>

class Base
{
public:
	char* characters;
	Base(int i){ characters = new char[i];};
	virtual ~Base(){};//amb virtual no fa mem leak.
};

class other :public  Base
{
public:
	int *numbers;
	other(int i) : Base(i)
	{ numbers = new int[i];}
	~other(){ delete[] numbers;}
};

int main()
{
	Base* a = new other(10);
	delete a;
}