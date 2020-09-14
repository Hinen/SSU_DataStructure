#pragma once

#include "stdafx.h"

class WeekManagerBase
{
public:
	WeekManagerBase(int week);
	~WeekManagerBase();

	virtual void Main();

	int a;

private:
	int _week;
};