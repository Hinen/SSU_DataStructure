#include "Week11Manager.h"

void Week11Manager::Main()
{
	WeekManagerBase::Main();

	BinarySearchTreeTest();
}

void Week11Manager::BinarySearchTreeTest()
{
	BinaryTreeNode<int>* a = new BinaryTreeNode<int>(5);
	BinarySearchTree<int>* tree = new BinarySearchTree<int>(a);

	delete tree;
}