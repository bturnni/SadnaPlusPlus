#pragma once
#include <cstring>
#include <iostream>
using namespace std;
class Student
{
protected:
	int id;
	char firstName[20];
	char lastName[20];
	bool registered[5];
public:
	void set(int mId, char mFirstName[20], char* mLastName, bool* mRegistered)
	{
		id = mId;
		strcpy_s(firstName, mFirstName);
		strcpy_s(lastName, mLastName);
		for (int i = 0; i < 5; i++) {
			//copying the bool array
			registered[i] = mRegistered[i];
		}
	}
	int getId() { return id; }
	char* getFirstName() { return firstName; }
	char* getLastName() { return lastName; }
	bool* getRegistered() { return registered; }
	Student(int mId, char mFirstName[20], char* mLastName, bool* mRegistered)
		: id(mId) 
	{
		strcpy_s(firstName, mFirstName);
		strcpy_s(lastName, mLastName);
		for (int i = 0; i < 5; i++) {
			//copying the bool array
			registered[i] = mRegistered[i];
		}
	}
	Student()
	{
		id = 0;
		strcpy_s(firstName, "");
		strcpy_s(lastName, "");
		for (int i = 0; i < 5; i++) {
			//init the bool array
			registered[i] = false;
		}
	}
	friend std::ostream& operator<< (std::ostream& stream, const Student& stu)
	{
		cout << "ID:" << stu.id<<std::endl
			   << "First Name:" << stu.firstName << std::endl
			   << "Last Name:" << stu.lastName << std::endl
			   << "Registered:";
		for (int i = 0; i < 5; i++)
		{
			if (stu.registered[i])
			{
				cout << "T ";
			}
			else
			{
				cout << "F ";
			}
		}
		cout << std::endl;
		return stream;
	}
};

