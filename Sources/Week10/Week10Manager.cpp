#include "Week10Manager.h"

void Week10Manager::Main()
{
	WeekManagerBase::Main();

	BinaryTreeTest();
}

void Week10Manager::BinaryTreeTest()
{
	BinaryTreeNode<char>* g = new BinaryTreeNode<char>('G');
	BinaryTreeNode<char>* h = new BinaryTreeNode<char>('H');

	BinaryTreeNode<char>* d = new BinaryTreeNode<char>('D');
	BinaryTreeNode<char>* e = new BinaryTreeNode<char>('E', g, h);
	BinaryTreeNode<char>* f = new BinaryTreeNode<char>('F');

	BinaryTreeNode<char>* b = new BinaryTreeNode<char>('B', d);
	BinaryTreeNode<char>* c = new BinaryTreeNode<char>('C', e, f);

	BinaryTreeNode<char>* a = new BinaryTreeNode<char>('A', b, c);

	BinaryTree<char>* tree = new BinaryTree<char>(a);

	//
	tree->ShowValueTraversal(Preorder);
	//tree->ShowValueTraversal(Inorder);
	//tree->ShowValueTraversal(Postorder);

	//
	int nodeCount = tree->GetAllNodeCount(Preorder);
	//int nodeCount = tree->GetAllNodeCount(Inorder);
	//int nodeCount = tree->GetAllNodeCount(Postorder);
	cout << "Tree Node Count : " << nodeCount << endl;

	//
	cout << "Tree Terminal Node Count : " << tree->GetTerminalNodeCount() << endl;

	//
	cout << "Tree Get Height : " << tree->GetHeight() << endl;

	delete tree;
}