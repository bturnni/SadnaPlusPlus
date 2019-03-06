#pragma once
#include "point.h"
class Circle
{
public:
	Point* getCenterPoint();
	float getRadius();

	void setCenterPoint(float x, float y);
	void setRadius(float mRadius);
	float Storage();
	float Perimeter();
	int inCirecle(Point a);
	int checkIfInCircle(Point a);
	private:
	Point centerPoint;
	float radius;
};

