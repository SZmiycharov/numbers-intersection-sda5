/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Stanislav Zmiycharov
* @idnumber 61883
* @task 5
* @compiler VC
*
*/

#include "HelperFunctions.h"
#include "LinearProbingHash.h"

using namespace std;

int main(int argc, char* argv[])
{
	validateCmdParams(argc, argv);

	int numberFiles = 0;
	int arrSize = 0;
	string fileName;
	uint64_t numbersFromFile[10000];

	assert(istringstream(argv[1]) >> numberFiles);

	getline(cin, fileName);
	fileToArray(fileName, numbersFromFile, arrSize);

	LinearProbingHash hash(arrSize + 1);

	for (int i = 0; i < arrSize; i++)
	{
		hash.Add(numbersFromFile[i], 1);
	}

	for (int i = 1; i < numberFiles; i++)
	{
		getline(cin, fileName);
		fileToHash(fileName, numbersFromFile, hash);
	}

	int currentValue = 0;
	std::fstream writeFile;
	char* resultFile = "result.bin";

	writeFile.open(resultFile, std::fstream::binary | std::ios_base::app);
	if (!writeFile.is_open())
	{
		std::cerr << "Unable to open file " << resultFile << "\n";
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < arrSize; i++)
	{
		currentValue = hash.GetValue(numbersFromFile[i]);
		if (currentValue == numberFiles)
		{
			writeFile.write((char*)&numbersFromFile[i], sizeof(numbersFromFile[i]));
		}
	}
	writeFile.close();

	system("pause");
	return 0;
}

