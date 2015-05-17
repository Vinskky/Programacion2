#ifndef _Point2d_H_
#define _Point2d_H_


template <class TYPE2>
class Point2d
{
public:
	TYPE2 x, y;

	Point2d operator - (const Point2d &a)const
	{
		Point2d result;
		result.x = x - a.x;
		result.y = y - a.y;
		return result;
	}

	Point2d operator + (const Point2d &v) const
	{
		p2Vector2 r;

		r.x = x + v.x;
		r.y = y + v.y;

		return(r);
	}

	const Point2d& operator -=(const Point2d &v)
	{
		x -= v.x;
		y -= v.y;

		return(*this);
	}

	const Point2d& operator +=(const Point2d &v)
	{
		x += v.x;
		y += v.y;

		return(*this);
	}

	bool operator ==(const Point2d& v) const
	{
		return (x == v.x && y == v.y);
	}

	bool operator !=(const Point2d& v) const
	{
		return (x != v.x || y != v.y);
	}

	// Utils ------------------------------------------------
	bool IsZero() const
	{
		return (x == 0 && y == 0);
	}

	Point2d& SetToZero()
	{
		x = y = 0;
		return(*this);
	}

	Point2d& Negate()
	{
		x = -x;
		y = -y;

		return(*this);
	}

	// Distances ---------------------------------------------
	TYPE2 DistanceTo(const Point2d& v) const
	{
		TYPE2 fx = x - v.x;
		TYPE2 fy = y - v.y;

		return sqrt((fx*fx) + (fy*fy));
	}
};





#endif _Point2d_H_