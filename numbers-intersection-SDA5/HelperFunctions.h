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

void validateCmdParams(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <number>" << "\n";
		system("pause");
		exit(EXIT_FAILURE);
	}
}

void readFromFile(std::string fileName, uint64_t(&numbersFromFile)[10000], int &arrSize)
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
			std::cout << num << std::endl;
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
