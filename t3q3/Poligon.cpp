#include "Poligon.h"

Poligon::Poligon(const Poligon& p)
{
	numPoints = p.numPoints;
	points = new Point[numPoints];
	for (int i = 0; i < numPoints; i++)
	{
		points[i] = p.points[i];
	}
}
double Poligon::round()
{
	double sum = 0;
	for (int i = 0; i < numPoints ; i++)
	{
		if (i < numPoints - 1)
		{
			sum += points[i].distance(points[i + 1]);
		}
		else//for last element
		{
			sum+=points[i].distance(points[0]);
		}
	}
	return sum;
}
Poligon::~Poligon()
{
	delete[] points;
}

void Poligon::addPoint(Point p)
{
	//increase size
	numPoints++;
	//allocate temp 
	Point* temp = new Point[numPoints];
	//copying
	for (int i = 0; i < numPoints-1; i++)
	{
		temp[i] = points[i];
	}
	temp[numPoints-1] = p;
	points = temp;
}
