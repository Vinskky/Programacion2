#include "DynamicArray.h"
#include <iostream>
#include <time.h>

int main(int argc, char** argv)
{
	DynamicArray<int> a;
	srand(time(NULL));
	for (unsigned int i = 10000; i != 0; i--)
	{
		int r = rand()%100;
		a.PushBack(r);
	}
	/*
	a.PushBack(5);
	a.PushBack(4);
	a.PushBack(10);
	a.PushBack(8);
	a.PushBack(3);
	
	a.Bubble();

	for (int i = 0; i < a.GetNumElements(); i++)
	{
		std::cout << *a.At(i) << std::endl;
	}
	*/
	std::cout << "Bubble counter: " << a.Bubble() << std::endl;

	getchar();
	return 0;

}
