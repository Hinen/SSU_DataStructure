#pragma once

#include "../WeekManagerBase.h"

class Week11Manager : public WeekManagerBase
{
public:
	Week11Manager() : WeekManagerBase(11) {}
	~Week11Manager() {}

public:
	virtual void Main() override;
};