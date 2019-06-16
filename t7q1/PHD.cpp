#include "PHD.h"

PHD::PHD(int mId, string mFirstName, string mLastName, int mCoursesNum, int mResarchHours)
	:Student(mId, mFirstName, mLastName, mCoursesNum)
{
	resarchHours = mResarchHours;
}

void PHD::print()
{
	cout << "id: " << id << "\n"
		<< "first name: " << firstName << "\n"
		<< "first name: " << lastName << "\n"
		<< "num courses: " << coursesNum << "\n"
		<<"hours: "<< resarchHours <<"\n";
}

bool PHD::milga()
{
	if (coursesNum < 2)
		return false;
	else
	{
		return (resarchHours > 25) ? (true) : (false);
	}
}

