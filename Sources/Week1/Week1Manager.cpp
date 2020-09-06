#include "Week1Manager.h"

Week1Manager::Week1Manager() : WeekManagerBase(1)
{

}

Week1Manager::~Week1Manager()
{

}

void Week1Manager::Main()
{
	WeekManagerBase::Main();

	TimeComplexityTest1(3);
	TimeComplexityTest2(3);
	TimeComplexityTest3(3);
}

void Week1Manager::TimeComplexityTest1(int n)
{
	cout << "\nStart Time Complexity Test1" << endl;
	cout << "n : " << n << endl;
	int calcCount = 0;

	int sum = n * n;
	calcCount += 2; // µ¡¼À, ´ëÀÔ ÃÑ 2¹ø

	cout << "Result Sum : " << sum << endl;
	cout << "Calc Count : " << calcCount << endl;
	cout << "Expected Count : " << 2 << endl;
}

void Week1Manager::TimeComplexityTest2(int n)
{
	cout << "\nStart Time Complexity Test2" << endl;
	cout << "n : " << n << endl;
	int calcCount = 0;

	int sum = 0;
	calcCount++;

	for (int i = 0; i < n; i++)
	{
		sum += n;
		calcCount += 2; // µ¡¼À, ´ëÀÔ ÃÑ 2¹ø
	}

	cout << "Result Sum : " << sum << endl;
	cout << "Calc Count : " << calcCount << endl;
	cout << "Expected Count : " << 2 * n + 1 << endl;
}

void Week1Manager::TimeComplexityTest3(int n)
{
	cout << "\nStart Time Complexity Test3" << endl;
	cout << "n : " << n << endl;
	int calcCount = 0;

	int sum = 0;
	calcCount++;

	for (int i = 0; i < n; i++)
	{
		for (int j= 0; j < n; j++) 
		{
			sum += 1;
			calcCount += 2; // µ¡¼À, ´ëÀÔ ÃÑ 2¹ø
		}
	}

	cout << "Result Sum : " << sum << endl;
	cout << "Calc Count : " << calcCount << endl;
	cout << "Expected Count : " << 2 * (n * n) + 1 << endl;
}