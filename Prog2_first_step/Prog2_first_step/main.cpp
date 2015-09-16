#include <iostream>
#include <stdlib.h>
using namespace std;

struct time
{
	int days = 3;
	int hours = 8;
	int seconds= 30;
}date;

void main()
{
	int seconds_toadd = 0;

	cout << "How much seconds will you add?";
	cin >> seconds_toadd;
	cout << "before: " << date.days << "d " << date.hours << "h " << date.seconds << "s." << endl;
	void AddSecond(int seconds_toadd);
	cout << "after: " << date.days << "d " << date.hours << "h " << date.seconds << "s." << endl;

	getchar();

}

void AddSecond(int seconds_toadd)
{
	date.seconds += seconds_toadd;
	if (date.seconds > 59)
	{

	}
}