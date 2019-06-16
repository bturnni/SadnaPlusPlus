#include "QueueStack.h"

QueueStack::QueueStack()
{
}

void QueueStack::clear()
{
	while (!data.empty())
	{
		data.pop();
	}
}

int QueueStack::dequeue()
{
	//reversing the data stk;
	std::stack<int> tmp;
	while (!data.empty())
	{
		tmp.push(data.top());
		data.pop();
	}
	int value = tmp.top();
	tmp.pop();
	while (!tmp.empty())
	{
		data.push(tmp.top());
		tmp.pop();
	}
	return value;
}

void QueueStack::enqueue(int value)
{
	data.push(value);
}

int QueueStack::front()
{
	int value;
	//reversing the data stk;
	std::stack<int> tmp;
	while (!data.empty())
	{
		tmp.push(data.top());
		data.pop();
	}
	value = tmp.top();
	while (!tmp.empty())
	{
		data.push(tmp.top());
		tmp.pop();
	}
	return value;
}

bool QueueStack::isEmpty() const
{
	return data.empty();
}
