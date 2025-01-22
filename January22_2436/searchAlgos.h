#pragma once

#include <iostream>

#include<array> //static array 
//
//#include<pair>

using std::array, std::cout, std::string, std::pair;

array<array<string, 4>, 4> initializeMyRoomContents(); //function declaration here (def. will be in the cpp file)

//template<typename T1, typename T2> //an alternative to std::pair
//struct myPair
//{
//	T1 first; 
//	T2 second; 
//
//};

/*template<typename T>*/ 
void print2DArray(array<array<string, 4>, 4> twoDArray);

pair<int, int> search(array<array<string, 4>, 4>, const string& thingWeSearchFor);