#include "DynamicArray.h"
#include <iostream>

int main()
{
	DynamicArray<int> a;
	a.PushBack(5);
	a.PushBack(4);
	a.PushBack(10);
	a.PushBack(8);
	a.PushBack(3);
	
	a.Bubble();

	for (int i = 0; i < a.GetNumElements(); i++)
	{
		std::cout << &a[i] << std::endl;
	}

	return 0;
	
}