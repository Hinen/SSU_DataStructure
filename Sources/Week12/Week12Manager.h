#pragma once

#include "../WeekManagerBase.h"

class Week12Manager : public WeekManagerBase
{
public:
	Week12Manager() : WeekManagerBase(12) {}
	~Week12Manager() {}

public:
	virtual void Main() override;
};