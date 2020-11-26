#pragma once

#include "../WeekManagerBase.h"
#include "Heap\MaxHeap.h"
#include <queue>
#include <functional>

class Week12Manager : public WeekManagerBase
{
public:
	Week12Manager() : WeekManagerBase(12) {}
	~Week12Manager() {}

public:
	virtual void Main() override;

private:
	void MaxHeapTest();
	void PriorityQueueTest();
	void HeapSortInc(int a[], int n);
	void HeapSortDec(int a[], int n);
};