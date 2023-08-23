//Programmer: Yu Feng
//Gradebook number: 26
/*Assignment 2: Slot Machine: It shows 3 random numbers and determine if they are equal to each other.
                              If the numbers are equal, the programme adds corresponded tokens to the player depending on the situation of winning.
                              If the numbers aren't equal, the programme tells the player that he loses and deduct 1 token from what he currently has.
                              The player starts with 100 tokens and the game will end until he doesn't want to play by typing N or loses all his tokens. */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main ()
{
    int tokens = 100;
    int slot1, slot2, slot3, limit;
    char selection;
    const int max_value = 3;
    const int min_value = 1;
    unsigned seed = time(0);

    //Random number domain

    limit = max_value - min_value + 1;
    srand(seed);

    //Welcome screen

    cout << "WELCOME TO THE TRIO SLOT MACHINE!" << endl;
    cout << endl << "You have " << tokens << " tokens." << endl;
    cout << "Would you like to play?" << endl;
    cout << "Enter Y to pull or enter N to end [Y/N]: ";
    cin >> selection;

    //Convert small case letter to big case

    do
    {
       switch (selection)
        {
            case 'y':
                selection = 'Y';
                break;
            case 'n':
                selection = 'N';
                break;
            case 'Y':
                break;
            case 'N':
                break;
            default:
                cout << selection << " is not a valid response." << endl;
                cout << "Enter Y to pull or enter N to end. [Y/N]: ";
                cin >> selection;
        }

        if (selection == 'Y')
        {
            slot1 = rand() % limit + 1;
            slot2 = rand() % limit + 1;
            slot3 = rand() % limit + 1;

            //Output Random Number
            cout << endl <<"[" << slot1 << "]\t" << "[" << slot2 << "]\t"
                 << "[" << slot3 << "]\n";

            //Determine if the player wins
            if (slot1 == slot2 && slot2 == slot3 && slot1 == slot3 && slot1 == 1)
            {
                cout << "You have won 4 tokens!" << endl;
                tokens -= 1; //Cost of the spin
                tokens += 4;
            }
            else if (slot1 == 2 && slot1 == slot2 && slot2 == slot3 && slot1 == slot3)
            {
                cout << "You have won 8 tokens!" << endl;
                tokens -= 1; //Cost of the spin
                tokens += 8;
            }
            else if (slot1 == 3 && slot1 == slot2 && slot2 == slot3 && slot1 == slot3)
            {
                cout << "You have won 12 tokens!" << endl;
                tokens -= 1; //Cost of the spin
                tokens += 12;
            }
            else
            {
                cout << "Sorry, you lose." << endl;
                tokens -= 1; //Cost of the spin
            }

            //Ask the player their will to keep playing after winning/losing tokens

            if (tokens > 1)
            {
                cout << endl << "You have " << tokens << " tokens.";
                cout << endl << "Enter Y to pull again or enter N to end [Y/N]: " ;
                cin >> selection;
            }
            else if (tokens == 1)
            {
                cout << endl << "You have " << tokens << " token.";
                cout << endl << "Enter Y to pull again or enter N to end [Y/N]: " ;
                cin >> selection;
            }
            else
            {
                cout << endl << "Sorry! You have ran out of tokens.";
                selection = 'N';
            }

        }
    } while (selection != 'N');

    //End Statement if the game ends

    cout << endl << "Thanks for playing!" << endl;
    cout << "Come play again soon." << endl;

    return 0;
}
