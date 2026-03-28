/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Midshipmen Search
 * Description: Reads a file into a struct array and searches by alpha.
 * Date:        2026-03-23
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Define the struct before main so the program knows what a "mid" is
struct mid {
    int alpha;
    string first, last;
};

int main() {
    // Make an array of 41 Mids
    mid* A = new mid[41];

    // Open file
    ifstream fin("Mids.txt");
    
    // Stop if the file is missing
    if (!fin) {
        cout << "Error opening file." << endl;
        return 1;
    }

    // Read in all 41 mids
    for (int i = 0; i < 41; i++) {
        // The dot (.) lets us reach inside the struct to set the variables
        fin >> A[i].alpha >> A[i].last >> A[i].first;
    }
    fin.close();

    // Ask the user who to look for
    int targetAlpha;
    cout << "Enter alpha: ";
    cin >> targetAlpha;

    bool found = false;
    
    // Check every mid in the array one by one
    for (int i = 0; i < 41; i++) {
        if (A[i].alpha == targetAlpha) {
            // Print first name then last name
            cout << A[i].first << " " << A[i].last << endl;
            found = true;
            break; // Stop searching since we found them
        }
    }

    // If the loop finished and we never flipped "found" to true
    if (!found) {
        cout << "No Mid with that alpha was found!" << endl;
    }

    // Delete the array to give memory back
    delete[] A;

    return 0;
}