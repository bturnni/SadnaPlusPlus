#pragma once
#include "BA.h"
class MA :
	public BA
{
private:
	bool resarch;
public:
	MA(int mId, string mFirstName, string mLastName, int mCoursesNum, float mGrades[], bool resarch);
	void print() override; // overide print func of MA
	bool milga() override; // overide print func of MA
	bool isResarch() { return resarch; };
	string studType() override
	{
		return "MA";
	}
};

