#pragma once
class DynIntQueue
{
private:
	class QueueNode
	{
		friend class DynIntQueue;
		int value;
		QueueNode* next;

		QueueNode(int value1, QueueNode* next1 = nullptr)
		{
			value = value1;
			next = next1;
		}
	};

	QueueNode* front;
	QueueNode* rear;

public:
	DynIntQueue()
	{
		front = nullptr;
		rear = nullptr;
	}

	~DynIntQueue()
	{
		clear();
	}

	void enqueue(int);
	void dequeue(int&);
	bool isEmpty() const;
	void clear();
};

