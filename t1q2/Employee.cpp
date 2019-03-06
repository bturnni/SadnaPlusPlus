#define _CRT_SECURE_NO_WARNINGS

#include "Employee.h"


#pragma region gets
int Employee::GetId() { return id; }
char* Employee::GetName() { return name; }
float Employee::GetHourlyWage() { return hourlyWage; }
int Employee::GetHoursWorked() { return hoursWorked; }
int Employee::GetHoursOvertime() { return hoursOvertime; }
#pragma endregion
#pragma region sets
void Employee::SetId(int in_id) { id = in_id; }
void Employee::SetName(char* in_name) { strcpy(name, in_name); }
void Employee::SetHourlyWage(float in_wage) { hourlyWage = in_wage; }
void Employee::SetHoursWorked(int in_hoursWorked) { hoursWorked = in_hoursWorked; }
void Employee::SetHoursOvertime(int in_hoursOvertime) { hoursOvertime = in_hoursOvertime; }
#pragma endregion
float Employee::SalaryCalc() {
	return hourlyWage * (hoursWorked + 1.5 * hoursOvertime);
}
