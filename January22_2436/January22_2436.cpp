
// January22_2436.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"searchAlgos.h"


void demoSearchingThrough2DStringArray()
{
	auto myRoomContents = initializeMyRoomContents();

	print2DArray(myRoomContents);

	string thing_to_search_for = "Bed";

	cout << thing_to_search_for << " was? found at row  = "
		<< search(myRoomContents, thing_to_search_for).first
		<< "and column = "
		<< search(myRoomContents, thing_to_search_for).second << "\n";
}



int main()
{
	//cout << RAND_MAX << "\n"; //a limitiation of rand() (a C function)

	//cout << "Time(nullptr) yields: " << time(nullptr) << "\n";

	auto oneThousandRandomNums = generateRandomNumbersBetwixt0AndN(1000);

	printOneDVector(oneThousandRandomNums); 
}

