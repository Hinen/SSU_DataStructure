#pragma once

#include "../../stdafx.h"
#include <string>

#define MAX_VTXS 256

class AdjMatGraph
{
public:
	AdjMatGraph()
	{
		Reset();
	}

	~AdjMatGraph() { }

protected:
	int	_vertexCount;
	char _verticeArr[MAX_VTXS];
	int _adjMat[MAX_VTXS][MAX_VTXS];

public:
	int GetVertexCount()
	{
		return _vertexCount;
	}

	char GetVertexName(int idx)
	{
		return _verticeArr[idx];
	}

	int GetVertexIdx(char name)
	{
		for (int i = 0; i < _vertexCount; i++)
		{
			if (_verticeArr[i] == name)
				return i;
		}
		
		return -1;
	}

	int	GetEdge(int i, int j)
	{
		return _adjMat[i][j];
	}

	void InsertVertex(char name)
	{
		if (IsFull())
		{
			cout << "Error : 그래프 정점의 최대 개수를 초과합니다." << endl;
			return;
		}

		_verticeArr[_vertexCount] = name;
		_vertexCount++;
	}

	void InsertEdge(int u, int v)
	{
		SetEdge(u, v, 1);
		SetEdge(v, u, 1);
	}

	void RemoveEdge(int u, int v)
	{
		SetEdge(u, v, 0);
		SetEdge(v, u, 0);
	}

	void Display(FILE *fp = stdout)
	{
		fprintf(fp, "%d\n", _vertexCount);

		for (int i = 0; i < _vertexCount; i++)
		{
			fprintf(fp, "%c  ", GetVertexName(i));

			for (int j = 0; j < _vertexCount; j++)
				fprintf(fp, " %3d", GetEdge(i, j));

			fprintf(fp,"\n");
		}
	}

	void Load(char *filename)
	{
		FILE *fp = fopen(filename, "r");
		if (fp != NULL)
		{
			int n;
			fscanf(fp, "%d", &n);

			for (int i = 0; i < n; i++)
			{
				char str[80];
				fscanf(fp, "%s", str);

				InsertVertex(str[0]);

				for(int j = 0; j < n; j++)
				{
					int val;
					fscanf(fp, "%d", &val);

					if (val != 0)
						InsertEdge(i, j);
				}
			}

			fclose(fp);
		}
	}

	void Store(char *filename)
	{
		FILE *fp = fopen(filename, "w");
		if (fp != NULL)
		{
			Display(fp);
			fclose(fp);
		}
	}

private:
	void Reset()
	{
		_vertexCount = 0;

		for (int i = 0; i < MAX_VTXS; i++)
		{
			for (int j = 0; j < MAX_VTXS; j++)
				SetEdge(i, j, 0);
		}
	}

	void SetEdge(int i, int j, int v)
	{
		_adjMat[i][j] = v;
	}

	bool IsFull()
	{
		return _vertexCount >= MAX_VTXS;
	}
};
