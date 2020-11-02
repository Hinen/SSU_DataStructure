#pragma once

#include "Node.h"

class LinkedList
{
private:
	Node _org;

public:
	LinkedList() : _org(0) { }
	~LinkedList()
	{
		Clear();
	}

	Node* GetHead()
	{
		return _org.GetLink();
	}

	bool IsEmpty()
	{
		return GetHead() == NULL;
	}

	void Clear()
	{
		while (!IsEmpty())
			delete Remove(0);
	}

	Node* GetEntry(int pos)
	{
		Node* n = &_org;
		for (int i = -1; i < pos; i++, n = n->GetLink())
		{
			if (n == NULL)
				break;
		}

		return n;
	}

	void Insert(int pos, Node* n)
	{
		Node* prev = GetEntry(pos - 1);
		if (prev != NULL)
			prev->InsertNext(n);
	}

	Node* Remove(int pos)
	{
		Node* prev = GetEntry(pos - 1);
		return prev->RemoveNext();
	}

	void Display()
	{
		cout << "[단순연결리스트 항목 수 = " << Size() << "] : ";
		for (Node *p = GetHead(); p != NULL; p = p->GetLink())
			p->Display();

		cout << endl;
	}

	int Size()
	{
		int count = 0;
		for (Node *p = GetHead(); p != NULL; p = p->GetLink())
			count++;

		return count;
	}

	void Replace(int pos, Node* n)
	{
		Node* prev = GetEntry(pos - 1);
		if (prev != NULL)
		{
			prev->SetLink(n);

			Node* node = prev->GetLink();
			if (node != NULL)
				n->SetLink(node->GetLink());
		}
	}
};