#include <cmath>
#pragma once
class Point
{
private:
	int x;
	int y;
public:
	int getX() { return x; }
	int getY() { return y; }
	double distance(const Point&);
	Point(int, int);
	Point() {};
	~Point();
};

