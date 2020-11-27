#pragma once

#include "SrchAMGraph.h"

class ConnectedComponentGraph : public SrchAMGraph
{
private:
	int _vertexColorArr[MAX_VTXS];

public:
	void DepthFirstSearch(int v, int color)
	{
		_visitedArr[v] = true;
		_vertexColorArr[v] = color;

		for (int u = 0; u < _size; u++)
		{
			if (IsLinked(v, u) && _visitedArr[u] == false)
				DepthFirstSearch(u, color);
		}
	}

	int FindConnectedComponent()
	{
		int count = 0;

		for (int i = 0; i < _size; i++)
		{
			if (_visitedArr[i] == false)
			{
				count++;
				DepthFirstSearch(i, count);
			}
		}
		
		cout << "그래프 연결 성분 개수 = " << count << endl;

		for (int i = 0; i < _size; i++)
		{
			cout << GetVertexName(i) << " = " << _vertexColorArr[i];
			
			if (i != _size - 1)
				cout << ", ";
		}

		cout << endl << endl;

		return count;
	}
};
