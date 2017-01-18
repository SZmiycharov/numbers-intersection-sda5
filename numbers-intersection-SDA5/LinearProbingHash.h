#pragma once

#include <limits>
const int INT_MIN_VALUE = std::numeric_limits<int>::min();
const int multiplier = 2654435761;

class ModularHashingFunction
{
public:
	ModularHashingFunction(int Mod)
	{
		this->Mod = Mod;
	}

private:
	int Mod;
};

class LinearProbingHash
{
public:
	LinearProbingHash(size_t MaxSize);
	~LinearProbingHash();

	bool Add(const int ID, const int Value);
	bool IncrementValue(const int ID);
	int GetValue(const int ID);

private:
	int CalculateHash(int ID);
	
	struct bucket
	{
		int id;
		int value;
		bucket() : id(0), value(0) {};
	};

	size_t BufferSize;
	size_t ElementsCount;
	bucket* pBuffer;
	ModularHashingFunction* pHashingFunction;
};