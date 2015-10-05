#include <stdio.h>

void mmswap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

int main()
{
	int a = 8;
	int b = 4;
	printf("abans a = %d b = %d \n", a, b);
	mmswap(a, b);
	printf("despres a = %d b = %d \n", a, b);
	getchar();
	return 0;
}

