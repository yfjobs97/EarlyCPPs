//Programmer: Yu Feng
//Gradebook number: 26
//Assignment 4 EX 1: Converting numerical date to dates shown on legal documents. It asks for the numerical date and convert into Legal Document Date, then print the result.

#include <iostream>
#include <string>
using namespace std;

int main ()
{
    int month_value, day_value, year;
    string month, day_suffix; // month = month in words, day_suffix is the st, nd, th after the day.

    cout << "Enter the date (mm/dd/yyyy)" << endl;
    cin >> month_value;
    cin.ignore ();
    cin >> day_value;
    cin.ignore ();
    cin >> year;
    cin.ignore ();

    // Take out obvious unreasonable numbers out of the range

    if (year < 0 || day_value < 1 || day_value > 31 || month_value < 1 || month_value > 12)
    {
        cout << endl << "Invalid date Entered." << endl;
        {
            if (month_value < 1 || month_value > 12)
            {
                cout << "Month must be between 1 and 12 inclusive." << endl;
            }
            if (day_value < 1 || day_value > 31)
            {
                cout << "Day not valid." << endl;
            }
            if (year < 0)
            {
                cout << "Year must be greater than 0." << endl;
            }
        }
    }
    else
    {
        switch (month_value) // Switching numeric month to its corresponding word
        {
            case 1 :
                month = "January";
                break;
            case 2 :
                month = "February";
                break;
            case 3 :
                month = "March";
                break;
            case 4 :
                month = "April";
                break;
            case 5 :
                month = "May";
                break;
            case 6 :
                month = "June";
                break;
            case 7 :
                month = "July";
                break;
            case 8 :
                month = "August";
                break;
            case 9 :
                month = "September";
                break;
            case 10 :
                month = "October";
                break;
            case 11:
                month = "November";
                break;
            case 12:
                month = "December";
                break;

        }

        // Adding suffix to the end of the numeric day

        if (day_value % 10 == 1)
        {
            if (day_value == 11)
            {
                day_suffix = "th";
            }
            else
            {
                day_suffix = "st";
            }
        }
        else if (day_value % 10 == 2)
        {
            if (day_value == 12)
            {
                day_suffix = "th";
            }
            else
            {
                day_suffix = "nd";
            }
        }
        else if (day_value % 10 == 3)
        {
            if (day_value == 13)
            {
                day_suffix = "th";
            }
            else
            {
                day_suffix = "rd";
            }
        }
        else
        {
            day_suffix = "th";
        }
    //Justify days in a month, except for Feb.

        if (day_value < 31 && month_value != 2)
        {
            cout << "Dated this " << day_value << day_suffix << " day of " << month << ", " << year << "." << endl;
        }
        else if (day_value == 31 && month_value != 2)
        {
            switch (month_value)
            {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    cout << "Dated this " << day_value << day_suffix << " day of " << month << ", " << year << "." << endl;
                    break;
                default:
                    cout << endl << "Invalid date Entered." << endl;
                    cout << "Day not valid." << endl;
            }
        }
        else if (month_value == 2) // Leap Year identifier
        {
            if (year % 4 != 0 && day_value <= 28)
            {
                cout << "Dated this " << day_value << day_suffix << " day of " << month << ", " << year << "." << endl;
            }
            else if (year % 4 != 0 && day_value > 28)
            {
                cout << endl << "Invalid date Entered." << endl;
                cout << "Day not valid." << endl;
            }
            else if (year % 400 == 0 && day_value <= 29)
            {
                cout << "Dated this " << day_value << day_suffix << " day of " << month << ", " << year << "." << endl;
            }
            else if (year % 400 == 0 && day_value > 29)
            {
                cout << endl << "Invalid date Entered" << endl;
                cout << "Day not valid." << endl;
            }
            else if (year % 4 == 0 && year % 100 != 0 && day_value <= 29)
            {
                cout << "Dated this " << day_value << day_suffix << " day of " << month << ", " << year << "." << endl;
            }
            else if (year % 4 == 0 && year % 100 != 0 && day_value > 29)
            {
                cout << endl << "Invalid date Entered." << endl;
                cout << "Day not valid." << endl;
            }
            else if (year % 4 == 0 && year % 400 != 0 && day_value <= 28)
            {
                cout << "Dated this " << day_value << day_suffix << " day of " << month << ", " << year << "." << endl;
            }
            else if (year % 4 == 0 && year % 400 != 0 && day_value > 28)
            {
                cout << endl << "Invalid date Entered." << endl;
                cout << "Day not valid." << endl;
            }

        }

    }

    return 0;
}
