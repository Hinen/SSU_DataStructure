#include "Week6Manager.h"

Week6Manager::Week6Manager() : WeekManagerBase(6)
{

}

Week6Manager::~Week6Manager()
{

}

void Week6Manager::Main()
{
	WeekManagerBase::Main();

	VariableArr2D();
}

void Week6Manager::VariableArr2D()
{
	int** arr2D;
	int rowSize, columnSize;

	cout << "행과 열의 크기를 입력하세요.";
	cin >> rowSize >> columnSize;

	arr2D = AllocateArr2D(rowSize, columnSize);
	if (arr2D == NULL)
	{
		cout << "행과 열의 크기를 바르게 입력하지 않았습니다." << endl;
		return;
	}
	
	SetRandomDataArr2D(arr2D, rowSize, columnSize);
	PrintAllArr2D(arr2D, rowSize, columnSize);
	DeleteArr2D(arr2D, rowSize);
}

int** Week6Manager::AllocateArr2D(int rowSize, int columnSize)
{
	if (rowSize <= 0 || columnSize <= 0)
		return NULL;

	int** arr2D = new int*[rowSize];
	for (int i = 0; i < rowSize; i++)
		arr2D[i] = new int[columnSize];

	return arr2D;
}

void Week6Manager::SetRandomDataArr2D(int** arr2D, int rowSize, int columnSize)
{
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < columnSize; j++)
		{
			arr2D[i][j] = rand() % 100;
		}
	}
}

void Week6Manager::PrintAllArr2D(int** arr2D, int rowSize, int columnSize)
{
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < columnSize; j++)
		{
			cout << "arr2D[" << i << "][" << j << "] = " << arr2D[i][j] << endl;
		}
	}
}

void Week6Manager::DeleteArr2D(int** arr2D, int rowSize)
{
	for (int i = 0; i < rowSize; i++)
	{
		delete[] arr2D[i];
	}

	delete[] arr2D;
}