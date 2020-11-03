#pragma once

#include "../WeekManagerBase.h"

class Week9Manager : public WeekManagerBase
{
public:
	Week9Manager() : WeekManagerBase(9) {}
	~Week9Manager() {}

public:
	virtual void Main() override;

private:
	int SumRecursion(int num);
	float SumRecursion2(int num);
};