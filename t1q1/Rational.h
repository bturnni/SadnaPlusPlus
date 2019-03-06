#include <iostream>
#pragma once
using namespace std;
//implementing Rational class
class Rational
{
private:
	int mone;
	int mechane;

public:
	Rational(char num1[]);
	void setMone(int mMone);
	void setMechane(int mMechane);
	int getMone();
	int getMechane();
	void print();
	bool operator==(Rational& b);
};

