#define _CRT_SECURE_NO_WARNINGS
#include "Employee.h"
using namespace std;

Employee* addEmployee(Employee* Pemp, int id,
	char name[21], float hourlyWage, int hoursWorked, int hoursOvertime, int& numEmployee)
{
	Employee* new_Pemp = new Employee[numEmployee + 1];//new array of emp 1 size bigger
	for (int i = 0; i < numEmployee; i++)//copying old data
	{
		new_Pemp[i].SetId(Pemp[i].GetId());
		new_Pemp[i].SetName(Pemp[i].GetName());
		new_Pemp[i].SetHourlyWage(Pemp[i].GetHourlyWage());
		new_Pemp[i].SetHoursWorked(Pemp[i].GetHoursWorked());
		new_Pemp[i].SetHoursOvertime(Pemp[i].GetHoursOvertime());
	}
	new_Pemp[numEmployee].SetId(id);
	new_Pemp[numEmployee].SetName(name);
	new_Pemp[numEmployee].SetHourlyWage(hourlyWage);
	new_Pemp[numEmployee].SetHoursWorked(hoursWorked);
	new_Pemp[numEmployee].SetHoursOvertime(hoursOvertime);

	numEmployee++;
	return new_Pemp;
}
int main() {
	Employee* employee = new Employee[1];
	int id;
	char name[21];
	float hourlyWage;
	int hoursWorked;
	int hoursOvertime;
	int numEmployee = 0;
	cout << "enter details, to end enter 0" << endl;

	cin >> id;
	while (id)
	{
		cin >> name >> hourlyWage >> hoursWorked >> hoursOvertime;
		if (hourlyWage >= 0 && hoursWorked >= 0 && hoursOvertime >= 0)
		{
			employee = addEmployee(employee, id, name, hourlyWage, hoursWorked, hoursOvertime, numEmployee);
		}
		else
		{
			cout << "ERROR\n";
		}
		cin >> id;
	}
	int highest = 0; // Assume the first employee
	int i;
	for (i = 1; i < numEmployee; i++)
		if (employee[i].SalaryCalc() > employee[highest].SalaryCalc())
			highest = i;
	cout << "highest salary: " << employee[highest].GetId() << "       " << employee[highest].GetName() << endl;

	highest = 0; // Assume the first employee
	for (i = 1; i < numEmployee; i++)
		if (employee[i].GetHoursWorked() > employee[highest].GetHoursWorked())
			highest = i;
	cout << "highest salary: " << employee[highest].GetId() << "       " << employee[highest].GetName() << endl;
	delete[] employee;
	return 0;
}

