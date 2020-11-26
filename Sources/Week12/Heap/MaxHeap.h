#pragma once

#include "HeapNode.h"

#define MAX_ELEMENT	200

class MaxHeap
{
public:
	MaxHeap() : _size(0) { }
	~MaxHeap() { }

private:
	HeapNode _node[MAX_ELEMENT];
	int _size;

public:
	bool IsEmpty()
	{
		return _size == 0;
	}

	bool IsFull()
	{
		return _size == MAX_ELEMENT - 1;
	}

	HeapNode& GetParent(int i)
	{
		return _node[i / 2];
	}

	HeapNode& GetLeft(int i)
	{
		return _node[i * 2];
	}

	HeapNode& GetRight(int i)
	{
		return _node[i * 2 + 1];
	}

	HeapNode Find()
	{
		return _node[1];
	}

	void Insert(int key)
	{
		if (IsFull())
			return;

		_size++;

		int i = _size;

		while (i != 1 && key > GetParent(i).GetKey())
		{	
			_node[i] = GetParent(i);
			i /= 2;
		}

		_node[i].SetKey(key);
	}

	HeapNode remove()
	{
		if (IsEmpty())
			return NULL;

		HeapNode root = Find();
		HeapNode last = _node[_size--];

		int parent = 1;
		int	child = 2;

		while (child <= _size)
		{	

		  if (child < _size && GetLeft(parent).GetKey() < GetRight(parent).GetKey())
			  child++;

		  if (last.GetKey() >= _node[child].GetKey())
			  break;

		  _node[parent] = _node[child];
		  parent = child;

		  child *= 2;
		}

		_node[parent] = last;

		return root;
	} 

	void Display( )
	{
		int level = 1;

		for (int i = 1; i <= _size; i++)
		{
			if (i == level)
			{
				cout << endl;
				level *= 2;
			}

			_node[i].Display();
		}

		cout << endl << "-------------------------------------------";
	}
};

