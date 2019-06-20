#include "Student.h"

bool Student::operator > (const Student& s) const
{
	if (this->lname == s.lname)
		return this->fname > s.fname;
	else
		return this->lname > s.lname;
}
bool Student::operator<(const Student& s) const
{
	if (this->lname == s.lname)
		return this->fname < s.fname;
	else
		return this->lname < s.lname;
}bool Student::operator==(const Student& s) const
{
	if (s.fname == fname && s.lname == lname)
	{
		return true;
	}
	else
	{
		return false;
	}
}
 