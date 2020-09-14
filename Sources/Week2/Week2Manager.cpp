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
	if (p1.IsZero())
		printf("\tp1 is zero!\n");

	p2.Display("p2 = ");
	if (p2.IsZero())
		printf("\tp2 is zero!\n");

	p3.Display("p3(p1 + p2) = ");

	printf("\n");

	p1.Negate();
	p1.Display("p1(Negate) = ");

	p2.Negate();
	p2.Display("p2(Negate) = ");
}