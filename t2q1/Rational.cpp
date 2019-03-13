#include "Rational.h"
//recursion func to find the Greatest common divisor
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
//set the lowest form of the Rational
void Rational::fix()
{
	int divider = gcd(mone, mechane);
	mone = mone / divider;
	mechane = mechane / divider;
}

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
	//checking if the mechane is 0
	if (down[0] == '0')
	{
		cout << endl << "ERROR" << endl;
		setMone(atoi(up));
		setMechane(atoi("1"));
	}
	else
	{
		setMone(atoi(up));
		setMechane(atoi(down));
	}
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
	if (mone==0)
	{
		cout << mone << endl;
	}
	else if (mone==mechane)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << mone << '/' << mechane << endl;
	}
}
// overload operator of == to return the bool answer of mone/mechane
bool Rational::operator==(Rational& b) {
	float a = (float)(this->mone) / (float)(this->mechane);
	float toCompare = (float)b.getMone() / (float)b.getMechane();
	return (a == toCompare) ? true : false;
}
//Rational++
Rational& Rational::operator++()
{
	this->setMone(this->getMone() + this->getMechane());
	return *this;
}
//++Rational
Rational Rational::operator++(int)
{
	Rational temp(*this);
	operator++();
	return temp;
}
//Rational--
Rational& Rational::operator--()
{
	this->setMone(this->getMone() - this->getMechane());
	return *this;
}
//--Rational
Rational Rational::operator--(int)
{
	Rational temp(*this);
	operator--();
	return temp;
}

//Rational!=
bool Rational::operator!=(Rational& b)
{
	return !(*this==b);
}
//Rational>
bool Rational::operator>(Rational& b) {
	float a = (float)(this->mone) / (float)(this->mechane);
	float toCompare = (float)b.getMone() / (float)b.getMechane();
	return (a > toCompare) ? true : false;
}
//Rational>=
bool Rational::operator>=(Rational& b)
{
	float a = (float)(this->mone) / (float)(this->mechane);
	float toCompare = (float)b.getMone() / (float)b.getMechane();
	return (a >= toCompare) ? true : false;
}
//Rational<
bool Rational::operator<(Rational& b) {
	float a = (float)(this->mone) / (float)(this->mechane);
	float toCompare = (float)b.getMone() / (float)b.getMechane();
	return (a < toCompare) ? true : false;
}
Rational Rational::operator-(Rational b)
{
	//impleminting muxing in the mux of both machane
	Rational temp;
	int mMone, mMechane;
	mMone = (b.getMechane() *this->getMone() - this->getMechane() *b.getMone());
	mMechane = getMechane() * b.getMechane();
	temp.setMone(mMone);
	temp.setMechane(mMechane);
	return temp;
}
Rational Rational::operator/(Rational b)
{
	//impleminting reversed muxing
	Rational temp;
	int mMone, mMechane;
	mMone = (this->getMone() * b.getMechane());
	mMechane = (this->getMechane() * b.getMone());
	temp.setMone(mMone);
	temp.setMechane(mMechane);
	return temp;
}