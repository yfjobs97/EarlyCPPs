//Programmer: Yu Feng
//Gradebook number: 26
/*Assignment 6 Exercise 1: a program that reads a file containing information on properties for rent around a local
                           university and displays the name and rental price followed by the average of the rental prices,
                           the highest price for a rental and the lowest price for a rental on the computer screen. */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    ifstream input;
    ofstream output;
    string file_name, content;
    char characters;
    double numbers = 0, result, multiplier, total_length = 0;
    double highest = 0, price_total, lowest = 99999, runtime = 0, average;
    int firstrun = 0;

    //Welcome Screen

    cout << "Enter the name of the file that contains the list of properties." << endl;
    cout << setprecision(2) << fixed;
    getline(cin, file_name);

    //Open File

    input.open(file_name);

    while (input.fail() == true)
    {
        cout << "Error: File not found." << endl;
        cout << "Enter the name of the file that contains the list of properties." << endl;
        getline (cin, file_name);
        input.open(file_name);
    }



    for (firstrun = 1; input >> content; firstrun++)
    {

        if (firstrun == 1)
        {
            cout << endl << endl << "Property Name" << "\t\t\t\t\t" << setw(12) << "Price" << endl << endl;
        }

        if (content.at(0) > '9')
        {
            cout << content << " ";

            //total_length to save the length of each name of property

            total_length += content.length();
        }
        else
        {
            multiplier = pow (10, (content.length() - 1));
            result = 0;

            // runtime reflects the amount of properties listed in the file

            runtime++;

            for (int counter = 0; counter < content.length(); counter++)
            {
                // characters variable saves extracted values from the string.

                characters = content.at(counter);
                switch (characters)
                {
                    case '1':
                        numbers = 1;
                        break;
                    case '2':
                        numbers = 2;
                        break;
                    case '3':
                        numbers = 3;
                        break;
                    case '4':
                        numbers = 4;
                        break;
                    case '5':
                        numbers = 5;
                        break;
                    case '6':
                        numbers = 6;
                        break;
                    case '7':
                        numbers = 7;
                        break;
                    case '8':
                        numbers = 8;
                        break;
                    case '9':
                        numbers = 9;
                        break;
                    case '0':
                        numbers = 0;
                        break;
                }

                result += numbers * multiplier;
                multiplier /= 10;
            }

            price_total += result;
            average = price_total / runtime;

            if (result > highest)
            {
                highest = result;
            }

            if (result < lowest)
            {
                lowest = result;
            }

            if (total_length < 14)
            {
                cout << "\t";
            }
            total_length = 0;
            cout << "\t\t\t\t" << "$    " << result << endl ;
        }
    }

    input.close();

    if (firstrun > 1)
    {
        cout << endl << endl << setw(50) << "Average Price = \t$    " << average << endl;
        cout << setw (50) << "Highest Price = \t$    " << highest << endl;
        cout << setw (50) << "Lowest Price = \t$    " << lowest << endl;
    }
    else
    {
        cout << endl << "This is an empty file." << endl;
    }


    return 0;
}
