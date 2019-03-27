#include "Point.h"


double Point::distance(const Point& p)
{
	return sqrt(pow(x - p.x, 2.0) + pow(y - p.y, 2.0));
}
Point::Point(int mX, int mY) :x(mX), y(mY){}

Point::~Point()
{
}
