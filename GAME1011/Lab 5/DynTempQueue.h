#pragma once
#ifndef _DYN_TEMP_QUEUE_H
#define _DYN_TEMP_QUEUE_H

#include <iostream>

using namespace std;

template <class T>
class DynTempQueue
{
private:
	class QueueNode
	{
		friend class DynTempQueue<T>;
		T value;
		QueueNode* next;

		QueueNode(T value1, QueueNode* next1 = nullptr)
		{
			value = value1;
			next = next1;
		}
	};

	QueueNode* front;
	QueueNode* rear;

public:
	DynTempQueue()
	{
		front = nullptr;
		rear = nullptr;
	}

	~DynTempQueue()
	{
		clear();
	}

	void enqueue(T);
	void dequeue(T&);
	bool isEmpty() const;
	void clear();
};

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


#endif // !_DYN_TEMP_QUEUE_H


