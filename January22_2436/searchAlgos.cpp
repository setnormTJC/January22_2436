#include"searchAlgos.h"
#include <cassert>

vector<int> generateRandomNumbersBetwixt0AndN(int N)
{

    mt19937 rng(time(nullptr));


    uniform_int_distribution<int> distribution{ 0, N };

    vector<int> randomNumbersBetwixt0AndN;

    for (int i = 0; i < N; ++i)
    {
        randomNumbersBetwixt0AndN.push_back(distribution(rng)); 
    }

    return randomNumbersBetwixt0AndN;
}

void printOneDVector(const vector<int>& oneDVector)
{
    for (auto& num : oneDVector)
    {
        cout << num << " "; 
    }
    cout << "\n";
}

array<array<string, 4>, 4> initializeMyRoomContents()
{
	array<array<string, 4>, 4> myRoom = 
    {{
        {"Bed", "Desk", "Chair", "Lamp"},
        {"Bookshelf", "Wardrobe", "Mirror", "Rug"},
        {"Window", "Curtains", "Plant", "Clock"},
        {"Laptop", "Notebook", "Pen", "Backpack"}
    }};

    return myRoom; 
}

void print2DArray(array<array<string, 4>, 4> twoDArray)
{
	for (const auto& row : twoDArray)
	{
		for (const auto& element : row)
		{
			cout << element << "\t";
		}
		cout << "\n"; //puts a newline between each row of myRoom (or whatever 2D array we're dealing with) 
	}
}


/*Complexity (~the number of operations) is BigO(N)*/
pair<int, int> search(array<array<string, 4>, 4> twoDArray, const string& thingWeSearchFor)
{
    unsigned int comparisonCount = 0; 

    pair<int, int> position = { -1, -1 }; // Initialize with -1, -1 to indicate not found

    for (int i = 0; i < twoDArray.size(); ++i)
    {
        for (int j = 0; j < twoDArray[i].size(); ++j)
        {
            comparisonCount++; 

            if (twoDArray[i][j] == thingWeSearchFor)
            {
                position = { i, j };

                cout << "Number of comparisons performed: " << comparisonCount << "\n";
                return position;
            }
        }
    }

    cout << "Number of comparisons performed: " << comparisonCount << "\n";
    return position; // Return -1, -1 if not found
}


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

/*CSV stands for "comma-separated values/variables"*/
void demoWritingToACSVFile()
{
	ofstream fout{ "out.csv" };

	fout << 1 << "," << 3 << "\n";
	fout << 2 << "," << 6 << "\n";
	fout << 3 << "," << 9 << "\n";
	fout << 4 << "," << 12 << "\n";
	fout << 5 << "," << 15 << "\n";


	//cout 
	fout.close();
}

//void callSequentialSearchOnNElement

void demoSequentialSearchOnNElements(const int N)
{
	//constexpr int N1 = 100;
	//const? 
	//constexpr int N2 = 10'000;
	auto NRandomNumbers = generateRandomNumbersBetwixt0AndN(N);
	//auto tenThousandRandomNums = generateRandomNumbersBetwixt0AndN(N2); 

	std::random_device rd; //better alternative to passing in time(nullptr) to rng
	mt19937 rng(rd()); //there is a bit of a subtle problem here ... 
	uniform_int_distribution<int> distribution{ 0, N };

	int theRandomNumber = distribution(rng);
	cout << "Looking for this random number: " << theRandomNumber << "\n";

	std::cin.get();
	printOneDVector(NRandomNumbers);

	if (sequentialSearch(NRandomNumbers, theRandomNumber))
	{
		cout << "it was found\n";
	}

	else
	{
		cout << "Not found\n";
	}

	std::cin.get();
}

long long getSequentialSearchTimeForNElements(int N)
{
	auto vecN = generateRandomNumbersBetwixt0AndN(N);// vecN means a vector of N elements


	std::random_device rd; //better alternative to passing in time(nullptr) to rng
	mt19937 rng(rd()); //there is a bit of a subtle problem here ... 
	uniform_int_distribution<int> distribution{ 0, N };

	int theRandomNumber = distribution(rng);
	

	auto start = std::chrono::high_resolution_clock::now(); 

	sequentialSearch(vecN, theRandomNumber);

	auto end = std::chrono::high_resolution_clock::now();


	return (end - start).count(); 
}

bool recursiveBinarySearch(vector<int> SORTEDnums, int targetNumber, int startIndex, int endIndex, int& counter)
{
	assert(std::is_sorted(SORTEDnums.begin(), SORTEDnums.end()));


	++counter; 

	if (startIndex > endIndex)
	{
		return false; //means `targetNumber` is not in `nums`
	}
	
	int middleIndex = floor((startIndex + endIndex) / 2);

	if (SORTEDnums[middleIndex] == targetNumber)
	{
		cout << targetNumber << " was found in the array: \n";
		printOneDVector(SORTEDnums);
		cout << "\nAnd the number of recursive calls ended up being = " << counter << "\n";


		return true; 
	}

	else if (SORTEDnums[middleIndex] > targetNumber)
	{
		
		recursiveBinarySearch(SORTEDnums, targetNumber, startIndex, middleIndex - 1, counter);

	}

	else //middle index value < targetNumber
	{
		recursiveBinarySearch(SORTEDnums, targetNumber, middleIndex + 1, endIndex, counter);
	}

}
