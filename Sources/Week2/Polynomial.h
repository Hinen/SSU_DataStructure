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
		cout << "다항식의 최고 차수를 입력하시오: ";
		cin >> _degree;

		cout << "각 항의 계수를 입력하시오 (총 " << _degree + 1 << "개): ";
		for (int i = 0; i <= _degree; i++)
			cin >> _coef[i];
	}

	void Display(char *str = " Poly = ")
	{
		cout << "\t" << str;

		for (int i = 0; i < _degree; i++)
			cout << _coef[i] << " x^" << _degree - i << " + ";

		cout << _coef[_degree] << endl;
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
		for (int i = 0; i <= _degree; i++)
			_coef[i] = -_coef[i];
	}
};
