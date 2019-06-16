#pragma once
#include "Student.h"
class BA :
	public Student
{
protected:
	float* grades;
public:
	BA(int mId, string mFirstName, string mLastName, int mCoursesNum, float mGrades[]);
	virtual void print() override;
	~BA();
	bool milga() override;
};

