#include "Week11Manager.h"

void Week11Manager::Main()
{
	WeekManagerBase::Main();

	BinarySearchTreeTest();
}

void Week11Manager::BinarySearchTreeTest()
{
	BinarySearchTree<int>* searchTree = new BinarySearchTree<int>();

	searchTree->Insert(new BinaryTreeNode<int>(5));

	searchTree->Insert(new BinaryTreeNode<int>(3));
	searchTree->Insert(new BinaryTreeNode<int>(9));

	searchTree->Insert(new BinaryTreeNode<int>(1));
	searchTree->Insert(new BinaryTreeNode<int>(4));
	searchTree->Insert(new BinaryTreeNode<int>(7));

	searchTree->Insert(new BinaryTreeNode<int>(2));
	searchTree->Insert(new BinaryTreeNode<int>(6));
	searchTree->Insert(new BinaryTreeNode<int>(8));

	//
	cout << endl << "9 삭제 전 레벨 순회 출력" << endl << "----------" << endl;
	searchTree->ShowValueLevelTraversal();

	//
	searchTree->Remove(9);

	cout << endl << "9 삭제 후 레벨 순회 출력" << endl << "----------" << endl;
	searchTree->ShowValueLevelTraversal();

	delete searchTree;
}