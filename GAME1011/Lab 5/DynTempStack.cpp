#include "DynTempStack.h"
#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
void DynTempStack<T>::push(T num)
{
	top = new StackNode(num, top);

}

template <class T>
void DynTempStack<T>::pop(T& num)
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

		temp = top;
		top = top->next;

		delete temp;

		temp = nullptr;
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
