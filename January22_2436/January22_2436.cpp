
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



}

