#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include "Circle.h"
using namespace std;

int main()
{
	Circle a, b, c;
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
		if (a.checkIfInCircle (temp) <= 0) {
			countA++;
		}
		if (b.checkIfInCircle(temp) <=0) {
			countB++;
		}
		if (c.checkIfInCircle(temp) <=0) {
			countC++;
		}
		cin >> x >> y;

	}
	cout << "num of points in circle A:" << countA << " B:" << countB << " C:" << countC << endl;
	return 0;
}