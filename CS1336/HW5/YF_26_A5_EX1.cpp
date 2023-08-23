//Programmer: Yu Feng
//Gradebook number: 26
//Assignment 5 Exercise 1: A Hexadecimal to binary converter. It inputs the hexadecimal number, converts to binary code, and prints the resulting output on the screen.

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main ()
{
    string input, output, result;
    char extract;
    int letter_count;
    bool error = false;

    cout << "Enter a value in hexadecimal: ";
    getline(cin, input);

    for (letter_count = 0; letter_count < input.length() && error == false; ++letter_count)
    {
        extract = input.at(letter_count);

        if (extract > 'F')
        {
            switch (extract)
           {
                case 'a':
                    extract = 'A';
                    break;
                case 'b':
                    extract = 'B';
                    break;
                case 'c':
                    extract = 'C';
                    break;
                case 'd':
                    extract = 'D';
                    break;
                case 'e':
                    extract = 'E';
                    break;
                case 'f':
                    extract = 'F';
                    break;
                default:
                    cout << endl << "Error " << input << " is not a valid hexadecimal value.";
                    error = true;
           }
        }
        switch (extract)
        {
            case '0':
                output = "0000";
                break;
            case '1':
                output = "0001";
                break;
            case '2':
                output = "0010";
                break;
            case '3':
                output = "0011";
                break;
            case '4':
                output = "0100";
                break;
            case '5':
                output = "0101";
                break;
            case '6':
                output = "0110";
                break;
            case '7':
                output = "0111";
                break;
            case '8':
                output = "1000";
                break;
            case '9':
                output = "1001";
                break;
            case 'A':
                output = "1010";
                break;
            case 'B':
                output = "1011";
                break;
            case 'C':
                output = "1100";
                break;
            case 'D':
                output = "1101";
                break;
            case 'E':
                output = "1110";
                break;
            case 'F':
                output = "1111";
                break;
        }
        result += " " + output;
    }
    if (error == false)
    {
        cout << endl << "The equivalent binary value is: " << endl;
        cout << setw(7 + result.length()) << result;
    }
    return 0;
}
