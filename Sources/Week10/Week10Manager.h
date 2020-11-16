#pragma once

#include "../WeekManagerBase.h"
#include "BinaryTree\BinaryTree.h"
#include "BinaryTree\BinaryTreeNode.h"

class Week10Manager : public WeekManagerBase
{
public:
	Week10Manager() : WeekManagerBase(10) {}
	~Week10Manager() {}

public:
	virtual void Main() override;

private:
	void BinaryTreeTest();
};