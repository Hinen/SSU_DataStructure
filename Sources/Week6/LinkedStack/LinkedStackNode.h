#pragma once

#include "LinkedStackStudent.h"

class LinkedStackNode : public LinkedStackStudent
{
private:
	LinkedStackNode* _link;

public:
	LinkedStackNode(int id = 0, char* name = "", char* dept = "") : LinkedStackStudent(id, name, dept)
	{
		_link = NULL;
	}

	~LinkedStackNode(void)
	{
		// DO NOTHING
	}

	LinkedStackNode* GetLink()
	{
		return _link;
	}
	
	void SetLink(LinkedStackNode *p)
	{
		_link = p;
	}
};
