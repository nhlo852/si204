/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Split positive and negative numbers
 * Description: Take in inputs of length n and split into positive and negative arrays
 * Date:        2026-02-23
 ******************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int num, countPos = 0, countNeg = 0;
    int dim;
    cin >> dim;
    int* Apos = new int[dim];
    int* Aneg = new int[dim];
    
    // Process each input and sort into the appropriate array
    for (int i = 0; i < dim; i++) {
        cin >> num;
        if (num > 0) {
            Apos[countPos] = num;
            countPos++;
        }
        else {
            Aneg[countNeg] = num;
            countNeg++;
        }
    }

    // Output all stored negative numbers
    cout << "negative: ";
    for (int j = 0; j < dim; j++) {
        // Only print non-zero entries 
        if (!(Aneg[j] == 0)) cout << Aneg[j] << " ";
    }
    cout << endl;

    // Output all stored positive numbers
    cout << "positive: ";
    for (int k = 0; k < dim; k++) {
        // Only print non-zero entries
        if (!(Apos[k] == 0)) cout << Apos[k] << " ";
    }
    cout << endl;
    
    delete[] Apos;
    delete[] Aneg;
    
    return 0;
}