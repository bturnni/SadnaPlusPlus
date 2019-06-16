#include <iostream>
#include <fstream>
#include "Student.h"
using namespace std;

enum Choices {
	 PRINT = 1,
	 PRINTALL,
	 UPDATE, NEW,
	 DELETE,
	 CHECKREGISTERED,
	 END
};
void initilizeFile(fstream *file)
{
	Student stu;
	for (int i = 0; i < 100; i++)
	{
		file->write((char*)& stu, sizeof(stu));
	}
}
void updateStudent(fstream *file, int id)
{

	file->seekg((id - 1) * sizeof(Student));
	Student stu;
	file->read((char*)& stu, sizeof(Student));
	if (stu.getId() == id)
	{
		cout << "found. now enter First name, last Name, and 5 courses: 1 for regisered or 0 to not registered\n";
		char firstName[20];
		char lastName[20];
		bool registerd[5];
		cin >> id;
		for (size_t i = 0; i < 5; i++)
		{
			cin >> registerd[i];
		}
		stu.set(id, firstName, lastName, registerd);
		//now writing
		file->seekp((id - 1) * sizeof(Student)); // go to place
		file->write((char*)& stu, sizeof(Student));
	}
	else
	{
		cout << "not found\n";
	}

}
void addStudent(fstream *file)
{
	cout << "Enter id, First name, last Name, and 5 courses: 1 for regisered or 0 to not registered\n";
	int id;
	char firstName[20];
	char lastName[20];
	bool registerd[5];
 	cin >> id >> firstName >> lastName;
	for (size_t i = 0; i < 5; i++)
	{
		cin >> registerd[i];
	}
	file->seekg((id - 1) * sizeof(Student));
	Student stu;
	file->read((char*)&stu,sizeof(Student));
	if (stu.getId() == id)
	{
		cout << "allready exists\n";
	}
	else
	{
		stu.set(id, firstName, lastName, registerd);
		file->seekp((id-1) * sizeof(Student)); // go to place
		file->write((char*)& stu, sizeof(Student));
	}
}
void delStu(fstream* file, int id)
{

	file->seekg((id - 1) * sizeof(Student));
	Student stu;
	file->read((char*)& stu, sizeof(Student));
	if (stu.getId() == id)
	{
		Student empty;//creating empty student
		file->seekp((id - 1) * sizeof(Student)); // go to place
		file->write((char*)& empty, sizeof(Student));
		cout << "deleted secssesufly\n";
	}
	else
	{
		cout << "ID not found\n";
	}
}
void printRegistered(fstream *file, int id)
{
	file->seekg(0);
	for (int i = 1; i <= 100; i++)//every student in file
	{
		file->seekg((i - 1) * sizeof(Student));
		Student stu;
 		file->read((char*)& stu, sizeof(Student));
		if (stu.getRegistered()[id])
		{
			if (stu.getId()) // if it empty so it empty student
				cout << stu;
		}
	}
}
void printAll(fstream* file)
{
	for (int i = 1; i <= 100; i++)//every student in file
	{
		file->seekg((i - 1) * sizeof(Student));
		Student stu;
		file->read((char*)& stu, sizeof(Student));
		if (stu.getId()) // if it empty so it empty student
			cout << stu;
	}
}

void printRecord(fstream *file, int id)
{
	file->seekg(0);
	for (int i = 1; i <= 100; i++)//every student in file
	{
		file->seekg((i - 1) * sizeof(Student));
		Student stu;
		file->read((char*)& stu, sizeof(Student));
		if (stu.getId()==id)
		{
			if (stu.getId()) // if it empty so it empty student
			{
				cout << stu;
				return;
			}
		}
	}
}
int enterChoice()
 {
	 cout << "\nEnter your choice" << endl
	 << "1 - Print student"<< endl
	 << "2 - Print list" << endl
	 << "3 - update an student" << endl
	 << "4 - add a new student" << endl
	 << "5 - delete an student" << endl
	 << "6 - check registered student" << endl
	 << "7 - end program\n? ";
	 int menuChoice;
	 cin >> menuChoice;
	 return menuChoice;
 }
int main()
{
	try
	{
		std::fstream StudentsData("example.bin", std::ios::in | ios::out | ios::trunc);
		if (!StudentsData)
		{
			throw "error creating file\n";
		}
		initilizeFile(&StudentsData); // init file
		int id;
		int choice;
		while ((choice = enterChoice()) != END) {
			StudentsData.seekg(0);
			switch (choice) {
				case PRINT: 
				try {
					cout << "enter ID to print\n";
					cin >> id;
					printRecord(&StudentsData, id);
				}
				catch(char* msg) {
					cout << msg;
				}
					break;
				case PRINTALL:
					printAll(&StudentsData);
					break;
				case UPDATE: 
					printAll(&StudentsData);
				break;
				case NEW: 		addStudent(&StudentsData);
				break;
				case DELETE: 
					cout << "Enter ID to delete:\n";
					cin >> id;
					delStu(&StudentsData,id);
				break;
				case CHECKREGISTERED:
					cout << "enter course ID to Check registered\n";
					cin >> id;
					printRegistered(&StudentsData, id);
					break;
				default: cout << "Incorrect choice" << endl;

						if (!cin << choice)
							throw "error cin/ input";
			}
		}
		StudentsData.close();
	}
	catch (const char* e)
	{
		cout << e;
	}
	return 0;
}