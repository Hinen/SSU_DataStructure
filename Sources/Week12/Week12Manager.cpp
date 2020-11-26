#include "Week12Manager.h"

void Week12Manager::Main()
{
	WeekManagerBase::Main();

	MaxHeapTest();
}

void Week12Manager::MaxHeapTest()
{
	MaxHeap heap;

	//
	heap.Insert(10);
	heap.Insert(5);
	heap.Insert(30);
	heap.Insert(8);
	heap.Insert(9);
	heap.Insert(3);
	heap.Insert(7);
	heap.Display();

	//
	heap.Remove();
	heap.Display();

	heap.Remove();
	heap.Display();

	cout << endl;
}