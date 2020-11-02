#pragma once

#include "../../stdafx.h"

class Node
{
private:
	Node* _link;
	int _data;

public:
	Node(int val = 0) : _data(val), _link(NULL) {}
	~Node() {}

	Node* GetLink()
	{
		return _link;
	}

	void SetLink(Node* next)
	{
		_link = next;
	}

	void Display()
	{
		cout << " <" << _data << ">";
	}
	
	bool HasData(int val)
	{
		return _data == val;
	}

	void InsertNext(Node *n)
	{
		if (n != NULL)
		{
			n->_link = _link;
			_link = n;
		}
	}

	Node* RemoveNext()
	{
		Node* removed = _link;
		if (removed != NULL)
			_link = removed->_link;

		return removed;
	}
};
