#include <iostream>
using  namespace std;
#pragma once
class Date
{
private:
	int day, month, year;
public:
#pragma region sets, gets
	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }

	void setDay(int mDay) { day = mDay; }
	void setMonth(int mMonth) { month = mMonth; }
	void setYear(int mYear) { year = mYear; }
#pragma endregion

	Date(int,int,int);
	Date() {}
	~Date();
	Date(const Date& d);
	void setDate(int, int, int);
	//Date++
	Date& operator++();
	//++Date
	Date operator++(int);
	//date+=
	Date operator+=(int);
	//date>
	bool operator>(Date);
	//date>
	bool operator<(Date);
	//date== printing as dd//mm/yyyy
	bool operator==(Date);
	void print();
	static int kupa;
};