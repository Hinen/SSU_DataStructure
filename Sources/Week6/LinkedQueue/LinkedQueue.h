#pragma once

#include "LinkedQueueNode.h"

class LinkedQueue
{
private:
	LinkedQueueNode* _front;
	LinkedQueueNode* _rear;

public:
	LinkedQueue()
	{
		_front = NULL;
		_rear = NULL;
	}

	~LinkedQueue()
	{
		while(!IsEmpty())
			delete Dequeue();
	}

	bool IsEmpty()
	{
		return _front == NULL;
	}

	LinkedQueueNode* Peek()
	{
		return _front;
	}

	void Enqueue(LinkedQueueNode* n)
	{
		if (IsEmpty())
		{
			_front = n;
			_rear = n;
		}
		else
		{
			_rear->SetLink(n);
		}

		_rear = n;
	}

	LinkedQueueNode* Dequeue()
	{
		LinkedQueueNode* target = _front;
		if (!IsEmpty())
		{
			if (_front == _rear)
			{
				_front = NULL;
				_rear = NULL;
			}
			else
			{
				_front = _front->GetLink();
			}
		}

		return target;
	}

	void Display()
	{
		LinkedQueueNode* iter = _front;
		if (iter == NULL)
			return;

		while(true)
		{
			iter->Display();
			if (iter->GetLink() == NULL)
				break;

			iter = iter->GetLink();
		}
	}
};
