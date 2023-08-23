//Programmer: Yu Feng
//Gradebook number: 26
/*Assignment 7: a program that gets an unspecified number of student ID numbers and averages from the user
and writes the ID numbers, averages, and letter grades earned to the file specified by the user and
displays the number of students whose data was entered, the average of the entered student averages,
and a histogram showing the grade distribution on the computer screen.*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

double getAverage();
char assignLetterGrade(double avg);
void drawHistogram(int);

int main ()
{
    string filename;
    ofstream output;
    cout << "Enter the name of the file that will store the student data: ";
    getline(cin, filename);
    output.open(filename);

    int studentID, counter = 0;
    double total_average = 0, average, average_of_average;
    int letter_sort [5] = {0};
    char letters [5] = {'A', 'B', 'C', 'D', 'F'};
    char letter_grade;
    for (counter = 1; studentID != 0; counter++)
    {
        cout << "Student #" << counter << ":" << endl;
        cout << "Enter the student's ID number or 0 to end input: ";
        cin >> studentID;
        while (studentID < 0)
        {
            cout << "Student's ID must be positive." << endl;
            cout << "Enter the student's ID number or 0 to end input: ";
            cin >> studentID;
        }
        if (studentID != 0)
        {
            average = getAverage();
            total_average += average;
            letter_grade = assignLetterGrade (average);

            switch (letter_grade)
            {
                case 'A':
                    letter_sort[0]++;
                    break;
                case 'B':
                    letter_sort[1]++;
                    break;
                case 'C':
                    letter_sort[2]++;
                    break;
                case 'D':
                    letter_sort[3]++;
                    break;
                case 'F':
                    letter_sort[4]++;
                    break;
            }
            output << studentID << "\t" << average << "\t" << letter_grade << endl;
        }
    }
    if (counter != 0)
    {
        int total = 0;
        for (int students : letter_sort)
            total += students;

        average_of_average = total_average / total;

        cout << endl << "Number of students: " << total << endl;
        cout << "The average of the student averages was: " << average_of_average << endl;
        for (int index = 0; index < 5; index++)
        {
            cout << endl << letters[index] << "'s: ";
            drawHistogram(letter_sort[index]);
        }
    }
    return 0;
}

double getAverage ()
{
    double average;
    cout << "Enter the student's average: ";
    cin >> average;
    return average;
}

char assignLetterGrade (double avg)
{
    char letter;
    if (avg >= 90)
    {
        letter = 'A';
    }
    else if (avg >= 80 && avg < 90)
    {
        letter = 'B';
    }
    else if (avg >= 70 && avg < 80)
    {
        letter = 'C';
    }
    else if (avg >= 60 && avg < 70)
    {
        letter = 'D';
    }
    else
    {
        letter = 'F';
    }
    return letter;
}

void drawHistogram(int stars)
{
    cout << setfill('*') << setw(stars + 1) << " ";
    return;
}
