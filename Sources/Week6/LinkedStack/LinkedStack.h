#pragma once

#include "LinkedStackNode.h"

class LinkedStack
{
private:
	LinkedStackNode* _top;

public:
	LinkedStack()
	{
		_top = NULL;
	}

	~LinkedStack()
	{
		while(!IsEmpty())
			delete Pop();
	}

	bool IsEmpty()
	{
		return _top == NULL;
	}

	LinkedStackNode* Peek()
	{
		return _top;
	}

	void Push(LinkedStackNode *n)
	{
		if (_top != NULL)
			n->SetLink(_top);

		_top = n;
	}

	LinkedStackNode* Pop()
	{
		LinkedStackNode* target = _top;

		if (_top != NULL)
			_top = _top->GetLink();

		return target;
	}

	void Display()
	{
		LinkedStackNode* now = _top;
		if (now == NULL)
			return;

		while(true)
		{
			now->Display();
			if (now->GetLink() == NULL)
				break;
			
			now = now->GetLink();
		}
	}
};
