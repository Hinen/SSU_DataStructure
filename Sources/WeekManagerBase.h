#pragma once

#include "stdafx.h"

class WeekManagerBase
{
public:
	WeekManagerBase(int week);
	~WeekManagerBase();

	virtual void Main();

private:
	int _week;
};