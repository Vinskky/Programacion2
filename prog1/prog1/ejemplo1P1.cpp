#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n1 = 0, n2 = 0;

	printf("give me a number: ");
	scanf_s("%i", &n1);
	printf("give me another number: ");
	scanf_s("%i", &n2);
	printf("the result is %i \n", n1 + n2);

	system("PAUSE");
	return 0;
}