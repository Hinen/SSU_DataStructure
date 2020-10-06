#include "Week5Manager.h"

Week5Manager::Week5Manager() : WeekManagerBase(5)
{

}

Week5Manager::~Week5Manager()
{

}

void Week5Manager::Main()
{
	WeekManagerBase::Main();

	FibonacciNumbers();
}

void Week5Manager::FibonacciNumbers()
{
	int count = 0;

	cout << "피보나치 수열 항의 갯수를 입력하세요 : ";
	cin >> count;

	if (count <= 0)
	{
		cout << "항의 갯수는 0보다 커야합니다." << endl;
		return;
	}

	queue<int> queue;
	for (int i = 0; i < count; i++)
	{
		if (i < 2)
		{
			queue.push(1);
			cout << queue.back() << " ";

			continue;
		}

		int num1 = queue.front();
		int num2 = queue.back();

		queue.pop();

		queue.push(num1 + num2);
		cout << queue.back() << " ";
	}
}