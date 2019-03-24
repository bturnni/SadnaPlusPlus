#include "String.h"


//allocating new size for the string as the char givven had;
String::String(char* s) {
	SetString(s);
}
String::String(const String& s)
{
	SetString(s.str);
}
// deleting the allocation
String::~String()
{
	if (str) // if the str isnt empty
		delete [] str;
	else
	{
		str = NULL;
	}
}

char* String::getString() const
{
	return str;
}
//using insert func
String& String::operator=(const String& s)
{
	SetString(s.str);
	return *this;
}

String& String::insert(int index, const char* str)
{
	int len = strlen(str);
	if (index>len)// the inert is bigger from size
	{
		cout << "Error\n";
		return *this;
	}
	else
	{
		char* temp = new char[len + strlen(this->str) +1];
		strncpy(temp, this->str, index); // First
		temp[index] = '\0';
		strcat(temp, str);        // Second
		strcat(temp, &this->str[index]); // Third
		SetString(temp); // Set to the new
		delete[] temp; //deleting the dynamic allocation

		return *this;
	}
}

int String::operator==(String& s)
{
	return strcmp(str, s.str);
}

String String::operator+(const String& s)
{
	strcat(str, s.str);
	return *this;
}

bool String::operator>(const String s)
{
	if (strcmp(str, s.str)>0) {
		return true;
	}
	else
		return false;
}
bool String::operator<(const String s)
{
	if (strcmp(str, s.str) < 0) {
		return true;
	}
	else
		return false;
}
bool String::operator>=(const String s)
{
	if (strcmp(str, s.str) >= 0) {
		return true;
	}
	else
		return false;
}
bool String::operator<=(const String s)
{
	if (strcmp(str, s.str) <= 0) {
		return true;
	}
	else
		return false;
}

bool String::operator!=(const String s)
{
	if (strcmp(str, s.str) != 0) {
		return true;
	}
	else
		return false;
}

int String::length() const
{
	return strlen(str);
}

void String::print()
{
	cout << str << endl;
}
void String::SetString(const char* s)
{
	if (s)
	{
		int len = strlen(s);
		str = new char[len + 1];
		strcpy(str, s);
	}
	else str = NULL;
}
