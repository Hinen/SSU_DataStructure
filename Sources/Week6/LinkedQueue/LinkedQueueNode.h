#pragma once

class LinkedQueueNode
{
private:
	LinkedQueueNode* _link;
	int _data;

public:
	LinkedQueueNode(int val = 0)
	{
		_data = val;
		_link = NULL;
	}

	LinkedQueueNode* GetLink()
	{
		return _link;
	}

	void SetLink(LinkedQueueNode* next)
	{
		_link = next;
	}

	void Display()
	{
		cout << " <" << _data << ">" << endl;
	}
};
