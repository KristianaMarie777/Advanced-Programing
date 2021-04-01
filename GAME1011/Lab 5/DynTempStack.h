#pragma once
#ifndef _DYN_INT_STACK_H
#define _DYN_INT_STACK_H

template <class T>
class DynTempStack
{
private:
	class StackNode
	{
		friend class DynTempStack;
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

#endif // !_DYN_INT_STACK_H


