#pragma once

#include "LinkedList.h"

class LinkedListExtend : public LinkedList
{
public:
	LinkedListExtend() : LinkedList() { }
	~LinkedListExtend() { }

	void Display(char* str)
	{
		cout << str;
		LinkedList::Display();
	}

	void Reverse()
	{
		Node* n1 = NULL;

		for (Node* p = GetHead(); p != NULL; p = p->GetLink())
		{
			if (p == NULL)
				continue;

			Node* n2 = new Node(p->GetData());
			if (n1 != NULL)
				n2->SetLink(n1);

			n1 = n2;
		}

		Clear();
		SetHead(n1);
	}

	void Merge(LinkedList* that)
	{
		if (that == NULL)
			return;

		Node* last = GetEntry(Size() - 1);
		for (Node* p = that->GetHead(); p != NULL; p = p->GetLink())
		{
			last->SetLink(p);
			last = p;
		}

		that->SetHead(NULL);
	}
};