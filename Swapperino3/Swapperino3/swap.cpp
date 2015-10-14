#include <stdio.h>
#include <stdlib.h>
void swap(int a, int b)
{
	int c;
	c = a;
	a = b;
	b = c;
}
void swap(float a, float b)
{
	float c;
	c = a;
	a = b;
	b = c;
}
void swap(char a, char b)
{
	char c;
	c = a;
	a = b;
	b = c;
}

int main()
{
	int x = 2, y = 3;
	float a = 2.1, b = 3.1;;
	char z = 'a', c = 'c';
	printf("%d %d %.2f %.2f %c %c \n", x, y, a, b, z, c);
	swap(x, y);
	swap(a, b);
	swap(z, c);
	printf("%d %d %.2f %.2f %c %c \n", x, y, a, b, z, c);
	system("pause");
}