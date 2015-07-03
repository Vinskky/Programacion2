#include <stdlib.h>
#include <stdio.h>
#include "p2Rectangle.h"
#include "p2List.h"

#define TEST(A) (A) ? printf("test " #A " success"): printf("test " #A " failure")

using namespace std;

int main()
{
	p2Rectangle<int> r(10, 10, 40, 50);
	p2Rectangle<int> r2(r);
	TEST(r.x == 10);
	TEST(r2.y == 10);
	TEST(r2.GetArea() == 2000);
	TEST(r2.Intersects(r) == true);

	/*String s("Hola Mundo");
	TEST(s.DoubleVocals() == 4);
	TEST(s == "Hoolaa Muundoo");
	*/

	/*sList<int> list;
	list.Add(1);
	list.Add(2);
	list.Add(3);
	list.Add(4);
	list.Add(5);
	list.Add(6);
	list.Add(7);
	list.Flip();
	TEST(list[0] == 7);
	TEST(list[1] == 6);
	TEST(list[2] == 5);
	TEST(list[3] == 4);
	TEST(list[4] == 3);
	TEST(list[5] == 2);
	TEST(list[6] == 1);*/

	getchar();

	return 0;

}