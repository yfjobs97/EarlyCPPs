//Programmer: Yu Feng
//Gradebook Number: 26
/*Assignment 5 Exercise 2: Rectangle Drawer: The programme asks the user for the row and columns the user wants for their rectangle,
                           the character the rectangle is to be composed of, and whether they want a hollow or filled rectangle.
                           Then, the programme displays the rectangle requested. */

#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
    int rows, columns, selection, columns_in_between;
    char character;


    cout << "Welcome to the rectangle drawing program." << endl;

    cout << "Enter the number of rows for your rectangle: ";
    cin >> rows;
    while (rows <= 0)
    {
        cout << "Rows must be greater than 0." << endl;
        cout << "Enter the number of rows for your rectangle: ";
        cin >> rows;
    }

    cout << "Enter the number of columns for your rectangle: ";
    cin >> columns;
    while (columns <= 0)
    {
        cout << "Columns must be greater than 0." << endl;
        cout << "Enter the number of columns for your rectangle: ";
        cin >> columns;
    }

    cout << "Enter the single character you want to use to draw the rectangle: ";
    cin >> character;

    cout << "Enter 1 if you want the rectangle to be drawn hollow, 0 if filled: ";
    cin >> selection;
    while (selection < 0 || selection > 1)
    {
        cout << "Error: Invalid selection entered." << endl;
        cout << "Enter 1 if you want the rectangle to be drawn hollow, 0 if filled: ";
        cin >> selection;
    }

    cout << setfill (character);
    cout << setw(columns + 1) << " " << endl;
    columns_in_between = rows - 2;

    for (int done = 0; done < columns_in_between; done++)
    {
        if (selection == 0)
        {
            cout << setw(columns + 1) << " " << endl;
        }
        else if (selection == 1)
        {
            cout << character << setfill(' ') << setw(columns - 1) << character << endl;
        }
    }
    cout << setfill(character);
    cout << setw(columns + 1) << " " << endl;

    return 0;
}
