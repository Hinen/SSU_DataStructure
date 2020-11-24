#pragma once
#include "../../Week10/BinaryTree/BinaryTree.h"
#include "../../Week10/BinaryTree/BinaryTreeNode.h"

template <typename T>

class BinarySearchTree : public BinaryTree<T>
{
public:
	BinarySearchTree() : BinaryTree<T>()
	{

	}

	~BinarySearchTree()
	{

	}

public:
	void Insert(BinaryTreeNode<T>* insertNode)
	{
		Insert(insertNode, _root);
	}

private:
	void Insert(BinaryTreeNode<T>* insertNode, BinaryTreeNode<T>* parentNode)
	{
		if (insertNode == NULL)
			return;

		if (parentNode == NULL)
		{
			_root = insertNode;
			return;
		}

		T insertValue = insertNode->GetValue();
		T parentValue = parentNode->GetValue();

		if (insertValue == parentValue)
			return;

		if (insertValue > parentValue)
		{
			BinaryTreeNode<T>* right = parentNode->GetRight();
			if (right == NULL)
			{
				parentNode->SetRight(insertNode);
				return;
			}
			else
			{
				Insert(insertNode, right);
			}
		}
		else if (insertValue < parentValue)
		{
			BinaryTreeNode<T>* left = parentNode->GetLeft();
			if (left == NULL)
			{
				parentNode->SetLeft(insertNode);
				return;
			}
			else
			{
				Insert(insertNode, left);
			}
		}
	}
};