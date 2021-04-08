#include "IntQueue.h"
#include <iostream>
#include <cstdlib>

using namespace std;

IntQueue::IntQueue(int size)
{

	queueArray = new int[size];
	queueSize = size;
	clear();

}

void IntQueue::enqueue(int num)
{
	if (isFull())
	{

		cout << "The queue is full.\n";
		exit(1);

	}
	else
	{
		rear = (rear + 1) % queueSize;
		queueArray[rear] = num;
		numItems++;
	}
}

void IntQueue::dequeue(int& num)
{
	if (isEmpty())
	{

		cout << "The queue is empty.\n";
		exit(1);

	}
	else
	{

		front = (front + 1) % queueSize;

		num = queueArray[front];

		numItems--;

	}
}

bool IntQueue::isEmpty() const
{
	if (numItems > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool IntQueue::isFull() const
{
	if (numItems < queueSize)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void IntQueue::clear()
{
	front = -1;
	rear = -1;
	numItems = 0;
}
