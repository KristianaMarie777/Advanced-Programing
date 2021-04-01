#pragma once
#ifndef _DYN_INT_STACK_H
#define _DYN_INT_STACK_H

class DynIntStack
{
private:
	class StackNode
	{
		friend class DynIntStack;
		int value;
		StackNode* next;

		StackNode(int value1, StackNode* next1 = nullptr)
		{
			value = value1;
			next = next1;
		}
	};
	StackNode* top;
public:
	DynIntStack()
	{
		top = nullptr;
	}
	void push(int);
	void pop(int&);
	bool isEmpty() const;
};

#endif // !_DYN_INT_STACK_H


