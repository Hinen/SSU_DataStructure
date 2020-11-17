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

	//
	cout << "Tree Order Traversal" << endl;
	tree->ShowValueTraversal(BinaryTree::Preorder);
	//tree->ShowValueTraversal(BinaryTree::Inorder);
	//tree->ShowValueTraversal(BinaryTree::Postorder);

	//
	cout << endl << "Tree Level Traversal" << endl;
	tree->ShowValueLevelTraversal();

	//
	int nodeCount = tree->GetAllNodeCount(BinaryTree::Preorder);
	//int nodeCount = tree->GetAllNodeCount(BinaryTree::Inorder);
	//int nodeCount = tree->GetAllNodeCount(BinaryTree::Postorder);
	cout << endl << "Tree Node Count : " << nodeCount << endl;

	//
	cout << "Tree Terminal Node Count : " << tree->GetTerminalNodeCount() << endl;

	//
	cout << "Tree Get Height : " << tree->GetHeight() << endl;

	delete tree;
}
