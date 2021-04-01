#include "DynIntQueue.h"
#include <iostream>

using namespace std;

void DynIntQueue::enqueue(int num)
{
	if (isEmpty())
	{
		front = new QueueNode(num);
		rear = front;
	}
	else
	{
		rear->next = new QueueNode(num);
		rear = rear->next;
	}
}

void DynIntQueue::dequeue(int& num)
{
	QueueNode* temp;

	if (isEmpty())
	{
		cout << "The queue is empty.\n";
		exit(1);
	}
	else
	{
		num = front->value;
		temp = front;
		front = front->next;
		delete temp;
		temp = nullptr;
	}
}

bool DynIntQueue::isEmpty() const
{
	if (front == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void DynIntQueue::clear()
{
	int value;

	while (!isEmpty())
	{
		dequeue(value);
	}
}
