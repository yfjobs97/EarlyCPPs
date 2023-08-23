//Programmer: Yu Feng
//Gradebook number: 26
//Assignment 3 EX 2: The programme asks for 4 digit military Time and display the converted standard Time with AM or PM

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int Time, hour, minute;
// Define string "Indicator" as the string for displaying AM or PM .
string Indicator;
int main()
{
    cout << "This program converts military Time to standard Timer." << endl;
    cout << "Enter a Time in military Time [dddd]: ";
    cin >> Time;

    //Justify morning and night
    if (Time >= 0100 && Time <= 1159)
    {
        hour = Time / 100;
        minute = Time - hour * 100;
        Indicator = "AM";
        cout << setw(4) << setfill('0') << Time << " hours is "
             << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << " " << Indicator << ".";
    }
    if (Time >= 1300 && Time <= 2359)
    {
        hour = (Time - 1200) / 100;
        minute = (Time - hour * 100) - 1200;
        Indicator = "PM";
        cout << setw(4) << setfill('0') << Time << " hours is "
             << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << " " << Indicator << ".";
    }
    if (Time >= 1200 && Time <= 1259 )
    {
        hour = Time / 100;
        minute = Time - hour * 100;
        Indicator = "PM";
        cout << setw(4) << setfill('0') << Time << " hours is "
             << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << " " << Indicator << ".";
    }
    if (Time < 0 || Time > 2400)
    {
        cout << "Error: Invalid Time entered.";
    }
    if  (Time >= 0 && Time <= 59)
    {
        hour = (Time + 1200) / 100;
        minute = (Time - hour * 100) + 1200;
        Indicator = "AM";
        cout << setw(4) << setfill('0') << Time << " hours is " << hour << ":" << minute << " " << Indicator << ".";
    }
    if (Time == 2400)
    {
        cout << Time << " hours is 12:00 AM.";
    }
    return 0;
}
