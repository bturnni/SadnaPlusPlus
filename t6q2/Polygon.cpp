#include "Polygon.h"

int Polygon::getNumSides()
{
	return numSides;
}

Polygon::Polygon(int size) : numSides(size), sides(new int[size]) {}

Polygon::~Polygon()
{
	delete[] sides;
}

Polygon::Polygon(const Polygon& p)
{
	numSides = p.numSides;
	sides = new int[numSides];
	for (int i = 0; i <numSides; i++)
		sides[i] = p.sides[i];
}

void Polygon::setSide(int sideNum, int val) {
	sides[sideNum] = val;
}

bool Polygon::operator==(Polygon p) const
{
	if (p.numSides == numSides)
	{
		int aSum = 0, bSum = 0;//store the sum of sides
		for (int i = 0; i < numSides; i++) //summing the the sides
		{
			aSum += sides[i];
			bSum += p.sides[i];
		}
		if (aSum == bSum) //check for equal
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else //Numsides not equal
	{
		return false;
	}
}

int Polygon::Perimeter()
{
	int Sum = 0;//store the sum
	for (int i = 0; i < numSides; i++) //summing the the sides
	{
		Sum += sides[i];
	}
	return Sum;
}
