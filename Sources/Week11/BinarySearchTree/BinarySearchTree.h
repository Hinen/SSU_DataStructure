#pragma once
#include "../../Week10/BinaryTree/BinaryTree.h"
#include "../../Week10/BinaryTree/BinaryTreeNode.h"
#include <math.h>

template <typename T>

class BinarySearchTree : public BinaryTree<T>
{
public:
	BinarySearchTree() : BinaryTree<T>() {}

	~BinarySearchTree() {}

public:
	void Insert(BinaryTreeNode<T>* insertNode)
	{
		Insert(insertNode, _root);
	}

	bool Remove(T value)
	{
		return Remove(value, NULL, _root);
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

	bool Remove(T value, BinaryTreeNode<T>* parentNode, BinaryTreeNode<T>* targetNode)
	{
		if (targetNode == NULL)
			return NULL;

		T targetValue = targetNode->GetValue();

		if (value == targetValue)
		{
			BinaryTreeNode<T>* leftNode = targetNode->GetLeft();
			BinaryTreeNode<T>* rightNode = targetNode->GetRight();

			if (leftNode == NULL && rightNode == NULL)
			{
				if (targetNode == _root)
				{
					_root = NULL;
				}
				else
				{
					if (parentNode->GetLeft() == targetNode)
						parentNode->SetLeft(NULL);
					else if (parentNode->GetRight() == targetNode)
						parentNode->SetRight(NULL);
				}

				targetNode->SetLeft(NULL);
				targetNode->SetRight(NULL);
				delete targetNode;
			}
			else if (leftNode == NULL || rightNode == NULL)
			{
				BinaryTreeNode<T>* nextTargetNode = leftNode != NULL ? leftNode : rightNode;

				if (targetNode == _root)
				{
					_root = nextTargetNode;
				}
				else
				{
					if (parentNode->GetLeft() == targetNode)
						parentNode->SetLeft(nextTargetNode);
					else if (parentNode->GetRight() == targetNode)
						parentNode->SetRight(nextTargetNode);
				}

				targetNode->SetLeft(NULL);
				targetNode->SetRight(NULL);
				delete targetNode;
			}
			else
			{
				BinaryTreeNode<T>* leftMaxNode = leftNode;
				BinaryTreeNode<T>* rightMinNode = rightNode;

				while (leftMaxNode->GetRight() != NULL)
					leftMaxNode = leftMaxNode->GetRight();

				while (rightMinNode->GetLeft() != NULL)
					rightMinNode = rightMinNode->GetLeft();

				T leftDiff = abs(leftMaxNode->GetValue() - targetValue);
				T rightDiff = abs(rightMinNode->GetValue() - targetValue);

				BinaryTreeNode<T>* nextChildNode = leftDiff < rightDiff ? leftMaxNode : rightMinNode;
				T nextChildValue = nextChildNode->GetValue();

				Remove(nextChildValue);
				targetNode->SetValue(nextChildValue);
			}

			return true;
		}

		if (value > targetValue)
			return Remove(value, targetNode, targetNode->GetRight());
		else if (value < targetValue)
			return Remove(value, targetNode, targetNode->GetLeft());
	}
};