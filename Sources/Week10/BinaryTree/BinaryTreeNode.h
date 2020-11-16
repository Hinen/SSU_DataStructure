#pragma once
#include "../../stdafx.h"

class BinaryTreeNode
{
public:
	BinaryTreeNode(char value, BinaryTreeNode* left = NULL, BinaryTreeNode* right = NULL)
	{
		_value = value;
		_left = left;
		_right = right;
	}

	~BinaryTreeNode()
	{
		if (_left != NULL)
			delete _left;

		if (_right != NULL)
			delete _right;
	}

private:
	char _value;

	BinaryTreeNode* _left;
	BinaryTreeNode* _right;

public:
	char GetValue()
	{
		return _value;
	}

	BinaryTreeNode* GetLeft()
	{
		return _left;
	}

	BinaryTreeNode* GetRight()
	{
		return _right;
	}
};