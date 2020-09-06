#include "WeekManagerBase.h"

WeekManagerBase::WeekManagerBase(int week)
{
	_week = week;
	std::cout << "Initializing Week" << _week << "Manager...\n" << std::endl;
}

WeekManagerBase::~WeekManagerBase()
{
	std::cout << "\nTerminating Week" << _week << "Manager..." << std::endl;
}

void WeekManagerBase::Main()
{
	std::cout << "Week " << _week << " Main Start\n" << std::endl;
}