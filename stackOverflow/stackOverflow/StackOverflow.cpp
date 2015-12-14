#include <stdio.h>
#include <stdlib.h>
double factorial(double);

int main()
{
	double val2;

	printf("introdueix un numero: \n");
	scanf_s("%d", &val2);

	double result = factorial(val2);

	printf("%d ", result);
	
	system("pause");
	return 0;
}

double factorial(double value)
{
	if (valu
		e > 1)
		return value * factorial(value - 1);
	else
		return 1;
}