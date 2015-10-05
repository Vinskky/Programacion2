#include <stdio.h>

void my_function(int* num)
{
	*num = 15;
}

int main()
{
	int a = 3;
	my_function(&a);
	printf("%i", a);
	getchar();
	return  0;
}