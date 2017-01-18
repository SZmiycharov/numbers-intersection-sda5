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
#include "Hash.h"

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

int* getIntersection(int* arr1, int* arr2, int size1, int size2, int &testSize)
{
	int i = 0, j = 0;
	int arr[100];

	while (i < size1 && j < size2)
	{
		if (arr1[i] == arr2[j])
		{
			cout << arr1[i] << " HA: ";
			arr[testSize] = arr1[i];
			++testSize;
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
	char* fileName = "D:\\Users\\Desktop\\1.txt";
	char* fileNamå2 = "D:\\Users\\Desktop\\2.txt";
	/*char* fileNamå3 = "D:\\Users\\Desktop\\3.txt";*/

	char* filenames[100];

	filenames[0] = fileName;
	filenames[1] = fileNamå2;
	/*filenames[2] = fileNamå3;*/

	ifstream file(fileName);
	ifstream file2(fileNamå2);

	int arr1[100];
	int arr2[100];

	int number = 0;	
	int size1 = 0;
	int size2 = 0;

	struct MyKeyHash {
		unsigned long operator()(const int& k) const
		{
			return k % 10;
		}
	};

	HashMap<int, int, MyKeyHash> hmap;

	cout << "putting numbers with 0: " << endl;
	while (file >> number)
	{
		cout << number << " ";
		hmap.put(number, 0);
	}
	cout << endl;

	int zero = 0;
	int one = 1;

	int numbersFromFirstFile[100];
	int numbfirstfilesize = 0;

	ifstream file222(filenames[0]);
	while (file222 >> number)
	{
		numbersFromFirstFile[numbfirstfilesize] = number;
		numbfirstfilesize++;
	}

	int filenamessize = 2;
	//entries in hash: 1 12020 5 1238 10923 161283761
	for (int i = 1; i < filenamessize; ++i)
	{
		ifstream file(filenames[i]);
		cout << "for filename: " << filenames[i] << endl;
		while (file >> number)
		{
			cout << number << " " << hmap.get(number, zero) << endl;
			if (hmap.get(number, zero))
			{
				hmap.remove(number);
				hmap.put(number, one);
			}
		}
	}

	for (int i = 0; i < numbfirstfilesize; ++i)
	{
		cout << hmap.get(numbersFromFirstFile[i], one);
		cout << hmap.get(numbersFromFirstFile[i], zero);
		cout << endl;
	}



	for (int i = 0; i < numbfirstfilesize; ++i)
	{
		if (hmap.get(numbersFromFirstFile[i], one))
		{
			cout << numbersFromFirstFile[i] << " ";
		}
	}
	cout << endl;


	cout << "INTERSECTION: " << endl;
	for (int i = 0; i < numbfirstfilesize; ++i)
	{
		if (hmap.get(numbersFromFirstFile[i], one))
		{
			cout << numbersFromFirstFile[i] << " ";
		}
	}
	cout << endl;


	

	system("pause");
	return 0;
}

