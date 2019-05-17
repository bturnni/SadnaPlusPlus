#pragma once
#include "List.h"
class RoundList : public List
{
public:
	friend std::ostream& operator<<(std::ostream& out, const RoundList& l);
	void add(int val);
	void addToEnd(int val);
	void removeFirst();
	void clear();
	int search(int ind) const;
	List::Link* lastNode();

};

