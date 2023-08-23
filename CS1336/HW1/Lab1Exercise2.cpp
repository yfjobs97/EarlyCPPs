// CS 1136 Lab 1 Exercise 2
// A programme to calculate the user's age
// in dog years
//
// Program by: Yu Feng

#include <iostream>
using namespace std;

int main ()
{
    int humanAge, dogAge;

    cout << "How old are you?";
    cin >> humanAge;

    dogAge = humanAge * 7;

    cout << "Wow, in dog years, that is " << dogAge << ".\n";

    cout << "Hello. My name is Yu Feng\n";

    return 0;
}
