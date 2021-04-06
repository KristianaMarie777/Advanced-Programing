#include "NumberList.h"

NumberList::~NumberList()
{
	ListNode* nodePtr = head;
	while (nodePtr != nullptr)
	{
		ListNode* garbage = nodePtr;
		nodePtr = nodePtr->next;

		delete garbage;
	}
}

void NumberList::add(double num)
{
	if (head == nullptr)
	{
		head = new ListNode(num);
	}
	else
	{
		ListNode* nodePtr = head;
		while (nodePtr = nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}

		nodePtr->next = new ListNode(num);
	}
}

void NumberList::displayList() const
{
	ListNode* nodePtr = head;

	while (nodePtr)
	{
		std::cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}
}
