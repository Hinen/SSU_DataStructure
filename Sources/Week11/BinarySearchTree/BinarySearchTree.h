#pragma once
#include "../../Week10/BinaryTree/BinaryTree.h"
#include "../../Week10/BinaryTree/BinaryTreeNode.h"

template <typename T>

class BinarySearchTree : public BinaryTree<T>
{
public:
	BinarySearchTree(BinaryTreeNode<T>* root) : BinaryTree<T>(root)
	{

	}

	~BinarySearchTree()
	{

	}
};