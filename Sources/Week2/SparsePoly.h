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
	void Read(char *str = "SparsePoly")
	{
		cout << endl;
		cout << str << "의 희소 다항식 항의 개수를 입력하시오: ";
		cin >> _nTerms;

		cout << "각 항의 계수를 입력하시오 (총 " << _nTerms << "개): ";
		for (int i = 0; i < _nTerms; i++)
			cin >> _term[i].coef;

		cout << "각 항의 지수를 입력하시오 (총 " << _nTerms << "개) : ";
		for (int i = 0; i < _nTerms; i++)
			cin >> _term[i].expon;

		// bubble sort by expon
		Sort();
	}

	void Display(char *str = "SparsePoly Display = ")
	{
		cout << endl;
		cout << str;

		// Show Sparse Poly
		for (int i = 0; i < _nTerms; i++)
		{
			if (_term[i].expon == 0)
				cout << _term[i].coef;
			else
				cout << _term[i].coef << " x^" << _term[i].expon;
			
			if (i != _nTerms - 1)
				cout << " + ";
		}
	}

	void Add(SparsePoly sp1, SparsePoly sp2)
	{
		*this = sp1;

		int incTermCount = 0;
		for (int i = 0; i < sp2._nTerms; i++)
		{
			bool isFindSameExpon = false;
			for (int j = 0; j < _nTerms; j++)
			{
				if (_term[j].expon == sp2._term[i].expon)
				{
					_term[j].coef += sp2._term[i].coef;
					isFindSameExpon = true;
					break;
				}
			}

			if (!isFindSameExpon)
			{
				_term[_nTerms + incTermCount] = sp2._term[i];
				incTermCount++;
			}
		}

		_nTerms += incTermCount;

		Sort();
	}

	void Sort()
	{
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
	}
};
