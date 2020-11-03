#include "stdafx.h"
#include "Manager.h"

int main()
{
	//auto manager = new Week1Manager();
	//auto manager = new Week2Manager();
	//auto manager = new Week3Manager();
	//auto manager = new Week5Manager();
	//auto manager = new Week6Manager();
	//auto manager = new Week8Manager();
	auto manager = new Week9Manager();

	manager->Main();

	delete manager;

	return 1;
}