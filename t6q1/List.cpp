#include "List.h"

//--------------------------------------------
//  class Link implementation
//--------------------------------------------
List::Link::Link(int val, Link* nxt) : value(val), next(nxt) {}
List::Link::Link(const Link& source) : value(source.value), next(source.next) {}

//--------------------------------------------
//  class List implementation
//--------------------------------------------
List::List() : head(NULL) {}

// Copy ctor
List::List(const List& l)
{
	Link* src, * trg;
	if (l.head == NULL)
		head = NULL;
	else
	{
		head = new Link((l.head)->value, NULL);
		src = l.head;
		trg = head;
		while (src->next != NULL)
		{
			trg->next = new Link((src->next)->value, NULL);
			src = src->next;
			trg = trg->next;
		}
	}
}

// Dtor
List::~List()
{
	clear();
}

void List::clear()
{
	// empty all elements from the List
	Link* next;
	for (Link* p = head; p != NULL; p = next)
	{
		// delete the element pointed to by p
		next = p->next;
		p->next = NULL;
		delete p;
	}
	// mark that the List contains no elements
	head = NULL;
}

bool List::isEmpty() const
{
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is NULL

	return head == NULL;
}

List& List::operator+=(int val)
{
	//Add a new value to the front of a Linked List
	head = new Link(val, head);
	if (head == NULL)
		throw "failed in memory allocation";
	return *this;
}

int List::firstElement() const
{
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}

bool List::search(const  int& val) const
{
	// loop to test each element
	for (Link* p = head; p != NULL; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}

void List::removeFirst()
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	p->next = NULL;
	// recover memory used by the first element
	delete p;
}

ostream& operator<<(ostream & os, const List & l)
{
	cout << "The list is: ";
	for (List::Link* p = l.head; p != NULL; p = p->next)
		cout << p->value << " ";
	cout << endl;
	return os;
}

void List::add(int val)
{
//Add a new value to the front of a Linked List
	head = new Link(val, head);
	if (head == NULL)
		throw "failed in memory allocation";
}
