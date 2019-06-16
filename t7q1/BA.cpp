#include "BA.h"

BA::BA(int mId, string mFirstName, string mLastName, int mCoursesNum, float mGrades[])
	:Student(mId, mFirstName, mLastName, mCoursesNum)
{
	grades = mGrades;
}

BA::~BA()
{

}

bool BA::milga()
{
	if(coursesNum<10)
		return false;
	else
	{
		float sum = 0;
		for (int i = 0; i < coursesNum; i++)
		{
			sum += grades[i];
		}
		if (sum > 95)
			return true;
		else
		{
			return false;
		}
	}
}
void BA::print()
{
	cout<< "id: " << id << "\n"
		<< "first name: " << firstName << "\n"
		<< "first name: " << lastName << "\n"
		<< "num courses: " << coursesNum << "\n"
		<< "grades: ";
	for (int i = 0; i < coursesNum; i++)
	{
		cout << grades[i] << " ";
	}
	cout << "\n";
}
