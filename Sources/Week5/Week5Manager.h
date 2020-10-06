#pragma once

#include "../WeekManagerBase.h"
#include "../Week3/Location2D.h"
#include "../Week3/MazeMap.h"
#include <queue>

class Week5Manager : public WeekManagerBase
{
public:
	Week5Manager();
	~Week5Manager();

public:
	virtual void Main() override;

private:
	void FibonacciNumbers();
	void MazeSearch();
	bool IsValidLocation(int r, int c);
};