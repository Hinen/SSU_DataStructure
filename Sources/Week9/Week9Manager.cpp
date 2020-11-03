#include "Week9Manager.h"

void Week9Manager::Main()
{
	WeekManagerBase::Main();

	cout << SumRecursion(10) << endl;
	cout << SumRecursion2(3) << endl;
}

int Week9Manager::SumRecursion(int num)
{
	return num == 1 ? 1 : num + SumRecursion(num - 1);
}

float Week9Manager::SumRecursion2(int num)
{
	return num == 1.f ? 1.f : 1.f / num + SumRecursion2(num - 1);
}