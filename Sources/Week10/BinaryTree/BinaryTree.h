#pragma once
#include "BinaryTreeNode.h"
#include "BinaryTreeTraversalType.h"
#include <queue>

template<typename T>

class BinaryTree
{
public:
	BinaryTree(BinaryTreeNode<T>* root)
	{
		_root = root;
	}

	~BinaryTree()
	{
		delete _root;
	}

private:
	BinaryTreeNode<T>* _root;

public:
	void ShowValueTraversal(BinaryTreeTraversalType type)
	{
		ShowValueTraversal(_root, type);
	}

	void ShowValueLevelTraversal()
	{
		queue<BinaryTreeNode<T>*>* _queue = new queue<BinaryTreeNode<T>*>();
		_queue->push(_root);

		ShowValueLevelTraversal(_queue);

		delete _queue;
	}

	int GetAllNodeCount(BinaryTreeTraversalType type)
	{
		return GetAllNodeCountTraversal(_root, type);
	}

	int GetTerminalNodeCount()
	{
		return GetTerminalNodeCount(_root);
	}

	int GetHeight()
	{
		return GetHeight(_root);
	}

private:
	void ShowValueTraversal(BinaryTreeNode<T>* node, BinaryTreeTraversalType type)
	{
		if (node == NULL)
			return;

		if (type == Preorder)
			cout << node->GetValue() << endl;

		ShowValueTraversal(node->GetLeft(), type);

		if (type == Inorder)
			cout << node->GetValue() << endl;

		ShowValueTraversal(node->GetRight(), type);

		if (type == Postorder)
			cout << node->GetValue() << endl;
	}

	void ShowValueLevelTraversal(queue<BinaryTreeNode<T>*>* queue)
	{
		if (queue->size() == 0)
			return;

		BinaryTreeNode<T>* node = queue->front();
		queue->pop();

		if (node != NULL)
		{
			cout << node->GetValue() << endl;
			queue->push(node->GetLeft());
			queue->push(node->GetRight());
		}

		ShowValueLevelTraversal(queue);
	}

	int GetAllNodeCountTraversal(BinaryTreeNode<T>* node, BinaryTreeTraversalType type)
	{
		int count = 0;

		if (node == NULL)
			return count;

		if (type == Preorder)
			count++;

		count += GetAllNodeCountTraversal(node->GetLeft(), type);

		if (type == Inorder)
			count++;

		count += GetAllNodeCountTraversal(node->GetRight(), type);

		if (type == Postorder)
			count++;

		return count;
	}

	int GetTerminalNodeCount(BinaryTreeNode<T>* node)
	{
		if (node == NULL)
			return 0;

		if (node->GetLeft() == NULL && node->GetRight() == NULL)
			return 1;
		
		return GetTerminalNodeCount(node->GetLeft()) + GetTerminalNodeCount(node->GetRight());
	}

	int GetHeight(BinaryTreeNode<T>* node)
	{
		if (node == NULL)
			return 0;

		int leftHeight = GetHeight(node->GetLeft());
		int rightHeight = GetHeight(node->GetRight());

		return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
	}
};