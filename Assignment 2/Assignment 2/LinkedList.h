#pragma once
#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

using namespace std;

template <class T>
class LinkedList
{
protected:
	struct ListNode
	{
		T value;
		ListNode* next;

		ListNode(T valuse1, ListNode* next1 = nullptr)
		{
			value = value1;
			next = next1;
		}
	};

	ListNode* head;
public:

	LinkedList()
	{
		head = nullptr;
	}
	~LinkedList();
	void add(T value);
	void remove(T value);
	void displayList() const;
};

#endif // !_LINKED_LIST_H_

template<class T>
LinkedList<T>::~LinkedList()
{
	ListNode* nodePtr = head;
	while (nodePtr != nullptr)
	{
		ListNode* garbage = nodePtr;
		nodePtr = nodePtr->next;
		delete garbage;
	}
}

template<class T>
void LinkedList<T>::add(T value)
{
	if (head == nullptr)
	{
		head = new ListNode(value);
	}
	else
	{
		ListNode* nodePtr = head;

		while (nodePtr->next != nullptr)
		{
			nodePtr = nodePtr->next;
		}

		nodePtr->next = new ListNode(value);
	}
}

template<class T>
void LinkedList<T>::remove(T value)
{
	ListNode* nodePtr = nullptr;
	ListNode* previousNodePtr = nullptr;

	if (!head)
	{
		cout << "List is Empty.\n";
		return;
	}

	if (head->value == value)
	{
		nodePtr = head;
		head = head->next;
		delete nodePtr;
	}
	else
	{
		nodePtr = head;
		while (nodePtr != nullptr && nodePtr->value != value)
		{
			previousNodePtr = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr)
		{
			previousNodePtr->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

template<class T>
void LinkedList<T>::displayList() const
{
	ListNode* nodePtr = head;

	while (nodePtr)
	{
		std::cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}
}
