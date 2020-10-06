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
		cout << "map에 시작 위치(e)가 찍혀있지 않습니다." << endl;
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

	cout << "미로 탐색 " << (isSuccessFindExit ? "성공!" : "실패.. (이 미로는 출구가 존재하지 않습니다.)") << endl;
}

bool Week5Manager::IsValidLocation(int r, int c)
{
	if (r < 0 || c < 0 || r >= mazeSize || c >= mazeSize)
		return false;
	else
		return map[r][c] == '0' || map[r][c] == 'x';
}