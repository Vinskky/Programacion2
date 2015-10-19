#include <stdio.h>

class A
{
public:
	A(int n) : num(n){ }
	int num;
};

int main()
{
	//int b = 4;
	//A* pclass = new A(b);
	A a1(5);
	A b1(a1);
	return 0;
}