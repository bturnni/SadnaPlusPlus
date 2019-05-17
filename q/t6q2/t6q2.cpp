#include <iostream>
#include <string>
#include <vector>
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

void getShape(Polygon*& p,int size)
{
	cout << "enter sides for polygon:\n";
	int* values = new int[size];
	if (size == 3)
	{
		cin >> values[0] >> values[1] >> values[2];
		p = new Triangle(values[0], values[1], values[2]);
	}
	else if (size == 4)
	{
		cin >> values[0] >> values[1];
		p = new Rectangle(values[0], values[1]);
	}
	else
		{
		for (int i = 0; i < size; i++)
		{
			cin >> values[i];
		}
			p = new Polygon(size);
			for (int i = 0; i < size; i++)
				p->setSide(i, values[i]);
		}
	delete[] values;
}

int main()
{
	Polygon* p1, * p2;

	cout << "enter number of sides for polygon 1:\n";
	int size;
	cin >> size;
	getShape(p1,size);	  // get pointer to first shape into p1
	cout << "enter number of sides for polygon 2:\n";
	cin >> size;
	if (size != (p1->getNumSides()))
	{
		cout << "not equal\n";
		return 0;
	}
	getShape(p2,size);	  // get pointer to second shape into p2
	if (*p1 == *p2)
		cout << "equal\n";
	else
		cout << "not equal\n";
	return 0;
}




