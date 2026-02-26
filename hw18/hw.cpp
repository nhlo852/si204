/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       X and Y arrays
 * Description: Takes in input n length of array and outputs array x and y
 * Date:        2026-02-23
 ******************************************************************************/

#include <iostream>
#include <iomanip> 
using namespace std;

int main()
{
    float numX, numY;
    int dim;
    char junk, junk1, junk2;
    cin >> junk >> junk1 >> dim;
    float* aX = new float[dim];
    float* aY = new float[dim];

    // Loop through the input for X and Y values 
    for (int i = 0; i < dim; i++) {
        cin >> junk2; // Eat opening punctuation 
        cin >> numX;
        aX[i] = numX;

        cin >> junk2; // Eat separator ','
        cin >> numY;
        aY[i] = numY;

        cin >> junk2; // Eat  ')'
    }
    
    // Output the X array in bracketed format
    cout << "X := [";
    for (int j = 0; j < dim; j++) {
        if (dim == 1) {
            cout << aX[j];
        }
        // Add comma separator for all elements except the last one
        else if (!(j == (dim-1))) cout << aX[j] << ", ";
        else cout << aX[j];
    }
    cout << "]" << endl;

    // Output the Y array in bracketed format
    cout << "Y := [";
    for (int k = 0; k < dim; k++) {
        if (dim == 1) {
            cout << aY[k];
        }
        // Add comma separator for all elements except the last one
        else if (!(k == (dim-1))) cout << aY[k] << ", ";
        else cout << aY[k];
    }
    cout << "]" << endl;

    delete[] aX;
    delete[] aY;
    
    return 0;
}