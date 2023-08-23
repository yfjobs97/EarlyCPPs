// HW 5
// Yu Feng CS 1337
//Encrypter / Decrypter: A programme that has 2 modes of operation: Encryption or Decryption. The user will be asked to select the mode of the operation of the programme.
//The programme assumes the user knows the input restrictions of the characters, such as the amount of elements allowed, and the only characters that are accepted.

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <string>
using namespace std;

//Function Headers
void eMode(char[],int);
void dMode(char[], int);
void up_to_low(char[], int);
int indexFinder(char[], char[], int*);
void encrypt(int*, int, int, int, int);
void decrypt(int*, int, int*, int, int, int);
void DisplayEcrypted(int* indexes, char alphabet[], int size);

const int SIZE = 100; // The largest input size is: 100 elements
int main()
{
	int mode;

	//Encrypt key
	char alphabet[] = " abcdefghijklmnopqrstuvwxyz.?,";

	//Welcome screen & Prompt
	cout << "Welcome to the Encrypter/Decrpter" << endl;
	cout << "Please select the mode of operation:" << endl;
	cout << "1.Encrypt \n2.Decrypt" << endl;
	cin >> mode;

	//Error check for the mode selector
	while (mode < 1 || mode > 2)
	{
		cout << "Error. Mode not Found!" << endl;
		cout << "Please select the mode of operation:" << endl;
		cout << "1.Encrypt \n2.Decrypt" << endl;
		cin >> mode;
	}

	//Directing the user to the corresponding mode
	if (mode == 1)
	{
		eMode(alphabet, strlen(alphabet));
	}
	else
	{
		dMode(alphabet, strlen(alphabet));
	}

	cout << endl << endl;
	system("pause");
	return 0;
}


//A Function that change all capital letters to lower case letters.
void up_to_low(char input[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		input[i] = tolower(input[i]);
	}
	return;
}

//Core Function for Encryption
void eMode(char alphabet [], int alphaSize)
{
	int shift = 0, inc = 0, stopVal;
	char message[SIZE] = { ' ' };
	ifstream input;
	string filename;

	//Ask for the name of the file input
	cout << "Enter the filename where the message was stored: " << endl;
	cout << "Warning: Only " << SIZE << " characters are allowed in the message!" << endl;
	cin.ignore();
	getline(cin, filename);

	input.open(filename);

	//Getting data from the file
	input.getline(message, SIZE);
	input.close();


	cout << "Enter the shifting of the indexes: ";
	cin >> shift;
	cout << "Enter the increment per letter position: ";
	cin >> inc;

	up_to_low(message, SIZE);
	int* indexes = new int[SIZE]; //The Encrypted index with respect to the encrypted key is stored

	//Use the the function to match the input string with the subscript of the encryption key
	//Returning the index where null terminator is located.
	stopVal = indexFinder(message, alphabet, indexes);

	//Encryption started
	encrypt(indexes, alphaSize, stopVal, shift, inc);

	//Display the encrypted message and store in the file.
	cout << "Your encrypted message is: " << endl;
	DisplayEcrypted(indexes, alphabet, stopVal);
	cout << endl << "Your message was also stored in the file Encrypted message.txt" << endl;

	delete[] indexes;

	return;
}


//A Function that match the input message to the subscript of the encryption key.
//Returning the location of the null terminator
int indexFinder(char input[], char alphabet[], int* indexes)
{
	int i = 0; //Index count for the input
	for (i = 0; input[i] != '\0'; i++)
	{
		int p = -1; //Index count in the encryption key
		do
		{
			p++;
			if (input[i] == alphabet[p])
			{
				*(indexes + i) = p;
			}

		} while (input[i] != alphabet[p]);
	}

	return i; //Returning the position of the null terminator
}

// Process the encryption
void encrypt(int* indexes, int alphaSize, int stopVal, int shift, int inc)
{


	for (int i = 0; i < stopVal; i++)
	{
		int value;
		value = *(indexes + i) + shift + i * inc;

		//Wrapping the value from 0 to the maximum size of the encrytion key
		while (value >= alphaSize)
		{
			value -= alphaSize;
		}

		*(indexes + i) = value;
	}
	return;
}

//A function for displaying the result of ecryption
void DisplayEcrypted(int* indexes, char alphabet[], int size)
{
	ofstream output;
	output.open("Encrypted message.txt");
	output << "Your encrypted message is: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << alphabet[*(indexes + i)];
		output << alphabet[*(indexes + i)];
	}
	output.close();
	return;
}

// Core Function for Decryption
void dMode(char alphabet[], int alphaSize)
{
	int shift = 0, inc = 0, stopVal;
	ifstream input;
	ofstream output;
	string filename;
	output.open("Decrypted Possibilities.txt");

	//Ask for the name of the file input
	cout << "Enter the filename where the message was stored: " << endl;
	cout << "Warning: Only " << SIZE << " characters are allowed in the message!" << endl;
	cin.ignore();
	getline(cin, filename);

	input.open(filename);
	char message[SIZE] = { ' ' };

	input.getline(message, SIZE);
	input.close();

	//Ask for the possible increment for decryption
	cout << "Input the possible increment per letter position: ";
	cin >> inc;

	int* indexes = new int[SIZE]; //The index with respect to the encrypted key is stored
	int* new_indexes = new int[SIZE];//The Encrypted index of each possible shifts with respect to the encrypted key is stored

	//Use the the function to match the input string with the subscript of the encryption key
	//Returning the index where null terminator is located.
	stopVal = indexFinder(message, alphabet, indexes);

	//Writing all the decryption possibilities of the message to the file
	for (shift = 0; shift < alphaSize; shift++)
	{

		output << endl << "For shift " << shift << " with an decrement of " << inc << ", the message is: " << endl;
		decrypt(indexes, alphaSize, new_indexes, stopVal, shift, inc);

		for (int i = 0; i < stopVal; i++)
		{
			output << alphabet[*(new_indexes + i)];
		}

		output << "\n";


	}

	cout << "Check the Decrypted Possibilities.txt file to check possible results." << endl;

	output.close();
	delete[] indexes;
	delete[] new_indexes;
	return;
}

//Process the Decryption and display the end result
void decrypt(int* indexes, int alphaSize, int* new_indexes, int stopVal, int shift, int inc)
{
	for (int i = 0; i < stopVal; i++)
	{
		int value;
		value = *(indexes + i);
		value = value - shift - i * inc;

		//Wrapping the value from 0 to the maximum size of the encrytion key
		while (value < 0)
			value += alphaSize;

		*(new_indexes + i) = value;
	}
	return;
}




