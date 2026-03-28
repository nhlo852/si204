/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Multiples of 3 in 2D Array
 * Description: Reads a matrix and prints the indices of rows and columns 
 * whose sum is a multiple of 3.
 * Date:        2026-03-20
 ******************************************************************************/

#include <iostream>

using namespace std;

int main() {
    int n, m;
    char x;
    
    // Prompt for size
    cout << "What size? ";
    cin >> n >> x >> m;
    
    // Dynamically allocate and fill the 2D array
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // Check rows for sums that are multiples of 3
    cout << "rows:";
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += matrix[i][j];
        }
        if (sum % 3 == 0) {
            cout << " " << i;
        }
    }
    cout << endl;
    
    // Check columns for sums that are multiples of 3
    cout << "cols:";
    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += matrix[i][j];
        }
        if (sum % 3 == 0) {
            cout << " " << j;
        }
    }
    cout << endl;
    
    // Clean up memory
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;
}