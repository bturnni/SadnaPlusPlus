#include <iostream>
#pragma once
using namespace std;
//implementing Rational class
class Rational
{
private:
	int mone;
	int mechane;
	void fix();
public:
	Rational(char num1[]);
	Rational() {}
	void setMone(int mMone);
	void setMechane(int mMechane);
	const int getMone();
	const int getMechane();
	void print();
	bool operator==(Rational &b);
	//Rational++
	Rational& operator++();
	//++Rational
	Rational operator++(int);
	//Rational--
	Rational& operator--();
	//--Rational
	Rational operator--(int);
	//Rational!=
	bool operator!=(Rational& b);
	//Rational>
	bool operator>(Rational& b);
	//Rational>=
	bool operator>=(Rational& b);
	//Rational<
	bool operator<(Rational& b);
	//Rational-
	Rational operator-(Rational b);
	//Rational/
	Rational operator/(Rational b);

};

