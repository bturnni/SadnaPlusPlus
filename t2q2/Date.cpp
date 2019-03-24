#include "Date.h"



Date::Date(int mDay, int mMonth, int mYear)
{
	this->setDate(mDay,mMonth,mYear);
	this->print();

}
Date::Date(const Date &d) {
	this->setDate(d.day, d.month, d.year);
}

void Date::setDate(int mDay, int mMonth, int mYear)
{
	//day
	if ((mDay <= 30) && (mDay >= 1))
	{
		setDay(mDay);
	}
	else
	{
		cout << "Error day" << endl;
		day = 1;
	}
	if ((mMonth <= 30) && (mMonth >= 1))
	{
		setMonth(mMonth);
	}
	else
	{
		cout << "Error month" << endl;
		month = 1;
	}
	if ((mYear <= 2099) && (mYear >= 1970))
	{
		setYear(mYear);
	}
	else
	{
		cout << "Error year" << endl;
		year = 1970;
	}
}
//Date++
Date& Date::operator++()
{
	if (day == 30)
	{
		month++;
		day = 1;
		if (month > 12)
		{
			year++;
			month = 1;
		}
	}
	else
	{
		day++;
	}
	return *this;
}
//++Date
Date Date::operator++(int)
{
	Date temp(*this);
	operator++();
	return temp;
}

//date+=
Date Date::operator+=(int days)
{
	setDay(days + this->day);
	if (day > 30)
	{
		int n = day / 30;//num of month are in days
		month = month+n;
		//calculating them
		day -= n*30;
		if (month > 12)
		{
			n = month / 12;//same with months
			year += n;
			//calculating them
			month -= n * 12;
		}
	}
	return *this;
}
//date>
//
bool Date::operator>(Date d)
{
	if (this->getYear() == d.getYear())
	{
		if (this->getMonth() == d.getMonth())
		{
			if (this->getDay() > d.getDay())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (this->getMonth() > d.getMonth())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (this->getYear() > d.getYear())
	{
		return true;
	}
	else
	{
		return false;
	}
}
//date>
bool Date::operator<(Date d)
{
	return (*this > d) ? false : true;
}
//date== printing as dd//mm/yyyy
bool Date::operator==(Date d)
{
	return(d.day == day && d.month == month && d.year == year);
}
void Date::print()//print func
{
	cout << day << "/" << month << "/" << year << endl;
}
Date::~Date()
{
}
