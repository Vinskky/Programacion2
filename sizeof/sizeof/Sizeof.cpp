#include <stdio.h>
#include <iostream>

struct point
{
	int x = 2;
	int y = 3;
};
struct rect
{
	point a, b;
};

using namespace std;
void test(int a[15]);
int AreaRect(rect* a);

int main()
{
	rect a;
	printf( "%d",AreaRect(&a));
	//char* a[] = {"dilluns","dimarts","dimecres","dijous","divendres","dissabte","diumenge"};
	//int a[15];
	//cout << sizeof(a);
	//printf("%s", a[0]);
	//int* b = a;
	//cout << sizeof(b) << endl;
	//test(a);
	getchar();
	return 0;
}

void test(int a[15])
{
	cout<<sizeof(a);

}
int AreaRect(rect* a)
{
	return a->a.x*a->b.y;
}