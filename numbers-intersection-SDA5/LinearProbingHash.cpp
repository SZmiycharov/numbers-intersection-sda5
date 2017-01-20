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

bool LinearProbingHash::Add(const uint64_t ID, const int Value)
{
	if (ElementsCount >= BufferSize)
		return false;

	int i = CalculateHash(ID);

	while (pBuffer[i].id <= INT_MAX_VALUE)
	{
		std::cout << pBuffer[i].id << " ";
		std::cout << INT_MAX_VALUE << " ";
		i = (i + 1) % BufferSize;
	}

	pBuffer[i].id = ID;
	pBuffer[i].value = Value;

	ElementsCount++;

	return true;
}

bool LinearProbingHash::IncrementValue(const uint64_t ID)
{
	int i = CalculateHash(ID);

	while (pBuffer[i].id <= INT_MAX_VALUE)
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

uint64_t LinearProbingHash::GetValue(const uint64_t ID)
{
	int i = CalculateHash(ID);

	while (pBuffer[i].id <= INT_MAX_VALUE)
	{
		if (pBuffer[i].id == ID)
			return pBuffer[i].value;
		else
			i = (i + 1) % BufferSize;
	}

	return INT_MIN_VALUE;
}

int LinearProbingHash::CalculateHash(const uint64_t ID)
{
	return ID % BufferSize;
}
