#include "stdafx.h"
#include "Manager.h"

int main()
{
	auto manager = new Week1Manager();

	manager->Main();

	delete manager;

	return 1;
}