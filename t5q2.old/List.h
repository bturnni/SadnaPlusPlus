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
private:
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
	};

public:
	Link* head;
	// constructors
	List();
	List(const List&);
	~List();

	// operations
	void add(int value);
	int firstElement() const;
	bool search(const int& value) const;
	bool isEmpty() const;
	void removeFirst();
	void print() const;
	void operator=(const List& other);
	void clear();
	void insert(int);
	void remove(int);
	void insertWithDuplicates(int val);
	//operator
	friend std::ostream& operator<< (std::ostream&, const List&);//output
	friend std::istream& operator>> (std::istream&, List&);//input
	
};
