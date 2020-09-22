#pragma once

struct Location2D
{
public:
	Location2D(int r = 0, int c = 0)
	{
		row = r;
		col = c;
	}

public:
	int row;
	int col;

public:
	// 아래의 함수들은 PPT 예시에서는 정의는 해놓았지만
	// 실제로 미로 탐색 구현에서는 사용하지 않는 함수들이기에 주석 처리
	/*
	bool IsNeighbor(Location2D &p)
	{
		return (row == p.row && (col == p.col - 1 || col == p.col + 1))
			|| (col == p.col && (row == p.row - 1 || row == p.row + 1));
	}

	bool operator==(Location2D &p)
	{
		return row == p.row && col == p.col;
	}
	*/
};
