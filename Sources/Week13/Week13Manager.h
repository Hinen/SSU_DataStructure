#pragma once

#include "../WeekManagerBase.h"
#include "Graph\ConnectedComponentGraph.h"

class Week13Manager : public WeekManagerBase
{
public:
	Week13Manager() : WeekManagerBase(13) {}
	~Week13Manager() {}

public:
	virtual void Main() override;

private:
	void GraphTest();
	int FindBridge(ConnectedComponentGraph* g);
};