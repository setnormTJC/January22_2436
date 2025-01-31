#pragma once

#include<array> //static array 
#include<chrono>
#include<fstream>
#include <iostream>

#include"random"


using std::mt19937; //this is a prime number and MT means "Mersenne Twister" 
using std::uniform_int_distribution;
using std::ofstream;


using std::array, std::cout, std::string, std::pair, std::vector;


vector<int> generateRandomNumbersBetwixt0AndN(int N);

void printOneDVector(const vector<int>& oneDVector);

array<array<string, 4>, 4> initializeMyRoomContents(); //function declaration here (def. will be in the cpp file)


/*template<typename T>*/ 
void print2DArray(array<array<string, 4>, 4> twoDArray);

pair<int, int> search(array<array<string, 4>, 4>, const string& thingWeSearchFor);


/*
@return false if valueToSearchFor is not found and true otherwise
*/
template<typename T>
bool sequentialSearch(const vector<T>& list, T valueToSearchFor)
{
	for (const auto& listElement : list) //range-based for loop 
	{
		if (listElement == valueToSearchFor)
		{
			return true; 
		}
	}

	//not found: 
	return false; 
}

void demoMeasuringExecutionTime();

void demoWritingToACSVFile();

void demoSequentialSearchOnNElements(const int N);

long long getSequentialSearchTimeForNElements(int N);

bool recursiveBinarySearch(vector<int> nums, int targetNumber, int startIndex, int endIndex, int& counter);