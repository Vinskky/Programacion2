#include <stdio.h>
#include "Stack.h"

int main()
{
	Stack<char> a;
	char var = ' ';

	a.Push('A'); 
	a.Push('B'); 
	a.Push('C'); 
	a.Push('D');
	a.Pop(var);
}