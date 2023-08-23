// Name: Yu Feng
// Gradebook #26
// Assignment 1, EX2

#include <iostream>
using namespace std;

int main ()
{
    float r, d, C, A, pi ;
    cout << "Please enter the radius of a circle: ";
    cin >> r ;

    pi = 3.14159 ;
    d = 2 * r ;
    C = 2 * pi * r;
    A = pi * r * r;

    cout << endl << "A circle with radius = " << r << " units has: \n\t";
    cout << "Diameter = " << d << " units" << endl;
    cout << "\t" << "Circumference = " << C << " units \n";
    cout << "\t" << "Area = " << A << " sq. units" ;

    return 0;
}
