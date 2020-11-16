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
		ShowValueTraversal(_root, 1, type);
	}

	int GetAllNodeCount(TraversalType type)
	{
		return GetAllNodeCountTraversal(_root, type);
	}

private:
	void ShowValueTraversal(BinaryTreeNode* node, int level, TraversalType type)
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
};