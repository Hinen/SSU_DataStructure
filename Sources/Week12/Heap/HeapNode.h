#pragma once

#include "../../stdafx.h"

class HeapNode
{
public:
	HeapNode(int key = 0) : _key(key) { }
	~HeapNode() { }

private:
	int	_key;

public:
	void SetKey(int k)
	{
		_key = k;
	}

	int GetKey()
	{
		return _key;
	}

	void Display()
	{
		cout << "\t" << _key;
	}
};

