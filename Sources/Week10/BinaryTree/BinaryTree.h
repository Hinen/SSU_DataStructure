#pragma once
#include "BinaryTreeNode.h"

class BinaryTree
{
public:
	BinaryTree(BinaryTreeNode* root)
	{
		_root = root;
	}

	~BinaryTree()
	{
		delete _root;
	}

public:
	enum TraversalType
	{
		Preorder,
		Inorder,
		Postorder
	};

private:
	BinaryTreeNode* _root;

public:
	void ShowValueTraversal(TraversalType type)
	{
		ShowValueTraversal(_root, type);
	}

	int GetAllNodeCount(TraversalType type)
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
	void ShowValueTraversal(BinaryTreeNode* node, TraversalType type)
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

	int GetAllNodeCountTraversal(BinaryTreeNode* node, TraversalType type)
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

	int GetTerminalNodeCount(BinaryTreeNode* node)
	{
		if (node == NULL)
			return 0;

		if (node->GetLeft() == NULL && node->GetRight() == NULL)
			return 1;
		
		return GetTerminalNodeCount(node->GetLeft()) + GetTerminalNodeCount(node->GetRight());
	}

	int GetHeight(BinaryTreeNode* node)
	{
		if (node == NULL)
			return 0;

		int leftHeight = GetHeight(node->GetLeft());
		int rightHeight = GetHeight(node->GetRight());

		return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
	}
};