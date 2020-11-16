#include "Week10Manager.h"

void Week10Manager::Main()
{
	WeekManagerBase::Main();

	BinaryTreeTest();
}

void Week10Manager::BinaryTreeTest()
{
	BinaryTreeNode* g = new BinaryTreeNode('G');
	BinaryTreeNode* h = new BinaryTreeNode('H');

	BinaryTreeNode* d = new BinaryTreeNode('D');
	BinaryTreeNode* e = new BinaryTreeNode('E', g, h);
	BinaryTreeNode* f = new BinaryTreeNode('F');

	BinaryTreeNode* b = new BinaryTreeNode('B', d);
	BinaryTreeNode* c = new BinaryTreeNode('C', e, f);

	BinaryTreeNode* a = new BinaryTreeNode('A', b, c);

	BinaryTree* tree = new BinaryTree(a);

	// ¼øÈ¸
	//tree->PreorderTraversal();
	//tree->InorderTraversal();
	//tree->PostorderTraversal();

	delete tree;
}