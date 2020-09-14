#pragma once
#include "../stdafx.h"

#define MAX_DEGREE 80

class Polynomial
{
public:
	Polynomial() 
	{ 
		_degree = 0;
	}

private:
	int _degree;
	float _coef[MAX_DEGREE];

public:
	void Read()
	{
		printf("다항식의 최고 차수를 입력하시오: ");
		scanf("%d", &_degree);

		printf("각 항의 계수를 입력하시오 (총 %d개): ", _degree + 1);
		for (int i = 0; i <= _degree; i++)
			scanf("%f", _coef + i);
	}

	void Display(char *str = " Poly = ")
	{
		printf("\t%s", str);

		for (int i = 0; i < _degree; i++)
			printf("%5.1f x^%d + ", _coef[i], _degree - i);

		printf("%4.1f\n", _coef[_degree]);
	}

	void Add(Polynomial a, Polynomial b)
	{
		if (a._degree > b._degree)
		{
			*this = a;
			for (int i = 0; i <= b._degree; i++)
				_coef[i + (_degree - b._degree)] += b._coef[i];
		}
		else
		{
			*this = b;
			for (int i = 0; i <= a._degree; i++)
				_coef[i + (_degree - a._degree)] += a._coef[i];
		}
	}

	bool IsZero()
	{
		return _degree == 0;
	}

	void Negate()
	{
		// TODO
	}
};
