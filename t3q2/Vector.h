#pragma once
#include <iostream>
using namespace std;
class Vector
{
private:
	int* data;//int array;
	int capacity;//max size(what allocated)
	int size;//real size(what have data)
public:
	Vector();//default 10 max size
	Vector(int);//capacity
	Vector(const Vector&); //copy constractor;
	~Vector();
	int getCapacity();
	int getSize();
	void print();//print max size, real size,data;
	Vector& operator=(const Vector&);
	bool operator==(const Vector);
	int operator[](int) const;//get
	int& operator[](int);//set
	int operator*(const Vector);//scalar
	Vector operator+(const Vector)const;//vecCat
	void clear();//empty vec
	void delLast();//delete last if empty print error
	void insert(int);//push int if full print error
};

