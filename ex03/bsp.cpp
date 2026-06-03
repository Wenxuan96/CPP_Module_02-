#include "Point.hpp"

// calculates which side of the line is the current point located at
Fixed crossProduct(Point const a, Point const b, Point const c)
{
	Fixed crossn((b.getX() - a.getX()) * (c.getY() - a.getY())
         - (b.getY() - a.getY()) * (c.getX() - a.getX()));

    return crossn;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed d1 = crossProduct(a, b, point);
    Fixed d2 = crossProduct(b, c, point);
    Fixed d3 = crossProduct(c, a, point);

    // if any cross product is zero, point is on edge or vertex
    if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0))
        return false;

    bool allPositive = (d1 > Fixed(0)) && (d2 > Fixed(0)) && (d3 > Fixed(0));
    bool allNegative = (d1 < Fixed(0)) && (d2 < Fixed(0)) && (d3 < Fixed(0));

    return allPositive || allNegative;
}