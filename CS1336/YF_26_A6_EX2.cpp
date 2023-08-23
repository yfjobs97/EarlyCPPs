//Programmer: Yu Feng
//Gradebook number: 26
/*Assignment 6 Exercise 2: a program that calculates the amount of money that you must invest in a savings account
                           at a given interest rate for a given number of years to have a certain dollar amount at the end of
                           the period.
                           Input: Number of years the user plans to let the money stay, and the annual interest rate
                           Output: value user need to deposit */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double getFutureValue();
double getAnnualIntRate();
int getYears ();
double calcPresentValue (double futureValue, double rate, int years);

int main()
{
    double present, future, interest;
    int year;

    future = getFutureValue();
    interest = getAnnualIntRate();
    year = getYears();
    present = calcPresentValue (future, interest, year);

    cout << setprecision(2) << fixed;
    cout << "You need to deposit $" << present << "." << endl;

    return 0;
}

double getFutureValue()
{
    double Future;
    cout << "What is the desired future value of the account? ";
    cin >> Future;
    return Future;
}

double getAnnualIntRate()
{
    double rate;
    cout << "Enter the annual interest rate [For 1.1% enter 1.1]: ";
    cin >> rate;
    return rate;
}

int getYears()
{
    int Years;
    cout << "Enter the number of years the money will stay in the account: ";
    cin >> Years;
    return Years;
}

double calcPresentValue(double futureValue, double rate, int years)
{
    double Present;
    Present = futureValue / pow( (1 + (rate / 100)), years);
    return Present;
}
