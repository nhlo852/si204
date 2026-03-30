/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Find Hardest Problem
 * Description: Finds which problem had the lowest average.
 * Date:        2026-03-20
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Read the file and make the 2D array
double** readGrades(string fname, int* ns, int* np) {
    *ns = 0;
    *np = 0;
    
    ifstream fin(fname);
    if (!fin) return 0; // Exit if no file

    string j1, j2;
    fin >> *ns >> j1 >> *np >> j2; 

    if (*ns <= 0 || *np <= 0) return 0;

    // Skip the line with "p1 p2 p3"
    string junk;
    for (int i = 0; i < *np; i++) {
        fin >> junk;
    }

    // Make 2D array
    double** P = new double*[*ns];
    for (int i = 0; i < *ns; i++) {
        P[i] = new double[*np];
        for (int j = 0; j < *np; j++) {
            fin >> P[i][j];
        }
    }
    fin.close();
    return P; 
}

// Turn points into percents and find the average
double avgGradeOfProblem(double** P, int ns, int problemIndex) {
    double maxScore = 0;
    
    // Find highest score
    for (int i = 0; i < ns; i++) {
        if (P[i][problemIndex] > maxScore) {
            maxScore = P[i][problemIndex];
        }
    }
    
    if (maxScore == 0) return 0.0;

    // Do the percent math
    double sumPercentage = 0;
    for (int i = 0; i < ns; i++) {
        sumPercentage += (P[i][problemIndex] / maxScore) * 100.0;
    }

    return sumPercentage / ns;
}

int main() {
    cout << "Filename: ";
    string fname;
    cin >> fname;

    int ns = 0, np = 0;
    double** P = readGrades(fname, &ns, &np);

    // Stop if file is broken
    if (P == 0) {
        cout << "Error opening file." << endl;
        return 1;
    }

    // Start with a really high fake average
    double minAvg = 200.0; 
    int hardestProblem = -1;

    // Look at each problem to find the lowest score
    for (int j = 0; j < np; j++) {
        double avg = avgGradeOfProblem(P, ns, j);
        if (avg < minAvg) {
            minAvg = avg;
            hardestProblem = j; // Save the problem number
        }
    }

    // +1 so it prints "p4" instead of "p3"
    cout << "Problem p" << (hardestProblem + 1) << " is hardest (ave = " << minAvg << "%)" << endl;

    // Delete array
    for (int i = 0; i < ns; i++) {
        delete[] P[i];
    }
    delete[] P;

    return 0;
}