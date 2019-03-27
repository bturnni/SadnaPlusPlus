#pragma once
#include <iostream>
#include "Point.h"
class Poligon
{
private:
	Point* points;
	int numPoints;
public:
	Poligon(const Poligon&);
	Poligon():numPoints(0){};
	Poligon(int mNumPoints) : numPoints(mNumPoints) {};
	~Poligon();
	void print()
	{
		for (int i = 0; i < numPoints; i++)
		{
			std::cout << points[i].getX() << "," << points[i].getY() << " ";
			if (i < numPoints - 1)
			{
				std::cout << points[i].distance(points[i + 1]);
			}
			else
			{
				std::cout << points[i].distance(points[0]);
			}
			std::cout << "\n";
		}
	}
	//add point to point arr
	void addPoint(Point);
	double round();
};

