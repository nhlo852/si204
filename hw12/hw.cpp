/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       HTML for Inputs
 * Description: Reads a grid of integers from a file and converts them into 
 * an HTML formatted table.
 * Date:        2026-02-04
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename;
    cout << "Filename: ";
    cin >> filename;

    ifstream fin(filename);
    ofstream fout("output.html");

    // check if input file opened successfully
    if (!fin) {
        cout << "Could not open file '" << filename << "'" << endl;
        return 1;
    }

    int row, column, num;
    fin >> row >> column; // read grid dimensions from first two lines
    fout << "<table border=2>" << endl;

    // Outer loop handles each row 
    for (int i = 0; i < row; i++) {
        fout << "<tr>";
        
        // Inner loop handles each column
        for (int j = 0; j < column; j++) {
            fin >> num;
            fout << "<td>" << num << "</td>";
        }
        
        fout << "</tr>" << endl;
    }

    // Close table tags
    fout << "</table>" << endl;
    cout << "Created output.html" << endl;

    fin.close();
    fout.close();

    return 0;
}