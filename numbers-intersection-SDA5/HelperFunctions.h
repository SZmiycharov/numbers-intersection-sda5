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
#include <algorithm>

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
