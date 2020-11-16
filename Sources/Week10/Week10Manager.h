#pragma once

#include "../WeekManagerBase.h"

class Week10Manager : public WeekManagerBase
{
public:
	Week10Manager() : WeekManagerBase(10) {}
	~Week10Manager() {}

public:
	virtual void Main() override;
};