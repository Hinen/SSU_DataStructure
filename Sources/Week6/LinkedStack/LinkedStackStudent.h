#pragma once

#include <stdio.h>
#include <string.h>

#define MAX_STRING	100

class LinkedStackStudent
{
private:
	int _id;
	char _name[MAX_STRING];
	char _dept[MAX_STRING];

public:
	LinkedStackStudent(int i = 0, char* nam = "", char* dep = "")
	{
		Set(i, nam, dep);
	}

	void Set(int i, char* nam, char* dep)
	{
		_id = i;
		strcpy(_name, nam);
		strcpy(_dept, dep);
	}

	void Display()
	{
		cout << " �й� : " << _id << "\t���� : " << _name << "\t�а� : " << _dept << endl;
	}
};
