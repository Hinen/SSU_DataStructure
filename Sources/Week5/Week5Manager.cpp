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

	//FibonacciNumbers();
	MazeSearch();
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

void Week5Manager::MazeSearch()
{
	int startPosX = -1;
	int startPosY = -1;

	for (int i = 0; i < mazeSize; i++)
	{
		for (int j = 0; j < mazeSize; j++)
		{
			if (map[i][j] == 'e')
			{
				startPosX = i;
				startPosY = j;
			}
		}
	}

	if (startPosX == -1 || startPosY == -1)
	{
		cout << "map�� ���� ��ġ(e)�� �������� �ʽ��ϴ�." << endl;
		return;
	}

	queue<Location2D> locQueue;
	locQueue.push(Location2D(startPosX, startPosY));

	bool isSuccessFindExit = false;
	while (locQueue.empty() == false)
	{
		Location2D here = locQueue.front();
		locQueue.pop();

		int r = here.row;
		int c = here.col;

		cout << "(" << r << "," << c << ")" << endl;

		if (map[r][c] == 'x')
		{
			isSuccessFindExit = true;
			break;
		}
		else
		{
			if (IsValidLocation(r - 1, c))
				locQueue.push(Location2D(r - 1, c));

			if (IsValidLocation(r + 1, c))
				locQueue.push(Location2D(r + 1, c));

			if (IsValidLocation(r, c - 1))
				locQueue.push(Location2D(r, c - 1));

			if (IsValidLocation(r, c + 1))
				locQueue.push(Location2D(r, c + 1));

			map[r][c] = '.';
		}
	}

	cout << "�̷� Ž�� " << (isSuccessFindExit ? "����!" : "����.. (�� �̷δ� �ⱸ�� �������� �ʽ��ϴ�.)") << endl;
}

bool Week5Manager::IsValidLocation(int r, int c)
{
	if (r < 0 || c < 0 || r >= mazeSize || c >= mazeSize)
		return false;
	else
		return map[r][c] == '0' || map[r][c] == 'x';
}