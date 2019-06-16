#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include "BA.h"
#include "PHD.h"
#include "MA.h"
using namespace std;
enum option {
	stop,	//	���� �������
	addNewStudent,	//	����� ������ ���
	milgaList,	//	����� ���� �� �������� ������ �����
	mostResearch,	//	����� �� (����� �����) �� ������� ����� ��� ���� ���� �����
	countMilgaBA,	//	����� ���� ��������� ����� ����� ������ �����
	noResearchMA,	//	����� ���� (����� �����) �� ��������� MA ����� ������ �����
	overheadStudent,	//	����� ����� ������, ��� ���� ������ ����� ���� �- 15 ������
	removePHDFailers,	//	����� �� ��������� ����� ����� ����� ������ ��� ����
};

void add(vector < Student*> &students)
{
	Student* stud;
	int option;
	int id;
	string firstName;
	string lastName;
	int courses;
	bool research;
	int resHours;
	float* grades;
	cout << "enter 1 to add a BA student\n";
	cout << "enter 2 to add a MA student\n";
	cout << "enter 3 to add a PHD student\n";
	cin >> option;
	cout << "enter id, first name, last name and number Of Courses\n";
	cin >> id >> firstName >> lastName>> courses;
	grades = new float[courses];
	if (option == 1 || option == 2)
	{
		cout << "enter " << courses << " grades\n";
		for (int i = 0; i < courses; i++)
		{
			cin >> grades[i];
		}
		if (option == 1)
		{
			stud = new BA(id, firstName, lastName, courses, grades);
		}
		if (option == 2)
		{
			cout << "enter 1 if the student does research and 0 if not\n";
			cin >> research;
			stud = new MA(id, firstName, lastName, courses, grades, research);

		}
	}
	if (option == 3)
	{
		cout << "enter number of research hours\n";
		cin >> resHours;
		stud = new PHD(id, firstName, lastName, courses, resHours);
	}
	students.push_back(stud);
}

void milga(vector < Student*> students)
{
	std::for_each(students.begin(), students.end(), [](Student*& stu){if (stu->milga())stu->print(); });
}
Student* mostResearchHours(vector < Student*> students)
{
	auto max = std::max_element(students.begin(), students.end(),
		[](Student* a, Student* b)
		{ // ����� �� ������ ���� �����
			if (a->studType() == (string)"PHD" &&
				b->studType() == (string)"PHD") // ���� ���� ��� ����� PHD
			{
				return ((PHD*)a)->getResarchHours() < ((PHD*)b)->getResarchHours();
			}
			else if (a->studType() == (string)"PHD" && // �� ������ �� ����� �� �� ����� �����
				b->studType() != (string)"PHD")
			{
				return false;
			}
			else if (a->studType() != (string)"PHD" &&
				b->studType() == (string)"PHD") // ����� ������
			{
				return true;
			}
			else // �� ���� �� ����� ������
			{
				return false;
			}
		});
	return ((*max)->studType()=="PHD") ? (*max) : NULL;//return this student if he PHD
}
int main()
{
	Student* s;
	vector < Student*> students;
	int op;
	int count = 0;
	std::cout << "enter 0-7\n";
	std::cin >> op;
	while (op != stop)
	{
		switch (op)
		{
		case addNewStudent:add(students);//����� ������ ���			
			break;
		case milgaList:milga(students);	//����� ���� ������ �����
			break;
		case mostResearch:
			//����� �� ������� ����� ����� ��� ���� ����:
			if (!students.size())
			{
				std::cout << "error\n";
				break;
			}
			s = mostResearchHours(students);
			if (!s)
			{
				break;
			}
			std::cout << "PHD studnet with most research hours: ";
			std::cout << s->getFirstName() << ' ' << s->getLastName() << endl;
			break;
		case countMilgaBA:  std::cout << "#BA studnets for milga: ";
				//����� ���� ������ ����� ����� ������
			std::cout << std::count_if(students.begin(), students.end(), [](Student* stu) {
				return (stu->studType() == (string)"BA") && stu->milga(); })<<endl;
			break;
		case noResearchMA:std::cout << "list of no research MA students : ";
			//����� ����� (�� ����� �����) ��������� ����� ��� ����� ������ �����
			std::for_each(students.begin(), students.end(), [](Student*& stu) {
				if (stu->studType() == (string)("MA") && !((MA*)stu)->isResarch())//looking on the element as a MA object to get access to his fields
				{
					stu->print();//printing his details
				}
				});
			std::cout << endl;
			break;
		case overheadStudent:
		{
			if (
				std::any_of(students.begin(), students.end(), [](Student*& stu) { //searching for instance of student with 15 <courses
					return stu->getCoursesNum() > 15;})
			)
				cout << "there is a student that takes more than 15 courses\n";
			else cout << "no student takes more than 15 courses\n";
			break;
		}
		case removePHDFailers:
			//����� ��������/����� �� �� ��������� ����� ����� ����� ������ ������ ����
			if(!students.empty())
				students.erase(std::remove_if(students.begin(), students.end(), [](Student*& stu) {
				return (stu->studType() == (string)("PHD") && ((PHD*)stu)->getCoursesNum() == 0);//looking on the element as a MA object to get access to his fields
				}),students.end());

			//����� �� ������ ���� ����� �������
			std::for_each(students.begin(), students.end(), [](Student*& stu) {
				stu->print(); });
			break;
		};

		cout << "enter 0-7\n";
		cin >> op;
	}
	return 0;
}
