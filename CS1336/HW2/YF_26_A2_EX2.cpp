//Programmer: Yu Feng
//Gradebook 26
//Assignment 2 EX2: Calculation of the Trigonometry with a given angle in degrees.

#include <iostream>
//Include to calculate Trigonometry
#include <cmath>
//Include to set use "setprecision" and "setw()"
#include <iomanip>

using namespace std;

//Define Variables
double degree, radius, sine, cosine, tangent;
int main ()
{
    //Set the precision to the nearest ten-thousands
    cout << setprecision(4) << fixed;

    //Ask for the angle in degree
    cout << "Enter an angle in degrees: ";
    cin >> degree;

    //Converting from degree to radius
    radius = degree * acos(-1) / 180;

    //Calculate the sine, cosine, tangent value
    sine = sin(radius);
    cosine = cos(radius);
    tangent = tan(radius);

    //Display the results
    cout << endl << setw(9) << "Sine: " << sine << endl;
    cout << setw(9) << "Cosine: " << cosine << endl;
    cout << "Tangent: " << tangent << endl;

    return 0;
}
