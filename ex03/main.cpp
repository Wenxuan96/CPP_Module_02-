#include "Point.hpp"

int main()
{
	Point a(0.0f, 0.0f);   // bottom left
	Point b(4.0f, 0.0f);   // bottom right
	Point c(2.0f, 4.0f);   // top middle

	Point points[] = { 
		Point(2.0f, 1.0f), // inside
        Point(5.0f, 5.0f), // outside
        Point(0.0f, 0.0f), // vertex
        Point(2.0f, 0.0f)};
		
	int size = sizeof(points) / sizeof(points[0]);

    for (int i = 0; i < size; i++)
    {
        if (bsp(a, b, c, points[i]))
            std::cout << "point is inside the triangle." << std::endl;
        else
            std::cout << "point is not inside the triangle." << std::endl;
    }
}