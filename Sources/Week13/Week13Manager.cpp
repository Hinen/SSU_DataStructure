#include "Week13Manager.h"

void Week13Manager::Main()
{
	WeekManagerBase::Main();

	GraphTest();
}

void Week13Manager::GraphTest()
{
	ConnectedComponentGraph* ccGraph = new ConnectedComponentGraph();

	for (int i = 0; i < 4; i++)
		ccGraph->InsertVertex('A' + i);

	ccGraph->InsertEdge(0, 1);
	ccGraph->InsertEdge(0, 2);
	ccGraph->InsertEdge(1, 2);
	ccGraph->InsertEdge(2, 3);

	cout << "인접 행렬로 표현한 그래프" << endl;
	ccGraph->Display();
	cout << endl;

	cout << "정점 D에서 부터 깊이 우선 탐색" << endl;
	ccGraph->SrchAMGraph::DepthFirstSearch(ccGraph->GetVertexIdx('D'));
	cout << endl << endl;

	FindBridge(ccGraph);

	delete ccGraph;
}

int Week13Manager::FindBridge(ConnectedComponentGraph* g)
{
	int count = 0;
	g->ResetVisited();

	for (int i = 0; i < g->GetVertexCount(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (g->GetEdge(i, j) != 0)
			{
				g->RemoveEdge(i, j);
				g->ResetVisited();

				if (g->FindConnectedComponent() > 1)
				{
					cout << "Bridge " << count + 1 << " : " << g->GetVertexName(i) << " - " << g->GetVertexName(j) << endl;
					count++;
				}

				g->InsertEdge(i, j);
			}
		}
	}

	return count;
}