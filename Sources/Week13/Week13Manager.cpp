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

	cout << "���� ��ķ� ǥ���� �׷���" << endl;
	ccGraph->Display();
	cout << endl;

	cout << "���� D���� ���� ���� �켱 Ž��" << endl;
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
				cout << "�ӽ÷� ����� ���� (" << g->GetVertexName(j) << " - " << g->GetVertexName(i) << ")" << endl;

				g->RemoveEdge(i, j);

				if (g->FindConnectedComponent() > 1)
				{
					cout << "Bridge " << count + 1 << " : " << g->GetVertexName(j) << " - " << g->GetVertexName(i) << endl;
					count++;
				}

				g->InsertEdge(i, j);

				cout << endl;
			}
		}
	}

	return count;
}