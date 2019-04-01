#include <iostream>
#include <string>
using namespace std;
#pragma once
class Clock
{
private:
	int second, minute, hour;
public:
	Clock();//defualt 00:00:00
	Clock(int,int,int);// if wrong 00:00:00
	~Clock();
#pragma region gets,sets
	int getSecond();
	int getMinute();
	int getHour();
	void setSecond(int);
	void setMinute(int);
	void setHour(int);
#pragma endregion
#pragma region operators
	Clock operator+=(int);
	friend std::ostream& operator<< (std::ostream&, const Clock&);//output
	friend std::istream& operator>> (std::istream&, Clock&);//input
#pragma endregion
};

