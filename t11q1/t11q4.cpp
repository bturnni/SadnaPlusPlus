#include <iostream>
#include <fstream>
#include "Student.h"
#include "SearchTree.h"
using namespace std;

enum Choices {
	ADD = 'a',
	DELETE,
	SEARCH, PRINT,
	END
};
char enterChoice()
{
	cout << "\nEnter your choice" << endl
		<< "a - add student" << endl
		<< "b - delete student from list" << endl
		<< "c - search a student" << endl
		<< "d - print students list" << endl
		<< "e - end program\n? ";
	char menuChoice;
	cin >> menuChoice;
	return menuChoice;
}
int main()
{
	SearchTree<Student> students;
	try
	{
		char choice;

		Student stu;
		while ((choice = enterChoice()) != END) {
			switch (choice) {
			case ADD:
				try {
					cout << "enter ID, First name, Last name\n";
					cin >> stu;
					students.add(stu);
				}
				catch (const char* msg) {
					cout << msg;
				}
				break;
			case DELETE:
				cout << "enter ID, First name, Last name to delete\n";
				cin >> stu;
				students.remove(stu);
				break;
			case SEARCH:
				cout << "enter ID, First name, Last name to delete\n";
				cin >> stu;
				cout<<((students.search(stu))? "found\n" :"not found\n");
				break;
			case PRINT:
				students.inOrder();
				break;
			default: cout << "Incorrect choice" << endl;

				if (!cin << choice)
					throw "error cin/ input";
			}
		}
	}
	catch (const char* e)
	{
		cout << e;
	}
	return 0;
}