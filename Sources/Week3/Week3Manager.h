#pragma once

#include "../WeekManagerBase.h"
#include "Location2D.h"
#include <stack>

class Week3Manager : public WeekManagerBase
{
public:
	Week3Manager();
	~Week3Manager();

public:
	virtual void Main() override;

private:
	void MazeSearch();
	bool IsValidLocation(int r, int c);
};