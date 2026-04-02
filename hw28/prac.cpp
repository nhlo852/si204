/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Cockroach Tracker
 * Description: Reads times and locations from a file and finds where the 
 * roach was at a specific time.
 * Date:        2026-03-28
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Struct for the time
struct hhmmss {
    int h, m, s;
};

// Struct for the x, y coordinates
struct point {
    double x, y;
};

// The main box that holds both the time and the coordinates
struct datum {
    hhmmss time;
    point pos;
};

// Helper functions
void read(datum& d, istream& in);
bool before(hhmmss a, hhmmss b);

int main() {
    ifstream fin("trial.txt");
    
    // Stop if there is no file
    if (!fin) return 0; 

    int n;
    string s1, s2;
    // Read the top line: "8 data listings"
    fin >> n >> s1 >> s2;

    // Make an array to hold all the roach sightings
    datum* A = new datum[n];
    
    // Fill the array using our custom read function
    for (int i = 0; i < n; i++) {
        read(A[i], fin);
    }
    fin.close();

    // Ask the user for a time
    cout << "Enter a time: ";
    hhmmss T;
    char junk;
    
    // Read the user input like [01:00:20]
    cin >> junk >> T.h >> junk >> T.m >> junk >> T.s >> junk;

    // Search the array to find where the roach is
    int foundIndex = n; // Assume it's after the very end to start
    
    for (int i = 0; i < n; i++) {
        // As soon as the user's time is BEFORE the array's time, stop!
        if (before(T, A[i].time)) {
            foundIndex = i;
            break; 
        }
    }

    // Print the answer based on where we stopped in the array
    if (foundIndex == 0) {
        cout << "This was before the first sighting at (" 
             << A[0].pos.x << "," << A[0].pos.y << ")" << endl;
    }
    else if (foundIndex == n) {
        cout << "This was after the last sighting at (" 
             << A[n-1].pos.x << "," << A[n-1].pos.y << ")" << endl;
    }
    else {
        cout << "The roach was somewhere between (" 
             << A[foundIndex-1].pos.x << "," << A[foundIndex-1].pos.y << ") and (" 
             << A[foundIndex].pos.x << "," << A[foundIndex].pos.y << ")" << endl;
    }

    delete[] A;
    return 0;
}

// Function to read the ugly string
void read(datum& d, istream& in) {
    char junk;
    
    in >> junk >> junk; // Throw away '{' and '['
    in >> d.time.h >> junk >> d.time.m >> junk >> d.time.s; // Read 02:00:23
    
    in >> junk >> junk >> junk; // Throw away ']', ',', and '('
    in >> d.pos.x >> junk >> d.pos.y; // Read 6.67 and 0.03
    
    in >> junk >> junk; // Throw away ')' and '}'
}

// Function to check if time 'a' happens before time 'b'
bool before(hhmmss a, hhmmss b) {
    // Check hours
    if (a.h < b.h) return true;
    if (a.h > b.h) return false;
    
    // If hours are tied, check minutes
    if (a.m < b.m) return true;
    if (a.m > b.m) return false;
    if (a.s < b.s) return true;
    return false;
}