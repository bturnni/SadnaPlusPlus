#include "Rational.h"
//constactor to create the object by givving string
Rational::Rational(char num1[])
{
	//divide by letter / 
	char up[10], down[10];
	int i = 0;
	while (num1[i] != '/')
	{
		up[i] = num1[i];
		i++;
	}
	up[i] = 0;
	i = i + 1;
	int j = 0;
	while (num1[i] != '\0')
	{
		down[j] = num1[i];
		i++;
		j++;
	}
	down[i - 2] = 0;
	setMone(atoi(up));
	setMechane(atoi(down));
}
//set Mone
void Rational::setMone(int mMone)
{
	this->mone = mMone;
}
//set mechane
void Rational::setMechane(int mMechane)
{
	if (mMechane == 0)
	{
		this->mechane = 1;
		return;
	}
	this->mechane = mMechane;
}
//get mone
int Rational::getMone()
{
	return mone;
}
//get mechane
int Rational::getMechane()
{
	return mechane;
}
//printing
void Rational::print()
{
	cout << mone << '/' << mechane;
}
// overload operator of == to return the bool answer of mone/mechane
bool Rational::operator==(Rational& b) {
	float a = (float)(this->mone) / (float)(this->mechane);
	float toCompare = (float)b.getMone() / (float)b.getMechane();
	return (a == toCompare) ? true : false;
}
