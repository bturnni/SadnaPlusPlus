#include "MA.h"

MA::MA(int mId, string mFirstName, string mLastName, int mCoursesNum, float mGrades[], bool mResarch)
	:BA(mId, mFirstName, mLastName, mCoursesNum, mGrades)
{
	resarch = mResarch;
}

void MA::print()
{
		cout << "id: " << id << "\n"
			<< "first name: " << firstName << "\n"
			<< "first name: " << lastName << "\n"
			<< "num courses: " << coursesNum << "\n"
			<< "grades: ";
		for (int i = 0; i < coursesNum; i++)
		{
			cout << grades[i] << " ";
		}
		cout << "\n";
		cout << resarch ? ("yes\n") : ("no\n");
}

bool MA::milga()
{
	if (coursesNum < 7)
		return false;
	else
	{
		float sum = 0;
		for (int i = 0; i < coursesNum; i++)
		{
			sum += grades[i];
		}
		if (sum > 90)
			return resarch ? (true) : (false);
		else
		{
			return false;
		}
	}
}