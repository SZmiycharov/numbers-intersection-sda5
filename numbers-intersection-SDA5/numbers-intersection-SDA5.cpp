/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Stanislav Zmiycharov
* @idnumber 61883
* @task 3
* @compiler VC
*
*/

#include "HelperFunctions.h"
#include "LinearProbingHash.h"

using namespace std;

int main(int argc, char* argv[])
{
	validateCmdParams(argc, argv);

	LinearProbingHash hash(10007);

	int numberFiles = 0;
	int arrSize = 0;
	string fileName;
	uint64_t numbersFromFile[10000];

	assert(istringstream(argv[1]) >> numberFiles);

	getline(cin, fileName);
	fileToArray(fileName, numbersFromFile, arrSize);

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
	writeFile.open("result.bin", std::fstream::binary | std::fstream::app);
	if (!writeFile.is_open())
	{
		std::cerr << "Unable to open file " << "result.bin" << "\n";
		exit(EXIT_FAILURE);
	}

	cout << "beginning of last cycle: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		currentValue = hash.GetValue(numbersFromFile[i]);
		if (currentValue == numberFiles)
		{
			uint64_t o = numbersFromFile[i];
			writeFile.write((char*)&o, sizeof(o));
			cout << " " << numbersFromFile[i] << " " << "sizeofnum: " << sizeof(numbersFromFile[i]);
		}
	}
	cout << endl;
	writeFile.close();

	read("result.bin");

	system("pause");
	return 0;



	/*cout << "adding 1 5" << endl;
	hash.Add(1, 5);
	cout << hash.GetValue(1) << endl;
	hash.IncrementValue(1);
	cout << hash.GetValue(1) << endl;
	hash.IncrementValue(1);
	cout << hash.GetValue(1) << endl;
	hash.IncrementValue(1);
	cout << hash.GetValue(1) << endl;

	cout << "adding 2 1" << endl;
	hash.Add(2, 1);
	cout << hash.GetValue(2) << endl;
	hash.IncrementValue(2);
	cout << hash.GetValue(2) << endl;
	
	cout << "adding 123 1" << endl;
	hash.Add(123, 1);
	cout << hash.GetValue(123) << endl;
	hash.IncrementValue(123);
	cout << hash.GetValue(123) << endl;

	cout << "adding 289 1" << endl;
	hash.Add(289, 1);
	cout << hash.GetValue(289) << endl;
	hash.IncrementValue(289);
	cout << hash.GetValue(289) << endl;

	cout << "addin 12378 1" << endl;
	hash.Add(12378, 1);
	cout << hash.GetValue(12378) << endl;
	hash.IncrementValue(12378);
	cout << hash.GetValue(12378) << endl;
	
	cout << "addin 100 1" << endl;
	hash.Add(100, 1);
	cout << hash.GetValue(100) << endl;
	hash.IncrementValue(100);
	cout << hash.GetValue(100) << endl;

	cout << "adding 666 1" << endl;
	hash.Add(666, 1);
	cout << hash.GetValue(666) << endl;
	hash.IncrementValue(666);
	cout << hash.GetValue(666) << endl;*/

	/*cout << "1 value before change: " << hash.GetValue(1) << endl;
	hash.IncrementValue(1);
	cout << "1 value after change: " << hash.GetValue(1) << endl;

	system("pause");
	return 0;*/




	/*char* fileName = "D:\\Users\\Desktop\\1.txt";
	char* fileNamå2 = "D:\\Users\\Desktop\\2.txt";
	char* fileNamå3 = "D:\\Users\\Desktop\\3.txt";
	int allFilesNumber = 3;

	char* filenames[100];

	filenames[0] = fileName;
	filenames[1] = fileNamå2;
	filenames[2] = fileNamå3;

	ifstream file(fileName);

	int number = 0;	
	int size1 = 0;
	int size2 = 0;
	int numbersFromFirstFile[100];
	int numbfirstfilesize = 0;

	cout << "putting numbers with 1: " << endl;
	while (file >> number)
	{
		cout << number << " ";
		hash.Add(number, 1);
		numbersFromFirstFile[numbfirstfilesize] = number;
		numbfirstfilesize++;
	}
	cout << endl;

	for (int i = 1; i < allFilesNumber; ++i)
	{
		ifstream file(filenames[i]);
		cout << "for filename: " << filenames[i] << endl;
		while (file >> number)
		{
			cout << number << " value:" << hash.GetValue(number) << endl;
			if (hash.GetValue(number) > INT_MIN_VALUE)
			{
				hash.IncrementValue(number);
			}
			cout << number << " afterchange:" << hash.GetValue(number) << "\n\n";
		}
	}

	cout << "\n**************INTERSECTION**************: " << endl;
	for (int i = 0; i < numbfirstfilesize; ++i)
	{
		if (hash.GetValue(numbersFromFirstFile[i]) == allFilesNumber)
		{
			cout << numbersFromFirstFile[i] << " ";
		}
	}
	cout << endl;*/

	system("pause");
	return 0;
}

