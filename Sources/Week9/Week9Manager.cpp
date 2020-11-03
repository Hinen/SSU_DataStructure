#include "Week9Manager.h"

void Week9Manager::Main()
{
	WeekManagerBase::Main();

	//cout << SumRecursion(10) << endl;
	//cout << SumRecursion2(3) << endl;

	char* a = "asdf";
	char* b = StrReverseRecursion(a);
	cout << a << endl << b << endl;
}

int Week9Manager::SumRecursion(int num)
{
	return num == 1 ? 1 : num + SumRecursion(num - 1);
}

float Week9Manager::SumRecursion2(int num)
{
	return num == 1.f ? 1.f : 1.f / num + SumRecursion2(num - 1);
}

char* Week9Manager::StrReverseRecursion(char* str)
{
	int len = strlen(str);

	if (len == 1)
	{
		char* str2 = new char[0];
		strcpy(str2, str);
		return str2;
	}
	else
	{
		char* str2 = new char[len];
		strcpy(str2, str + 1);

		char* newStr = StrReverseRecursion(str2);
		delete str2;

		return strncat(newStr, str, 1);
	}
}
