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

	//LinkedListTest();
	LinkedListTestExtend();
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

void Week8Manager::LinkedListTestExtend()
{
	LinkedListExtend list, list2;

	list.Insert(0, new Node(10));
	list.Insert(0, new Node(20));
	list.Insert(1, new Node(30));
	list.Insert(list.Size(), new Node(40));
	list.Insert(2, new Node(50));
	list.Display("List(Àü)");

	list.Reverse();
	list.Display("List(ÈÄ)");

	list2.Insert(0, new Node(70));
	list2.Insert(1, new Node(80));
	list2.Insert(2, new Node(90));
	list2.Display("List(that)");

	list.Merge(&list2);
	list.Display("List(reverse+that)");
	list2.Display("List(that)");

	list.Clear();
	list2.Clear();
	list.Display("List(³¡)");
}