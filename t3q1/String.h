#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
using namespace std;
class String
{
private:
	char* str;
public:
	// constructor.
	String(char* s = NULL);
	String(const String& s);
	~String();
	// view function.
	char* getString() const;

	// modify function.
	String& operator =(const String& s);//String a,b,c; c=a;
	String& insert(int index, const char* str);
// operators
	int operator==(String& s);
	String operator+(const String&);//String a,b,c; c=a+b; 
	bool operator>(const String);
	bool operator<(const String);
	bool operator>=(const String);
	bool operator<=(const String);
	bool operator!=(const String);
	char operator[](int index)const { return str[index]; } //R Value //String a; char c=a[2];
	char& operator[](int index) { return str[index]; } //L Value////String a; char c='t'; a[2]=c;	
	void SetString(const char*);

	int length() const;
	// print
	void print();
};

