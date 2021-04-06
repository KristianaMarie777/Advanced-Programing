#include "SortNumberList.h"

void SortNumberList::add(double num)
{
	ListNode* nodePtr = nullptr;
	ListNode* previousNodePtr = nullptr;
	if (head == nullptr || head->value >= num)
	{
		head = new ListNode(num, head);
	}
	else
	{
		previousNodePtr = head;
		nodePtr = head->next;

		while (nodePtr != nullptr && nodePtr->value < num)
		{
			previousNodePtr = nodePtr;
			nodePtr = nodePtr->next;
		}

		previousNodePtr->next = new ListNode(num, nodePtr);

	}
}
