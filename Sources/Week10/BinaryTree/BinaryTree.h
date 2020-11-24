#pragma once
#include "BinaryTreeNode.h"
#include "BinaryTreeTraversalType.h"

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
		ShowValueTraversal(_root, 1, type);
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
	void ShowValueTraversal(BinaryTreeNode<T>* node, int level, BinaryTreeTraversalType type)
	{
		if (node == NULL)
			return;

		if (type == Preorder)
			cout << "Level " << level << " " << node->GetValue() << endl;

		ShowValueTraversal(node->GetLeft(), level + 1, type);

		if (type == Inorder)
			cout << "Level " << level << " " << node->GetValue() << endl;

		ShowValueTraversal(node->GetRight(), level + 1, type);

		if (type == Postorder)
			cout << "Level " << level << " " << node->GetValue() << endl;
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