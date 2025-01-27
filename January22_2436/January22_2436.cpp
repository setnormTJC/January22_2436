
// January22_2436.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"searchAlgos.h"
#include<chrono>

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


void demoMeasuringExecutionTime()
{
	auto start = std::chrono::high_resolution_clock::now(); 
	//chrono is Latin/Greek and means "related to time" 
	//how long (in NANOSECONDS) does it take for my program to count to one billion? 
	for (int i = 0; i < 1'000'000'000; ++i)
	{
		//nothin'
	}
	auto end = std::chrono::high_resolution_clock::now();

	cout.imbue(std::locale(""));
	//puts a comma every three digits for nums >> 1 (on my machine)

	cout << "It took this much time: " << (end - start).count() << "\n";
}


int main()
{

	demoMeasuringExecutionTime(); 

	std::cin.get();//similar to system("pause")


	//cout << RAND_MAX << "\n"; //a limitiation of rand() (a C function)

	//cout << "Time(nullptr) yields: " << time(nullptr) << "\n";


	constexpr int N1 = 1'000; 
	//const? 
	constexpr int N2 = 10'000;
	auto oneThousandRandomNums = generateRandomNumbersBetwixt0AndN(N1);
	//auto tenThousandRandomNums = generateRandomNumbersBetwixt0AndN(N2); 



	//search(oneThousandRandomNums, someNumberBetween0AndOneThousand);


	printOneDVector(oneThousandRandomNums); 


}

