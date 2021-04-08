#pragma once
#ifndef _DYN_TEMP_QUEUE_H
#define _DYN_TEMP_QUEUE_H

#include <iostream>
#include "DynTempStack.h"

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
		QueueNode* before;

		QueueNode(T value1, QueueNode* before1 = nullptr,QueueNode* next1 = nullptr)
		{
			value = value1;
			next = next1;
			before = before1;
		}
	};
	int listNum = 0;
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
	//void displayList_F();
	//void displayList_B();
	int size() const { return listNum; }
	//void find_F(int num, T& find);
	//void find_B(int num, T& find);
};
//
//template<class T>
//void DynTempQueue<T>::displayList_F()
//{
//	QueueNode* item = front;
//	int num = 0;
//	while (item != nullptr)
//	{
//		cout << num++ << ". " << item->value << endl;
//		item = item->next;
//	}
//}
//
//template<class T>
//void DynTempQueue<T>::displayList_B()
//{
//	QueueNode* item = rear;
//	int num = 0;
//	while (item->before != nullptr)
//	{
//		cout << num++ << ". " << item->value << endl;
//		item = item->before;
//	}
//}
//
//template<class T>
//void DynTempQueue<T>::find_F(int num, T& find)
//{
//
//	if (num >= listNum || num < 0)
//	{
//		cout << "List Item does not exist.\n";
//		exit(1);
//	}
//	else
//	{
//		DynTempQueue<T> items;
//
//		for (int i = 0; i <  num; i++)
//		{
//			T itemsIn;
//
//			dequeue(itemsIn);
//
//			items.enqueue(itemsIn);
//
//		}
//
//		T one, two;
//		
//		dequeue(one);
//
//		find = one;
//		while (!items.isEmpty())
//		{
//			T itemsIn;
//
//			items.dequeue(itemsIn);
//
//			enqueue(itemsIn);
//
//		}
//
//		listNum--;
//	}
//
//}
//
//template<class T>
//void DynTempQueue<T>::find_B(int num, T& find)
//{
//
//	if (num >= listNum || num < 0)
//	{
//		cout << "List Item does not exist.\n";
//		exit(1);
//	}
//	else
//	{
//		DynTempStack<T> items;
//
//		for (int i = listNum-1; i > num; i--)
//		{
//			T itemsIn;
//
//			dequeue(itemsIn);
//
//			items.push(itemsIn);
//
//		}
//
//		T one, two;
//
//		dequeue(one);
//
//		find = one;
//
//		while (!items.isEmpty())
//		{
//			T itemsIn;
//			QueueNode* temp;
//
//			items.dequeue(itemsIn);
//
//			enqueue(itemsIn);
//
//
//
//		}
//
//		listNum--;
//	}
//
//}

template <class T>
void DynTempQueue<T>::enqueue(T num)
{
	listNum++;
	if (isEmpty())
	{
		front = new QueueNode(num);
		rear = front;
	}
	else
	{
		rear->next = new QueueNode(num);

		
		if (rear->before != nullptr)
		{
			rear->next->before = rear;
		}

		rear = rear->next;
		
		if (rear->before == nullptr)
		{
			rear->before = front;
		}
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
		listNum--;
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


