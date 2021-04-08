#pragma once
#ifndef _DYN_TEMP_STACK_H
#define _DYN_TEMP_STACK_H

#include <iostream>

using namespace std;

template <class T>
class DynTempStack
{
private:
	class StackNode
	{
		friend class DynTempStack<T>;
		T value;
		StackNode* next;

		StackNode(T value1, StackNode* next1 = nullptr)
		{
			value = value1;
			next = next1;
		}
	};
	StackNode* top;
	int listNum = 0;
public:
	DynTempStack()
	{
		top = nullptr;
	}
	void push(T);
	void pop(T&,bool startTop = false);
	//void find(T, T&);
	void find(int, T&);
	bool isEmpty() const;
	void displayList_Num();
	int size() const { return listNum; }
};

template <class T>
void DynTempStack<T>::push(T num)
{
	top = new StackNode(num, top);
	listNum++;
}

template <class T>
void DynTempStack<T>::pop(T& num, bool startTop)
{
	StackNode* temp;
	if (isEmpty())
	{
		cout << "The stack is empty.\n";
		exit(1);
	}
	else
	{
		num = top->value;
		listNum--;
		temp = top;
		top = top->next;

		delete temp; 

		temp = nullptr;
	}

}

template<class T>
void DynTempStack<T>::find(int num, T& find)
{

	if (num >= listNum || num < 0)
	{
		cout << "List Item does not exist.\n";
		exit(1);
	}
	else
	{

		DynTempStack<T> items;

		for (int i = 0; i  <num; i++)
		{
			T item;

			pop(item);
			items.push(item);

		}
		
		T check;

		pop(check);

		find = check;
		

		while (!items.isEmpty())
		{
			T item;

			items.pop(item);
			push(item);
		}
		listNum--;
	}

}

template <class T>
bool DynTempStack<T>::isEmpty() const
{
	if (!top)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
void DynTempStack<T>::displayList_Num()
{
	StackNode* item = top;
	int num = 0;
	while (item != nullptr)
	{
		cout << num++ << ". " << item->value << endl;
		item = item->next;
	}
}


#endif // !_DYN_TEMP_STACK_H


