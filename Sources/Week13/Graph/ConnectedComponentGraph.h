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

		for (int u = 0; u < _vertexCount; u++)
		{
			if (IsLinked(v, u) && _visitedArr[u] == false)
				DepthFirstSearch(u, color);
		}
	}

	int FindConnectedComponent()
	{
		ResetVisited();

		int count = 0;

		for (int i = 0; i < _vertexCount; i++)
		{
			if (_visitedArr[i] == false)
			{
				count++;
				DepthFirstSearch(i, count);
			}
		}
		
		cout << "그래프 연결 성분 개수 = " << count << endl;

		for (int i = 0; i < _vertexCount; i++)
		{
			cout << GetVertexName(i) << " Color = " << _vertexColorArr[i];
			
			if (i != _vertexCount - 1)
				cout << ", ";
		}

		cout << endl;

		return count;
	}
};
