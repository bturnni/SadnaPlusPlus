#pragma once
#include "Student.h"
class PHD :
	public Student
{
private:
	int resarchHours;
public:
	PHD(int mId, string mFirstName, string mLastName, int mCoursesNum, int mResarchHours);
	void print() override;//overide print func of student;
	bool milga() override;

};

