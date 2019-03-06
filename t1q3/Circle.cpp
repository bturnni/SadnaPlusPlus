#include "Circle.h"
#include <math.h>

//func to calc distance between 2 points;
int length(Point a, Point b)
{
	return sqrt(((a.getX() - b.getX()) * (a.getX() - b.getX())) + ((a.getY() - b.getY()) * (a.getY() - b.getY())));
}

Point* Circle::getCenterPoint()
{
	return &centerPoint;
}
float Circle::getRadius()
{
	return radius;
}

void Circle::setCenterPoint(float x, float y)
{
	centerPoint.setX(x);
	centerPoint.setY(y);
}
void Circle::setRadius(float mRadius)
{
	radius = mRadius;
}
float Circle::Storage()
{
	return (float)radius* radius* 3.14;
}
float Circle::Perimeter()
{
	return (float)2 * radius* 3.14;
}
int Circle::inCirecle(Point a) {
	int l = length(centerPoint, a);
	if (l == radius) { return 0; }
	else if (l < radius)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}
int Circle::checkIfInCircle(Point a)
{
	int l = length(*this->getCenterPoint(), a);
	if (l < this->radius)
	{
		return -1;
	}
	if (l == this->radius)
	{
		return 0;
	}
	if (l > this->radius)
	{
		return 1;
	}
}

