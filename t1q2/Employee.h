#include <iostream>
#include <cstring>
using namespace std;
#pragma once
class Employee
{
public:
#pragma region gets
	int GetId();
	char* GetName();
	float GetHourlyWage();
	int GetHoursWorked();
	int GetHoursOvertime();
#pragma endregion
#pragma region sets
	void SetId(int in_id);
	void SetName(char* in_name);
	void SetHourlyWage(float in_wage);
	void SetHoursWorked(int in_hoursWorked);
	void SetHoursOvertime(int in_hoursOvertime);
#pragma endregion
	float SalaryCalc();
private:
	int id;
	char name[21];
	float hourlyWage;
	int hoursWorked;
	int hoursOvertime;
	int lol;
};


