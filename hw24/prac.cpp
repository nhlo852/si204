/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Grade Lookup
 * Description: Reads a file of student grades and allows the user to query 
 * specific grades by student and homework number.
 * Date:        2026-03-20
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string fname;
    cout << "Filename: ";
    cin >> fname;

    ifstream fin(fname);
    int numStudents, numAssignments;
    string j1, j2;

    // j1 and j2 eat the words so they don't mess up our integers
    fin >> numStudents >> j1 >> numAssignments >> j2;

    // Dynamically allocate a 2D array for the grades
    // First, create an array of integer pointers (the rows)
    int** grades = new int*[numStudents];
    for (int i = 0; i < numStudents; i++) {
        // For each row, allocate an array of integers (the columns)
        grades[i] = new int[numAssignments];
        
        // Fill the current row with the student's grades from the file
        for (int j = 0; j < numAssignments; j++) {
            fin >> grades[i][j];
        }
    }
    fin.close();

    char choice;
    // Infinite loop that breaks when the user chooses 'Q'
    while (true) {
        cout << "(Q)uit or (V)iew? ";
        cin >> choice;
        
        if (choice == 'Q' || choice == 'q') {
            break; // Exit the loop
        } 
        else if (choice == 'V' || choice == 'v') {
            int s, h;
            // Ask for specific indices and print the corresponding 2D array element
            cout << "Student number [0.." << (numStudents - 1) << "]: ";
            cin >> s;
            cout << "Homework number [0.." << (numAssignments - 1) << "]: ";
            cin >> h;
            cout << "Grade was " << grades[s][h] << endl;
        }
    }

    // Must delete each row first, then the array of pointers
    for (int i = 0; i < numStudents; i++) {
        delete[] grades[i];
    }
    delete[] grades;

    return 0;
}