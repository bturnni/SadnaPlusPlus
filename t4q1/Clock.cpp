#include "Clock.h"


Clock::Clock()
{
	second = 0;
	minute = 0;
	hour = 0;
}

Clock::Clock(int mHour,int mMinute,int mSecond)
{
	bool errorFlag = false;
	//sec
	if (0 > mSecond)
	{
		errorFlag=true;
		cout << "Invalid time - negative number of seconds.\n";
	}
	if (mSecond>59)
	{
		errorFlag = true;
		cout << "Invalid time - more than 60 seconds.\n";
	}
	//min
	if (0 > mMinute)
	{
		errorFlag = true;
		cout << "Invalid time - negative number of minutes.\n";
	}
	if (mMinute > 59)
	{
		errorFlag = true;
		cout << "Invalid time - more than 60 minutes.\n";
	}
	//hour
	if (0 > mHour)
	{
		errorFlag = true;
		cout << "Invalid time - negative number of hours\n";
	}
	if (mHour > 24)
	{
		errorFlag = true;
		cout << "Invalid time - more than 60 hours.\n";
	}
	if(errorFlag) //error in input
	{
		second = 0;
		minute = 0;
		hour = 0;
	}
	else//everything fine :)
	{
		second = mSecond;
		minute = mMinute;
		hour = mHour;
	}
}

int Clock::getSecond()
{
	return second;
}

int Clock::getMinute()
{
	return minute;
}
int Clock::getHour()
{
	return hour;
}

void Clock::setSecond(int mSec)
{
	second = mSec;
}

void Clock::setMinute(int mMin)
{
	minute = mMin;
}

void Clock::setHour(int mHour)
{
	hour = mHour;
}

Clock Clock::operator+=(int sec)
{
	second += sec;
	if (second >= 60)
	{
		int n = second / 60;//num of month are in days
		minute = minute + n;
		//calculating them
		second -= n * 60;
		if (minute > 60)
		{
			n = minute / 12;//same with months
			hour += n;
		}
	}
	return *this;
}


Clock::~Clock()
{
}

std::ostream& operator<<(std::ostream& output, const Clock& c)
{
	if (c.hour < 10)
		output << '0' << c.hour;
	else
		output << c.hour;
	output << ':';
	if (c.minute < 10)
		output << '0' <<c.minute;
	else
		output << c.minute;
	output << ':';
	if (c.second < 10)
		output << '0' << c.second;
	else
		output << c.second;
	output << endl;
	return output;
}

std::istream& operator>>(std::istream& input, Clock& c)
{
	int sec, min, hours;//temp vars to store data, if exeption throwed, do nothing:)
	string str;
	input >> str;
	//finding index of first : for hours
	int index = str.find(':');
	if (index == string::npos)//not found
	{
		throw "Wrong time format.\n";
	}
	hours = atoi(str.substr(0, index ).data()); // get chars of HH
	str.substr(++index);

	//finding index of second : for minutes
	index = str.find(':');
	if (index == string::npos)//not found
	{
		throw "Wrong time format.\n";
	}
	min = atoi(str.substr(0, index).data()); // get chars of MM
	str.substr(++index);

	//rest is seconds
	str = str.substr(index + 1); // "Erase" the minutes part
	if (str.length() == 0)
		throw "Wrong time format.\n";
	sec = atoi(str.data());
	//everything good, now insert data to class
	c.setSecond(sec);
	c.setMinute(min);
	c.setHour(hours);
	return input;
}
