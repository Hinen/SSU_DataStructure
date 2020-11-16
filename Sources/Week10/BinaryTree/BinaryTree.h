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

private:
	enum TraversalType
	{
		Preorder,
		Inorder,
		Postorder
	};

private:
	BinaryTreeNode* _root;

public:
	void PreorderTraversal()
	{
		Traversal(_root, 1, Preorder);
	}

	void InorderTraversal()
	{
		Traversal(_root, 1, Inorder);
	}

	void PostorderTraversal()
	{
		Traversal(_root, 1, Postorder);
	}

private:
	void Traversal(BinaryTreeNode* node, int level, TraversalType type)
	{
		if (node == NULL)
			return;

		if (type == Preorder)
			cout << "Level " << level << " " << node->GetValue() << endl;

		Traversal(node->GetLeft(), level + 1, type);

		if (type == Inorder)
			cout << "Level " << level << " " << node->GetValue() << endl;

		Traversal(node->GetRight(), level + 1, type);

		if (type == Postorder)
			cout << "Level " << level << " " << node->GetValue() << endl;
	}
};