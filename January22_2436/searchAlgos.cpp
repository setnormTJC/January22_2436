#include"searchAlgos.h"

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

pair<int, int> search(array<array<string, 4>, 4> twoDArray, const string& thingWeSearchFor)
{
    pair<int, int> position = { -1, -1 }; // Initialize with -1, -1 to indicate not found

    for (int i = 0; i < twoDArray.size(); ++i)
    {
        for (int j = 0; j < twoDArray[i].size(); ++j)
        {
            if (twoDArray[i][j] == thingWeSearchFor)
            {
                position = { i, j };
                return position;
            }
        }
    }

    return position; // Return -1, -1 if not found
}
