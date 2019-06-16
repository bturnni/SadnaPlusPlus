#pragma once
#include<string>
#include<iostream>
using namespace std;
class Student
{
protected:
	int id;
	string firstName;
	string lastName;
	int coursesNum;
public:
	string getFirstName() { return firstName; };
	string getLastName() { return lastName; };
	int getCoursesNum() { return coursesNum; };
	Student(int mId, string mFirstName, string mLastName, int mCoursesNum);
	virtual bool milga() = 0;
	virtual void print() = 0;
	virtual string studType() = 0;
};

