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
			cout << arr1[i] << " HA: ";
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

int main(int argc, char* argv[])
{
	validateCmdParams(argc, argv);

	LinearProbingHash hash(10007);

	cout << "argv 1: " << argv[1] << endl;

	int numberFiles = 0;
	string fileName;
	int arrSize = 0;
	uint64_t numbersFromFile[10000];

	assert(istringstream(argv[1]) >> numberFiles);

	for (int i = 0; i < numberFiles; i++)
	{
		getline(cin, fileName);
		cout << "file: " << fileName << endl;
		readFromFile(fileName, numbersFromFile, arrSize);

		for (int j = 0; j < arrSize; j++)
		{
			hash.Add(1, 5);
		}
	}

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

