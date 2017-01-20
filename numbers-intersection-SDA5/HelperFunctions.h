/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Stanislav Zmiycharov
* @idnumber 61883
* @task 4
* @compiler VC
*
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>
#include <cstdlib>
#include <string>
#include <cstdint>
#include <algorithm>
#include "LinearProbingHash.h"

void validateCmdParams(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <number>" << "\n";
		system("pause");
		exit(EXIT_FAILURE);
	}
}

void fileToArray(std::string fileName, uint64_t(&numbersFromFile)[10000], int &arrSize)
{
	std::fstream readFile;

	uint64_t num;

	readFile.open(fileName, std::ios_base::binary | std::ios_base::in);
	if (readFile.is_open())
	{
		while (readFile.read((char*)&num, sizeof(num)))
		{
			numbersFromFile[arrSize] = num;
			++arrSize;
		}
	}
	else
	{
		std::cerr << "Unable to open file " << fileName << "\n";
		exit(EXIT_FAILURE);
	}
}

void read(std::string fileName)
{
	std::fstream readFile;

	uint64_t num;

	readFile.open(fileName, std::ios_base::binary | std::ios_base::in);
	if (readFile.is_open())
	{
		std::cout << "HERE MALAKA: " << std::endl;
		while (readFile.read((char*)&num, sizeof(num)))
		{
			std::cout << num << " ";
		}
	}
	else
	{
		std::cerr << "Unable to open file " << fileName << "\n";
		exit(EXIT_FAILURE);
	}
}

void fileToHash(std::string fileName, uint64_t(&numbersFromFile)[10000], LinearProbingHash &hash)
{
	std::fstream readFile;

	uint64_t num;

	readFile.open(fileName, std::ios_base::binary | std::ios_base::in);
	if (readFile.is_open())
	{
		while (readFile.read((char*)&num, sizeof(num)))
		{
			hash.IncrementValue(num);
		}
	}
	else
	{
		std::cerr << "Unable to open file " << fileName << "\n";
		exit(EXIT_FAILURE);
	}
}

void splitStringToArray(const std::string &str, char delimeter, std::string(&arr)[3])
{
	std::stringstream ss;
	ss.str(str);
	std::string item;

	int i = 0;
	while (getline(ss, item, delimeter))
	{
		arr[i] = item;
		++i;
	}
}

void quickSort(int(&arr)[100], int left, int right)
{
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	while (i <= j)
	{
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;

		if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}

	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

int* getIntersection(int* arr1, int* arr2, int size1, int size2, int &hashSize)
{
	int i = 0, j = 0;
	int arr[100];

	while (i < size1 && j < size2)
	{
		if (arr1[i] == arr2[j])
		{
			arr[hashSize] = arr1[i];
			++hashSize;
			++i;
			++j;
		}
		else if (arr1[i] > arr2[j])
		{
			++j;
		}
		else
		{
			++i;
		}
	}
	return arr1;
}
