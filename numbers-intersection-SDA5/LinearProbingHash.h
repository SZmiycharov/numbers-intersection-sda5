#pragma once

#include <limits>
#include <cstdint>

const int INT_MIN_VALUE = std::numeric_limits<int>::min();
const int INT_MAX_VALUE = std::numeric_limits<int>::max();
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

	bool Add(const uint64_t ID, const int Value);
	bool IncrementValue(const uint64_t ID);
	uint64_t GetValue(const uint64_t ID);

private:
	int CalculateHash(uint64_t ID);
	
	struct bucket
	{
		uint64_t id;
		uint64_t value;
		bucket() : id(0), value(0) {};
	};

	size_t BufferSize;
	size_t ElementsCount;
	bucket* pBuffer;
	ModularHashingFunction* pHashingFunction;
};