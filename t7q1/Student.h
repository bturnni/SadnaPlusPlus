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
	Student(int mId, string mFirstName, string mLastName, int mCoursesNum);
	virtual bool milga() = 0;
	virtual void print() = 0;
};

