#include <stdio.h>
#include <stdlib.h>

class Point
{
public:
	int x, y;

	Point& operator = (Point& a)
	{
		x = a.x;
		y = a.y;
		return *this;
	}

	bool operator == (Point& a)const
	{
		if (x == a.x && y == a.y)
			return true;
		return false;
	}

	bool operator != (Point& a)const
	{
		if (x == a.x && y == a.y)
			return false;
		return true;
	}

	Point& operator +=(Point& a)
	{
		x += a.x;
		y += a.y;
		return *this;
	}

	Point& operator -=(Point& a)
	{
		x -= a.x;
		y -= a.y;
		return *this;
	}

	Point& operator + (Point& a)
	{
		x = x + a.x;
		y = y + a.y;
		return *this;
	}

	Point& operator - (Point& a)
	{
		x = x - a.x;
		y = y - a.y;
		return *this;
	}

	bool Iszero()const 
	{
		if (x == 0 && y == 0)
			return true;
		return false;
	}

	void Setzero()
	{
		x = 0;
		y = 0;
	}

	void Negate()
	{
		if (x > 0 && y > 0)
		{
			x = (-1)* x;
			y = (-1)* y;
		}
		
	}
};

int main()
{
	Point a, b;
	a.x = 10;
	a.y = 6;
	b.x = 3;
	b.y = 4;

	b.Negate();
	printf(" %d %d", b.x, b.y);

	getchar();
	return 0;

}