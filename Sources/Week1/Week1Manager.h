#pragma once

#include "../WeekManagerBase.h"

class Week1Manager : public WeekManagerBase
{
public:
	Week1Manager();
	~Week1Manager();

public:
	virtual void Main() override;

private:
	void TimeComplexityTest1(int n);
	void TimeComplexityTest2(int n);
	void TimeComplexityTest3(int n);
};