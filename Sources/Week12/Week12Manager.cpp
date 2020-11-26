#include "Week12Manager.h"

void Week12Manager::Main()
{
	WeekManagerBase::Main();

	//MaxHeapTest();
	PriorityQueueTest();
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

void Week12Manager::PriorityQueueTest()
{
	int arr[] = { 7, 0, 8, 4 };

	//
	HeapSortInc(arr, sizeof(arr) / sizeof(int));
	for (int n : arr)
		cout << n << "\t";

	cout << endl;

	//
	HeapSortDec(arr, sizeof(arr) / sizeof(int));
	for (int n : arr)
		cout << n << "\t";

	cout << endl;
}

void Week12Manager::HeapSortInc(int arr[], int arrSize)
{
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for (int i = 0; i < arrSize; i++)
	{
		minHeap.push(arr[i]);
	}

	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = minHeap.top();
		minHeap.pop();
	}
}

void Week12Manager::HeapSortDec(int arr[], int arrSize)
{
	priority_queue<int> maxHeap;

	for (int i = 0; i < arrSize; i++)
	{
		maxHeap.push(arr[i]);
	}

	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = maxHeap.top();
		maxHeap.pop();
	}
}