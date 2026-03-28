/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Row and Column Lookup
 * Description: Reads a 2D array and prints specific rows and columns based 
 * on user request.
 * Date:        2026-03-20
 ******************************************************************************/

#include <iostream>

using namespace std;

int main() {
    int rows, cols;
    char x;
    
    // Read dimensions 
    if (!(cin >> rows >> x >> cols)) return 0;

    // Fill the 2D array
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Get the requested row and print it
    int targetRow;
    cout << "Row: ";
    cin >> targetRow;
    for (int j = 0; j < cols; j++) {
        cout << matrix[targetRow][j];
        if (j < cols - 1) {
            cout << " ";
        }
    }
    cout << endl;

    // Get the requested column and print it
    int targetCol;
    cout << "Column: ";
    cin >> targetCol;
    for (int i = 0; i < rows; i++) {
        cout << matrix[i][targetCol] << endl;
    }

    // Clean up memory
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}