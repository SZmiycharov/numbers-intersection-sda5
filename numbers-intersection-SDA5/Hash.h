//#pragma once
//
//#include <iostream>
//
/////
///// A hashing function, which tries not to cluster the hash values
/////
///// The hash for a specific value V is calculated as (V % Mod) * Multiplier
/////
//
//
//
/////
/////	Parent class for all hashes
/////
//class Hash
//{
//public:
//	Hash(ModAndMultiplyHashingFunction* pHashingFunction = 0)
//	{
//		this->pHashingFunction = pHashingFunction;
//	}
//
//	virtual ~Hash()
//	{
//	}
//
//	virtual bool Add(const int Value) = 0;
//
//	virtual bool Search(const int Value) = 0;
//
//	virtual void PrintInfo() const = 0;
//protected:
//	ModAndMultiplyHashingFunction* pHashingFunction;
//};