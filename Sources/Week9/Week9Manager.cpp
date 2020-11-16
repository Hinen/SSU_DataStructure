#include "Week9Manager.h"

void Week9Manager::Main()
{
	WeekManagerBase::Main();

	//cout << SumRecursion(10) << endl;
	//cout << SumRecursion2(3) << endl;

	FiboRecursionCountMain(5);

	char* a = "asdf";
	char* b = StrReverseRecursion(a);
	cout << a << endl << b << endl;
}

int Week9Manager::SumRecursion(int num)
{
	return num == 1 ? 1 : num + SumRecursion(num - 1);
}

float Week9Manager::SumRecursion2(int num)
{
	return num == 1.f ? 1.f : 1.f / num + SumRecursion2(num - 1);
}

void Week9Manager::FiboRecursionCountMain(int n)
{
	int* countArr = new int[n];
	for (int i = 0; i < n; i++)
		countArr[i] = 0;

	int fibo = FiboRecursionCount(countArr, n);
	for (int i = n; i > 0; i--)
		cout << "Fibo(" << i << ") = " << countArr[i - 1] << "번" << endl;

	cout << "피보나치 수열 결과 값 : " << fibo << endl;

	delete countArr;
}

int Week9Manager::FiboRecursionCount(int* countArr, int n)
{
	countArr[n - 1]++;
	
	// 1, 2번째 피보나치는 순환으로 값을 가져오는 것이 아닌, 정해진 수인 0과 1을 return
	if (n <= 2)
		return n - 1;

	return FiboRecursionCount(countArr, n - 2) + FiboRecursionCount(countArr, n - 1);
}

char* Week9Manager::StrReverseRecursion(char* str)
{
	int len = strlen(str);

	if (len == 1)
	{
		char* str2 = new char[0];
		strcpy(str2, str);
		return str2;
	}
	else
	{
		char* str2 = new char[len];
		strcpy(str2, str + 1);

		char* newStr = StrReverseRecursion(str2);
		delete str2;

		return strncat(newStr, str, 1);
	}
}
