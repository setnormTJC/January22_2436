
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




int main()
{
	//demoSequentialSearchOnNElements(10); 
	//demoSequentialSearchOnNElements(100);
	//demoSequentialSearchOnNElements(1'000);

	//demoSequentialSearchAlgoAnalysis(); 

	//demoBinarySearch()

	vector<int> binarySearchArraySizes =
	{
		(int)pow(2, 3),
		(int)pow(2, 4),
		(int)pow(2, 5),
		(int)pow(2, 6),
		(int)pow(2, 7),
	};

	vector<int> oneThroughTen;
	for (int i = 0; i < 10; ++i)
	{
		oneThroughTen.push_back(i); 
	}

	//oneThroughTen.at(1) = 123333; //{0, 1234444, 2, 3, 4, 5}

	cout << std::boolalpha; 
	int recursiveCallCount = 0; 
	int targetValue = 4; 
	cout << recursiveBinarySearch(oneThroughTen, targetValue , 0, oneThroughTen.size() - 1, recursiveCallCount);


}

