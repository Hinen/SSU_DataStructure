#include "stdafx.h"
#include "Manager.h"

int main()
{
	//auto manager = new Week1Manager();
	//auto manager = new Week2Manager();
	//auto manager = new Week3Manager();
	auto manager = new Week5Manager();

	manager->Main();

	delete manager;

	return 1;
}