// HW 4
// Yu Feng CS 1337
//Integer Number Generator

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int* random(int, int, int);

int main()
{
	int min, max, size;
	int* pointer = nullptr;

	//Ask for the boundaries and numbers needed:

	cout << "Welcome to the Random Number Generator" << endl;
	cout << "Please input the Minimum boundary of the random numbers (Integers Only): ";
	cin >> min;
	cout << "Please input the Maximum boundary of the random numbers (Integers Only): ";
	cin >> max;

	//Error checker in case of the minimum number input is greater the maximum number input
	while (min > max)
	{
		cout << "Your minimum number is greater than the maximum number. Please enter again." << endl;
		cout << "Minimum: ";
		cin >> min;
		cout << "Maximum: ";
		cin >> max;
	}

	cout << "How many numbers to generate? ";
	cin >> size;

	//Call the random number function, returning a pointer in which points to the array the generated numbers are stored 
	pointer = random(min, max, size);

	//Display the generated numbers
	cout << endl << "The numbers generated are: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << *(pointer + i) << "\t";
	}
	cout << endl << endl;

	//Release acquried memory back to heap
	delete[] pointer;

	system("pause");
	return 0;
}

int* random(int min, int max, int size)
{
	unsigned seed(0);
	srand(seed);

	int* numbers = nullptr;    // Define the pointer
	numbers = new int[size];   // Request Dynamic memory for storing random numbers gererated


	for (int index = 0; index < size; index++)
	{
		*(numbers + index) = (rand() % (max - min + 1)) + min;
	}
	return numbers;
}