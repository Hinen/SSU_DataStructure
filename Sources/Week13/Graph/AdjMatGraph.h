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
	int	_size;
	char _verticeArr[MAX_VTXS];
	int _adjMat[MAX_VTXS][MAX_VTXS];

public:
	int GetSize()
	{
		return _size;
	}

	char GetVertexName(int idx)
	{
		return _verticeArr[idx];
	}

	int	GetEdge(int i, int j)
	{
		return _adjMat[i][j];
	}

	void SetEdge(int i, int j, int v)
	{
		_adjMat[i][j] = v;
	}

	bool IsEmpty()
	{
		return _size == 0;
	}

	bool IsFull()
	{
		return _size >= MAX_VTXS;
	}

	void Reset()
	{
		_size=0;

		for (int i = 0; i < MAX_VTXS; i++)
		{
			for (int j = 0; j < MAX_VTXS; j++)
				SetEdge(i, j, 0);
		}
	}

	void InsertVertex(char name)
	{
		if (IsFull())
		{
			cout << "Error : 그래프 정점의 최대 개수를 초과합니다." << endl;
			return;
		}

		_verticeArr[_size] = name;
		_size++;
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
		fprintf(fp, "%d\n", _size);

		for (int i = 0; i < _size; i++)
		{
			fprintf(fp, "%c  ", GetVertexName(i));

			for (int j = 0; j < _size; j++)
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
};
