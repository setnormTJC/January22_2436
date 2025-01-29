
#include"searchAlgos.h"

 
/*This method WRITES TO A CSV output file (opening up in spreadsheet software enables plotting a TRENDLINE)
and finding O(N) time complexity of algorithm
*/
void demoSequentialSearchAlgoAnalysis()
{
	vector<int> elementCounts = { 10, 100, 1'000, 10'000, 100'000, (int)1E6 };

	const char* filename = "fancyData.csv";

	ofstream fout{ filename/*, std::ios::app*/ };

	for (const auto& elementCount : elementCounts)
	{
		long long timeSequentialSearchTookForNElements = getSequentialSearchTimeForNElements(elementCount);

		//cout << "For N = " << elementCount << ", it took " << timeSequentialSearchTookForNElements << " nanoseconds\n";

		fout << elementCount << "," << timeSequentialSearchTookForNElements << "\n";
	}

	fout.close();

	system(filename);
}

void demoSimpleBinarySearch()
{
	vector<int> oneThroughTen;
	for (int i = 0; i < 10; ++i)
	{
		oneThroughTen.push_back(i);
	}

	//oneThroughTen.at(1) = 123333; //{0, 1234444, 2, 3, 4, 5}

	cout << std::boolalpha;
	int recursiveCallCount = 0;
	int targetValue = 4;
	cout << recursiveBinarySearch(oneThroughTen, targetValue, 0, oneThroughTen.size() - 1, recursiveCallCount);

}

void demoBinarySearchAlgoAnalysis()
{
	vector<int> binarySearchArraySizes =
	{
		(int)pow(2, 3), //8
		(int)pow(2, 4), //16
		(int)pow(2, 5), //32
		(int)pow(2, 6), //etc.
		(int)pow(2, 7),
	};


	for (int currentArraySize : binarySearchArraySizes)
	{
		vector<int> vecN; 

		for (int i = 1; i <= currentArraySize; ++i)
		{
			vecN.push_back(i); //ex: for arraySize = 8, this array will be {1, 2, 3, ...8}
		}

		//now "force" a worst case scenario - pick a number outside of the array's range: 
		int targetValue = currentArraySize * 100; 
		
		int recursiveCallCount = 0; //track the number of calls -> for ALGORITHM ANALYSIS
		recursiveBinarySearch(vecN, targetValue, 0, vecN.size() - 1, recursiveCallCount);
	}
}


int main()
{
	//demoSequentialSearchOnNElements(10); 
	//demoSequentialSearchOnNElements(100);
	//demoSequentialSearchOnNElements(1'000);

	//demoSequentialSearchAlgoAnalysis(); 

	//demoSimpleBinarySearch()

	demoBinarySearchAlgoAnalysis(); 


}

