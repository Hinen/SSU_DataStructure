#include "Week2Manager.h"

Week2Manager::Week2Manager() : WeekManagerBase(2)
{

}

Week2Manager::~Week2Manager()
{

}

void Week2Manager::Main()
{
	WeekManagerBase::Main();

	PolynomialTest1();
}

void Week2Manager::PolynomialTest1()
{
	Polynomial p1, p2, p3;

	p1.Read();
	p2.Read();
	p3.Add(p1, p2);
	
	p1.Display("p1 = ");
	p2.Display("p2 = ");
	p3.Display("p3(p1 + p2) = ");
}