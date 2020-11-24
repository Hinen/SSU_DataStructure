#pragma once
#include "../../stdafx.h"

template <typename T>

class BinaryTreeNode
{
public:
	BinaryTreeNode(T value, BinaryTreeNode* left = NULL, BinaryTreeNode* right = NULL)
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
	T _value;

	BinaryTreeNode* _left;
	BinaryTreeNode* _right;

public:
	T GetValue()
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

	void SetLeft(BinaryTreeNode* node)
	{
		_left = node;
	}

	void SetRight(BinaryTreeNode* node)
	{
		_right = node;
	}
};