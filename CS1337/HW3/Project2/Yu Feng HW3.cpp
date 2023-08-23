//HW 3
//Yu Feng
//Binary Search after selection sort
//The searching function of the programme is case sensitive.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void selection_sort(string [], int);
int binary_search(string[], int, string);

const int Array_size = 100; // Maximum element size is 100.
int main()
{
	int subs, location;
	ifstream Filein;
	string names[Array_size];
	string hold, target;
	Filein.open("names.txt");
	for (subs = 0; getline(Filein, hold); subs++)
	{
		names[subs] = hold;
	}
	Filein.close();
	selection_sort(names, subs);
	cout << endl << endl << "Please enter the targeted name <Case Sensitive>: ";

	getline(cin, target); // user input

	location = binary_search(names, subs, target);


	if (location != -1)
	{
		cout << endl << "The item is at subscript " << location << " of the array." << endl;
	}
	else
	{
		cout << endl << location;
		cout << endl << "The item you're looking for couldn't be found." << endl;
	}
	cout << "The programme is finished. Press any key to exit.";
	cin.ignore();
	return 0;
}


void selection_sort(string data[], int subs)
{
	int startScan, minIndex;
	string minValue;
	for (startScan = 0; startScan < subs; startScan++)
	{
		minIndex = startScan;   //
		minValue = data[startScan];
		for (int index = startScan + 1; index < subs; index++)
		{
			if (data[index] < minValue)
			{
				minValue = data[index];
				minIndex = index;
			}
		}
		data[minIndex] = data[startScan];
		data[startScan] = minValue;
	}
	cout << "Here are the sorted names:" << endl;
	for (int counter = 0; counter < subs; counter++)
	{
		string output;
		output = data[counter];
		cout << output << "  ";
	}
	return;
}

int binary_search(string data[], int subs, string target)
{
	int index_start = 0;
	int index_end = subs;
	int middle;
	do
	{
		middle = (index_end + index_start) / 2;
		if (data[middle] == target)
		{
			return middle; // item Found!
		}

		// item Not Found
		if (data[middle] < target)
		{
			index_start = middle + 1;
		}
		else
		{
			index_end = middle - 1;
		}
	} while (index_start <= index_end);
	return -1; // Item not found in the whold array indicator
}
