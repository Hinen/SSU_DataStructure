#pragma once

#include "../WeekManagerBase.h"
#include "LinkedList\LinkedList.h"
#include "LinkedList\LinkedListExtend.h"

class Week8Manager : public WeekManagerBase
{
public:
	Week8Manager();
	~Week8Manager();

public:
	virtual void Main() override;

private:
	void LinkedListTest();
	void LinkedListTestExtend();
};