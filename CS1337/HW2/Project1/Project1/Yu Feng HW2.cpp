// CS 1337 HW 2
// Yu Feng
// Conversion of numbers in string literal format to actual numbers and to the binary string.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Max numbers the input document may have

const int max_element = 100;

int ConvertToNumbers(string);
string ConvertBinary(int);

int main()
{
	string holder;  //holder is used to store information pulled out directly from the file.
	ifstream Filein;
	ofstream Fileout;
	int numbers[max_element];
	int counter, total;

	Filein.open("numbers.txt");
	for (counter = 0; Filein >> holder; counter++)
	{
        total = ConvertToNumbers(holder);
		numbers[counter] = total;
	}
	Filein.close();

	Fileout.open("binary.txt");
	for (int i = 0; i < counter; i++)
	{
	    string binary_output;
		binary_output = ConvertBinary(numbers[i]);
		Fileout << binary_output << endl;
	}
	Fileout.close();

	cout << "Conversion to binary string has finished. Press any key to continue..." << endl;
	cin.ignore();
	return 0;
}

//Function to convert string back to numbers
int ConvertToNumbers(string holder)
{
    // total is a variable to store the actual number from the file after being pulled out separately in digits.

    int total = 0, input_number;

    // character variable "temp" is used to store numbers extracted from the string "holder" temporarily

    char temp;
    for (int i = 0; i < holder.length(); i++)
    {
        total *= 10;
        temp = holder.at(i);
        switch (temp)
        {
            case '1':
                input_number = 1;
                break;
            case '2':
                input_number = 2;
                break;
            case '3':
                input_number = 3;
                break;
            case '4':
                input_number = 4;
                break;
            case '5':
                input_number = 5;
                break;
            case '6':
                input_number = 6;
                break;
            case '7':
                input_number = 7;
                break;
            case '8':
                input_number = 8;
                break;
            case '9':
                input_number = 9;
                break;
            case '0':
                input_number = 0;
                break;
        }
        total += input_number;
    }
    return total;
}

//Function to convert number to binary string
string ConvertBinary(int result)
{
    string binary_output;

    //Binary string converter

    do
    {
        if (result % 2 == 0)
            binary_output = "0" + binary_output;
        else
            binary_output = "1" + binary_output;

        result /= 2;

    } while (result != 0);
    return binary_output;

}
