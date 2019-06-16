#include <iostream>
#pragma once
using namespace std;
class Polygon
{
private:
	int numSides;
	int* sides;
public:
		int getNumSides();
		Polygon(int);
		~Polygon();
		Polygon(const Polygon& p);
		void setSide(int, int);
		bool operator==(Polygon) const;
		int Perimeter();
};

