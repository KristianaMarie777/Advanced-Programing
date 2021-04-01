#include "DynTempQueue.h"
#include <iostream>

using namespace std;

template <class T>
void DynTempQueue<T>::enqueue(T num)
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

template <class T>
void DynTempQueue<T>::dequeue(T& num)
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

template <class T>
bool DynTempQueue<T>::isEmpty() const
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

template <class T>
void DynTempQueue<T>::clear()
{
	T value;

	while (!isEmpty())
	{
		dequeue(value);
	}
}
