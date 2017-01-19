#include <iostream>

#include "LinearProbingHash.h"

LinearProbingHash::LinearProbingHash(size_t MaxSize)
{
	ElementsCount = 0;

	BufferSize = MaxSize;

	pBuffer = new bucket[BufferSize];

	// Mark all positions as empty
	for (size_t i = 0; i < BufferSize; i++)
	{
		pBuffer[i].id = -1;
		pBuffer[i].value = -1;
	}
}

LinearProbingHash::~LinearProbingHash()
{
	delete[] pBuffer;
}

bool LinearProbingHash::Add(const int ID, const int Value)
{
	if (ElementsCount >= BufferSize)
		return false;

	int i = CalculateHash(ID);

	while (pBuffer[i].id >= 0)
	{
		i = (i + 1) % BufferSize;
	}

	pBuffer[i].id = ID;
	pBuffer[i].value = Value;

	ElementsCount++;

	return true;
}

bool LinearProbingHash::IncrementValue(const int ID)
{
	int i = CalculateHash(ID);

	while (pBuffer[i].id >= 0)
	{
		if (pBuffer[i].id == ID)
		{
			++pBuffer[i].value;
			return true;
		}
		else
			i = (i + 1) % BufferSize;
	}

	return false;
}

int LinearProbingHash::GetValue(const int ID)
{
	int i = CalculateHash(ID);

	while (pBuffer[i].id >= 0)
	{
		if (pBuffer[i].id == ID)
			return pBuffer[i].value;
		else
			i = (i + 1) % BufferSize;
	}

	return INT_MIN_VALUE;
}

int LinearProbingHash::CalculateHash(const int ID)
{
	return ID % BufferSize;
}
