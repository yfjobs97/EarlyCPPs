//Programmer: Yu Feng
//Gradebook number: 26
//Assignment 2 EX 1: Evaluating assessment value and property tax with a given property value.

//Including the header files
#include <iostream>

//Include to set use "setprecision" and "setw()"
#include <iomanip>

using namespace std;

//define the actual value of property
double value_property, assessment_value, property_tax;

int main ()
{
    //set the precision to nearest hundreds
    cout << setprecision(2) << fixed;
    // Ask the user for the actual value of property
    cout << "Enter the actual value of the property: ";
    cin >> value_property;

    // Calculation processes
    assessment_value = value_property * 0.6;
    property_tax = assessment_value * 1.65 / 100;

    // Display the result
    cout << endl << setw(20) << "Assessment Value: $";
    cout << setw(13) << assessment_value << endl;
    cout << "Property Tax Owed: $" << setw(13) << property_tax << endl;

    return 0;
}
