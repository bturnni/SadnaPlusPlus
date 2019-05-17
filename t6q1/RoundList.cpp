#include "RoundList.h"

void RoundList::addToEnd(int val)
{
	if (isEmpty())
		add(val);
	else
	{
		Link* p = lastNode();
		p->next = new Link(val, head);
		if (p->next == NULL)
			throw "failed in memory allocation";
	}
}

void RoundList::add(int val)
{
	if (isEmpty())
	{
		head = new Link(val, NULL);
		head->next = head;
	}
	else
	{	
		Link* last = RoundList::lastNode();
		head = new Link(val, head);
		last->next = head;
	}
}
List::Link* RoundList::lastNode()
{
	Link* p = head;
  	while (p->next != head) // cheack if the next node is head, end of list;
		p = p->next;
	return p;
}

std::ostream& operator<<(std::ostream& out, const RoundList& l)
{
	if (!l.isEmpty())
	{
		List::Link* p = l.head;
		do
		{
			out << p->value << " ";
			p = p->next;
		} while (p != l.head);
	}
	return out;
}

void RoundList::removeFirst()
{
	// check if empty
	if (isEmpty())
		throw string("the List is empty, no first element to remove");
	else if (head == head->next) // one node only
	{
		head->next = NULL;
		delete head;
		head = NULL;
	}
	else
	{
		Link* newHead = head->next;
		lastNode()->next = head->next;
		delete head;
		head = newHead;
	}
}
void RoundList::clear()
{
	while (head)//there is node
	{
		removeFirst();
	}
}

int RoundList::search(int ind) const
{
	if (ind < 0)
		throw string("Index can't be negative!");
	if (isEmpty())
		return -1;

	Link* p = head;
	for (int i = 0; i < ind; i++)
		p = p->next;

	return p->value;
}