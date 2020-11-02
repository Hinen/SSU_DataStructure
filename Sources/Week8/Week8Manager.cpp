#include "Week8Manager.h"

Week8Manager::Week8Manager() : WeekManagerBase(8)
{

}

Week8Manager::~Week8Manager()
{

}

void Week8Manager::Main()
{
	WeekManagerBase::Main();

	LinkedListTest();
}

void Week8Manager::LinkedListTest()
{
	LinkedList list;

	list.Insert(0, new Node(10));
	list.Insert(0, new Node(20));
	list.Insert(1, new Node(30));
	list.Insert(list.Size(), new Node(40));
	list.Insert(2, new Node(50));

	list.Display();

	list.Remove(2);
	list.Remove(list.Size() - 1);
	list.Remove(0);

	list.Replace(1, new Node(90));
	list.Display();

	list.Clear();
	list.Display();
}