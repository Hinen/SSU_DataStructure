#pragma once
#include "../stdafx.h"

#define MAX_TERMS 50

struct Term {
	int	expon;
	float coeff;
};

class SparsePoly
{
public:
	SparsePoly()
	{
		_nTerms = 0;
	}

private:
	int	_nTerms;
	Term _term[MAX_TERMS];

public:
	void Read()
	{

	}

	void Display()
	{

	}

	void Add()
	{

	}
};
