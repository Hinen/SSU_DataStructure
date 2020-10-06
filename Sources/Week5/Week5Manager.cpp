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

	cout << "�Ǻ���ġ ���� ���� ������ �Է��ϼ��� : ";
	cin >> count;

	if (count <= 0)
	{
		cout << "���� ������ 0���� Ŀ���մϴ�." << endl;
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