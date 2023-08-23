//Programmer: Yu Feng
//Gradebook number: 26
//Assignment 3 EX 1: a program that gets the names and votes received by three candidates and then displays each candidate¡¯s name, the number of votes the candidate received, and the percentage of the total votes the candidate received in a table.

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Define variables to store candidates' names and their votes
string candidate_1, candidate_2, candidate_3;
double vote_1, vote_2, vote_3, total_votes;
//Define variables to store the percentage result of the votes
float percentage_1, percentage_2, percentage_3;
int main ()
{
    //Ask for the names of the candidates and the votes they received
    cout << "Enter the name of the first candidate: ";
    getline(cin, candidate_1);
    cout << endl <<"Enter the number of votes received by " << candidate_1 + ": ";
    cin >> vote_1;
    cin.ignore(); //Skip newline character

    cout << endl << "Enter the name of the second candidate: ";
    getline(cin,candidate_2);
    cout << endl << "Enter the number of votes received by " << candidate_2 + ": ";
    cin >> vote_2;
    cin.ignore();

    cout << endl << "Enter the name of the third candidate: ";
    getline(cin, candidate_3);
    cout << endl << "Enter the number of votes received by " << candidate_3 + ": ";
    cin >> vote_3;
    cin.ignore();

    //Calculate the total votes and the percentage of votes each candidates received
    total_votes = vote_1 + vote_2 + vote_3;
    percentage_1 = vote_1 / total_votes * 100;
    percentage_2 = vote_2 / total_votes * 100;
    percentage_3 = vote_3 / total_votes * 100;

    //Display the formatted result
    cout << setprecision(2) << fixed << showpoint;

    cout << endl << endl << "Candidate" << setw(40) << "Votes" << setw(14) << "Percent" << endl;
    cout << "***************************************************************" << endl;
    cout << candidate_1 << setw(39) << static_cast<int>(vote_1) << setw(14) << percentage_1 << endl;
    cout << candidate_2 << setw(39) << static_cast<int>(vote_2) << setw(14) << percentage_2 << endl;
    cout << candidate_3 << setw(38) << static_cast<int>(vote_3) << setw(14) << percentage_3 << endl;
    cout << setw(35) << "TOTAL VOTES:" << setw(14) << static_cast<int>(total_votes) << endl;

    return 0;
}
