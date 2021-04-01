#include "IntStack.h"

IntStack::IntStack(int capacity)
{
	this->capacity = capacity;
	stackArray = new int[capacity];
	top = 0;
}

void IntStack::push(int value)
{
	if (top == capacity)
	{
		throw IntStack::OverFlow();
	}

	stackArray[top] = value;
	top++;
}

void IntStack::pop(int& value)
{
	if (isEmpty())
	{
		throw IntStack::UnderFlow();
	}
	top--;
	value = stackArray[top];
}

bool IntStack::isEmpty() const
{
	if (top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}