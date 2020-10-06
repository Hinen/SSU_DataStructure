#pragma once

#include "../WeekManagerBase.h"
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
};