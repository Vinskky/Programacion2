#ifndef _Circle_H_
#define _Circle_H_

#define PI 3.1415

template <class TYPE>
class Circle
{
public: 
	TYPE x, y, r;

	void Circle(TYPE& _x, TYPE& _y, TYPE& radium)
	{
		this.x = _x;
		this.y = _y;
		this.r = radium;
	}

	TYPE GetArea()const
	{
		return PI * r * r;
	}

	bool Distance( const Circle circle2)const
	{
		TYPE result = sqrt((this.x - circle2.x)*(this.x - circle2.x) + (this.y - circle2.y)*(this.y - circle2.y))
			if (result > (this.radium + circle2.radium))
				return true;
		return false;
	}

};

#endif _Circle_H_