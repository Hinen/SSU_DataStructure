#pragma once

#include "../WeekManagerBase.h"
#include "BinarySearchTree\BinarySearchTree.h"
#include "../Week10/BinaryTree/BinaryTreeNode.h"

class Week11Manager : public WeekManagerBase
{
public:
	Week11Manager() : WeekManagerBase(11) {}
	~Week11Manager() {}

public:
	virtual void Main() override;

private:
	void BinarySearchTreeTest();
};