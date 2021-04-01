#pragma once

template <class T>
class DynTempQueue
{
private:
	class QueueNode
	{
		friend class DynTempQueue;
		T value;
		QueueNode* next;

		QueueNode(T value1, QueueNode* next1 = nullptr)
		{
			value = value1;
			next = next1;
		}
	};

	QueueNode* front;
	QueueNode* rear;

public:
	DynTempQueue()
	{
		front = nullptr;
		rear = nullptr;
	}

	~DynTempQueue()
	{
		clear();
	}

	void enqueue(T);
	void dequeue(T&);
	bool isEmpty() const;
	void clear();
};
