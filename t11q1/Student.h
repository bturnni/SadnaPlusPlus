#include <iostream>
#include <string>
using namespace std;

class Student
{
	int  id;
	string  fname;
	string lname;
public:
	int getID() { return id; }
	void setID(int id) { this->id = id; }
	string getName() { return lname; }
	void setName(string n) { lname = n; }

	Student() {}
	Student(int mId, string mFname, string mLname) :id(mId), fname(mFname), lname(mLname) {}
	//>,=,==,>>,<<
	bool operator > (const Student& s) const;
	bool operator < (const Student& s) const;
	bool operator == (const Student& s) const;
	friend ostream& operator<<(ostream& os, const Student& stu)
	{
		cout << stu.id << " " << stu.fname << " " << stu.lname << endl;
		return os;
	};
	friend istream& operator >> (istream& in, Student& c)
	{
		if (!(in >> c.id))
			throw "cin error\n";
		if (!(in >> c.fname))
			throw "cin error\n";
		if (!(in >> c.lname))
			throw "cin error\n";
		return in;
	};

};