#ifndef _Rectangle_H_
#define _Rectangle_H_

template <class TYPE>

class p2Rectangle
{
public:
	TYPE x, y, w, h;

	p2Rectangle(TYPE _x, TYPE _y, TYPE _w, TYPE _h)
	{
		x = _x;
		y = _y;
		w = _w;
		h = _h;
	}

	p2Rectangle(const p2Rectangle& r)
	{
		x = r.x;
		y = r.y;
		w = r.w;
		h = r.h;
	}

	TYPE GetArea()const
	{
		return w * h;
	}

	bool Intersects(const p2Rectangle rect2)const
	{
		if (y <= rect2.y + rect2.h &&
			rect2.x + rect2.w >= x &&
			rect2.y <= y + h &&
			x + w >= rect2.x)
			return true;
		return false;
	}

};


#endif _Rectangle_H_
