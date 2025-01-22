
// January22_2436.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"searchAlgos.h"


int main()
{
	auto myRoomContents = initializeMyRoomContents();

	print2DArray(myRoomContents); 

	string thing_to_search_for = "Backpack";

	cout << thing_to_search_for << " was? found at row  = "
		<< search(myRoomContents, thing_to_search_for).first
		<< "and column = "
		<< search(myRoomContents, thing_to_search_for).second << "\n";
}

