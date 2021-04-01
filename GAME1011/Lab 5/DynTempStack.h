#pragma once
#ifndef _DYN_TEMP_STACK_H
#define _DYN_TEMP_STACK_H

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
public:
	DynTempStack()
	{
		top = nullptr;
	}
	void push(T);
	void pop(T&);
	bool isEmpty() const;
};

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


#endif // !_DYN_TEMP_STACK_H


