#include "List.h"
//------------------------------------------------
//  class Link implementation
//------------------------------------------------
List::Link::Link(int val, Link* nxt) : value(val), next(nxt) {}

List::Link::Link(const Link& source) : value(source.value), next(source.next) {}

//--------------------------------------------
//  class List implementation
//--------------------------------------------
List::List() : head(NULL)
{
	//cout << "CTOR\n";
}

// Copy constructor
List::List(const List& l)
{
	cout << "Copy CTOR\n";
	Link* src, * trg;
	if (l.head == NULL)
		head = NULL;
	else
	{  // copy the list
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

void List::operator=(const List& l)
{
	cout << "ASSIGNMENT OPERATOR\n";

	if (&l != this)
	{
		//this->clear();
		Link* src, * trg;
		if (l.head == NULL)
			head = NULL;
		else
		{  // copy the list
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
}

// Destructor
List::~List()
{
	//cout << "DTOR: ";
	//print();
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

void List::insert(int val)
{
	Link* curr;
	//check if is allready in list
	if (search(val))
	{
		return;
	}
	else if(isEmpty())
	{
		add(val);
		return;
	}
	else if(val<head->value)
	{
		add(val);
	}
	else
	{
		curr = head;
		while(curr->next != NULL && curr->next->value < val)
			curr = curr->next;

		Link* new_node = new Link(val, head);
		new_node->next = curr->next;
		curr->next = new_node;
	}
}
//this func remove first occurance of val by point the next val
void List::remove(int val)
{
	//check if the val is in list
	if (!this->search(val))
	{
		return;
	}
	// loop to test each element
	Link* previus = head;
	Link* p = head;
	//cheack for first
	if (val == head->value)
	{
		removeFirst();
		return;
	}
	while (p != NULL)
	{
		p = p->next;
		if (p->value == val)
		{
			previus->next = p->next;
			delete p;
			return;
		}
		else
		{
			previus = previus->next;
		}
	}
	return;
}

// test to see if the List is empty
// List is empty if the pointer to the head
// Link is null
bool List::isEmpty() const
{
	return head == NULL;
}

//Add a new value to the front of a Linked List
void List::add(int val)
{
	head = new Link(val, head);
	if (head == NULL)
		throw "failed in memory allocation";
}

// return first value in List
int List::firstElement() const
{
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

void List::print() const
{
	for (Link* p = head; p != NULL; p = p->next)
		cout << p->value << ((p->next != NULL) ? " -> " : "\n");
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

List merge(List & list1, List & list2)
{
	List list3, list4;
	int num;

	while (!list1.isEmpty() && !list2.isEmpty())
	{
		if (list1.firstElement() < list2.firstElement())
		{
			num = list1.firstElement();
			list1.removeFirst();
		}
		else
		{
			num = list2.firstElement();
			list2.removeFirst();
		}
		list3.add(num);
		cout << "Add " << num << endl;
	}
	while (!list1.isEmpty())
	{
		num = list1.firstElement();
		list3.add(num);
		list1.removeFirst();
		cout << "Add " << num << endl;
	}
	while (!list2.isEmpty())
	{
		num = list2.firstElement();
		list3.add(num);
		list2.removeFirst();
		cout << "Add " << num << endl;
	}
	// Reverse the list
	while (!list3.isEmpty())
	{
		num = list3.firstElement();
		list4.add(num);
		list3.removeFirst();
	}
	return list4;
}

List reverse1(List src)
{
	List dest;
	// Reverse the list
	while (!src.isEmpty())
	{
		int num = src.firstElement();
		dest.add(num);
		src.removeFirst();
	}
	return dest;
}

std::ostream& operator<<(std::ostream & output, const List & l)
{
	List::Link* next;
	for (List::Link* p = l.head; p != NULL; p = p->next)
		output << p->value << ((p->next != NULL) ? " " : "\n");
	return output;
}

std::istream & operator>>(std::istream & input, List & l)
{
	int var; 

	while ((input.peek() != '\n'))//read line
	{
		if (input >> var) // if the input is not int;
		{
			l.insert(var);
		}
		else // empty the istream
		{
			cout << "Error Wrong type\n";
			cin.clear(); // clears the error flags
			// this line discards all the input waiting in the stream
			//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.ignore();
		}
	}
	return input;
}
