#pragma once
#include "Queue.h"
#include <stack>
class QueueStack : public Queue
{
protected:
	std::stack<int> data;     // 
public:
	~QueueStack() { clear(); }
	QueueStack();
	void clear() override;
	int dequeue() override;
	void enqueue(int value) override;
	int front() override;
	bool isEmpty() const override;
};


