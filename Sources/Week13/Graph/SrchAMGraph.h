#pragma once

#include "AdjMatGraph.h"

class SrchAMGraph : public AdjMatGraph
{
protected:
	bool _visitedArr[MAX_VTXS];

public:
	void ResetVisited()
	{
		for (int i = 0; i < _size; i++)
			_visitedArr[i] = false;
	}

	bool IsLinked(int u, int v)
	{
		return GetEdge(u, v) != 0;
	}

	void DepthFirstSearch(int v)
	{
		_visitedArr[v] = true;
		cout << GetVertexName(v) << " ";

		for (int u = 0; u < _size; u++)
		{
			if (IsLinked(v, u) && _visitedArr[u] == false)
				DepthFirstSearch(u);
		}
	}
};
