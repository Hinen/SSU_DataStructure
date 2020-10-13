#pragma once

#include "../WeekManagerBase.h"
#include "LinkedStack\LinkedStack.h"
#include "LinkedQueue\LinkedQueue.h"

class Week6Manager : public WeekManagerBase
{
public:
	Week6Manager();
	~Week6Manager();

public:
	virtual void Main() override;

private:
	void VariableArr2D();
	int** AllocateArr2D(int rowSize, int columnSize);
	void SetRandomDataArr2D(int** arr2D, int rowSize, int columnSize);
	void PrintAllArr2D(int** arr2D, int rowSize, int columnSize);
	void DeleteArr2D(int** arr2D, int rowSize);

	void LinkedStackTest();
	void LinkedQueueTest();
};