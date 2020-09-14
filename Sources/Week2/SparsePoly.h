#pragma once
#include "../stdafx.h"

#define MAX_TERMS 50

struct Term {
	int	expon;
	float coef;
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
		printf("희소 다항식 항의 개수를 입력하시오: ");
		scanf("%d", &_nTerms);

		printf("각 항의 계수를 입력하시오 (총 %d개): ", _nTerms);
		for (int i = 0; i < _nTerms; i++)
			scanf("%f", &_term[i].coef);

		printf("각 항의 지수를 입력하시오 (총 %d개): ", _nTerms);
		for (int i = 0; i < _nTerms; i++)
			scanf("%d", &_term[i].expon);
	}

	void Display(char *str = "SparsePoly Display")
	{
		printf("%s\n", str);

		// Show All
		for (int i = 0; i < _nTerms; i++)
		{
			if (_term[i].expon == 0)
				printf("\t%5.1f\n", _term[i].coef);
			else
				printf("\t%5.1f x^%d\n", _term[i].coef, _term[i].expon);
		}

		// bubble sort by expon
		for (int i = 0; i < _nTerms - 1; i++)
		{
			for (int j = i + 1; j < _nTerms; j++)
			{
				if (_term[i].expon < _term[j].expon)
				{
					Term temp = _term[i];
					_term[i] = _term[j];
					_term[j] = temp;
				}
			}
		}

		// Show Sparse Poly
		for (int i = 0; i < _nTerms; i++)
		{
			if (i == 0)
				printf("\tSparse Poly : ");

			if (_term[i].expon == 0)
				printf("%5.1f", _term[i].coef);
			else
				printf("%5.1f x^%d", _term[i].coef, _term[i].expon);
			
			if (i != _nTerms - 1)
				printf(" + ");
		}
	}

	void Add()
	{

	}
};
