#include "Point.hpp"

Point::Point():x(0),y(0){}

Point::Point(const float nx, const float ny): x(nx),y(ny){}

Point::Point(const Point& other): x(other.x), y(other.y){}

Point& Point::operator=(Point& other)
{
	if (this != &other)
	{
		const_cast<Fixed&>(x) = other.x;
		const_cast<Fixed&>(y) = other.y;
	}
	return *this;
}

Point::~Point(){}

Fixed Point::getX() const
{
	Fixed fixedX(x);
	return fixedX;
}

Fixed Point::getY() const
{
	Fixed fixedY(y);
	return fixedY;
}