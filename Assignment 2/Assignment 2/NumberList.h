#pragma once
#ifndef _ROOM_H_
#define _ROOM_H_

#include <string>
#include <iostream>

class NumberList
{
protected:

	struct ListNode
	{
		double value;

		ListNode* next;

		ListNode(double value1, ListNode* next1 = nullptr)
		{
			value = value1;
			next = next1;
		}
	};

	ListNode* head;
public:

	NumberList()
	{
		head = nullptr;
	}
	
	~NumberList()
	{
	}
};

#endif