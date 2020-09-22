#include "Week3Manager.h"

Week3Manager::Week3Manager() : WeekManagerBase(3)
{

}

Week3Manager::~Week3Manager()
{

}

void Week3Manager::Main()
{
	WeekManagerBase::Main();

	MazeSearch();
}

const int mazeSize = 6;
char map[mazeSize][mazeSize] = {
	{ '1', '1', '1', '1', '1', '1' },
	{ 'e', '0', '1', '0', '0', '1' },
	{ '1', '0', '0', '0', '1', '1' },
	{ '1', '0', '1', '0', '1', '1' },
	{ '1', '0', '1', '0', '0', 'x' },
	{ '1', '1', '1', '1', '1', '1' },
};

void Week3Manager::MazeSearch()
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

	stack<Location2D> locStack;
	locStack.push(Location2D(startPosX, startPosY));

	bool isSuccessFindExit = false;
	while (locStack.empty() == false)
	{
		Location2D here = locStack.top();

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
			bool canGo = false;

			if (IsValidLocation(r - 1, c))
			{
				locStack.push(Location2D(r - 1, c));
				canGo = true;
			}
			else if (IsValidLocation(r + 1, c))
			{
				locStack.push(Location2D(r + 1, c));
				canGo = true;
			}
			else if (IsValidLocation(r, c - 1))
			{
				locStack.push(Location2D(r, c - 1));
				canGo = true;
			}
			else if (IsValidLocation(r, c + 1))
			{
				locStack.push(Location2D(r, c + 1));
				canGo = true;
			}

			map[r][c] = '.';

			if (!canGo)
				locStack.pop();
		}
	}

	cout << "미로 탐색 " << (isSuccessFindExit ? "성공!" : "실패..") << endl;
}

bool Week3Manager::IsValidLocation(int r, int c)
{
	if (r < 0 || c < 0 || r >= mazeSize || c >= mazeSize)
		return false;
	else
		return map[r][c] == '0' || map[r][c] == 'x';
}