#include "DynIntStack.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void DynIntStack::push(int num)
{
	top = new StackNode(num, top);

}

void DynIntStack::pop(int& num)
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

bool DynIntStack::isEmpty() const
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
