#pragma once
#include <iostream>
using namespace std;

//------------------------------------------------
//  class List
//      arbitrary size Lists
//      permits insertion and removal 
//      only from the front of the List
//------------------------------------------------
class List
{
protected:
	//--------------------------------------------
	//  inner class link
	//  a single element for the linked List 
	//--------------------------------------------
	class Link
	{
	public:
		// constructor
		Link(int linkValue, Link* nextPtr);
		Link(const Link&);
		// data areas
		int value;
		Link* next;
	};	//end of class Link
	// data field
	Link* head;

public:
	// constructors
	List();
	List(const List&);
	~List();

	// operations
	List& operator+=(int value);

	int firstElement() const;
	bool search(const int& value) const;
	bool isEmpty() const;
	void removeFirst();
	void clear();
	void add(int);
	friend ostream& operator<<(ostream& os, const List& l);
};
//------------------------------------------------
//  class Link implementation
//------------------------------------------------

