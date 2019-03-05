#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>

class Point
{
public:
	float getX()
	{
		return x;
	}
	float getY()
	{
		return y;
	}

	void setY(float mY)
	{
		y = mY;
	}
	void setX(float mX)
	{
		x = mX;
	}
private:
	float x;
	float y;
};

using namespace std;
int length(Point a, Point b)
{
	return sqrt(((a.getX() - b.getX()) * (a.getX() - b.getX())) + ((a.getY() - b.getY()) * (a.getY() - b.getY())));
}
class circle
{
public:
	Point *getCenterPoint()
	{
		return &centerPoint;
	}
	float getRadius()
	{
		return radius;
	}

	void setCenterPoint(float x, float y)
	{
		centerPoint.setX(x);
		centerPoint.setY(y);
	}
	void setRadius(float mRadius)
	{
		radius = mRadius;
	}
	float Storage()
	{
		return (float)radius* radius* 3.14;
	}
	float Perimeter()
	{
		return (float)2 * radius* 3.14;
	}
	int inCirecle(Point a) {
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
	int checkIfInCircle(Point a)
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
private:
	Point centerPoint;
	float radius;
};

int main()
{
	circle a, b, c;
	cout << "enter the center point and radius of 3 circles" << endl;

	float x, y, radius;
	//set data into the 3 circles
	//a
	cin >> x >> y >> radius;
	a.setRadius(radius);
	a.setCenterPoint(x, y);
	//b
	cin >> x >> y >> radius;
	b.setRadius(radius);
	b.setCenterPoint(x, y);
	//c
	cin >> x >> y >> radius;
	c.setRadius(radius);
	c.setCenterPoint(x, y);

	cout << "area A:" << a.Storage() << " B:" << b.Storage() << " C:" << c.Storage() << endl;
	cout << "hekef A:" << a.Perimeter() << " B:" << b.Perimeter() << " C:" << c.Perimeter() << endl;
	//checking if points are inside the circle
	Point temp;
	int countA = 0, countB = 0, countC = 0;
	cin >> x >> y;

	while ((x != 0 || y != 0))
	{
		temp.setX(x);
		temp.setY(y);
		if (a.checkIfInCircle (temp) == -1) {
			countA++;
		}
		if (b.checkIfInCircle(temp) == -1) {
			countB++;
		}
		if (c.checkIfInCircle(temp) == -1) {
			countC++;
		}
		cin >> x >> y;

	}
	cout << "num of points in circle A:" << countA << " B:" << countB << " C:" << countC << endl;
	return 0;
}