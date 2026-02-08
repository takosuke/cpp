#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point& p) : _x(p._x), _y(p._y)
{
}

Point &Point::operator=(const Point& p)
{
	(void)p;
	return *this;
}

Point::~Point(void)
{
}

Fixed Point::getX(void) const
{
	return _x;
}

Fixed Point::getY(void) const
{
	return _y;
}
