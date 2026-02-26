/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Dot product of two vectors
 * Description: Computes dot-products of vectors of two dimensions
 * Date:        2026-02-22
 ******************************************************************************/

#include <iostream>
#include <iomanip> 
using namespace std;

int main()
{
    float num, prod = 0;
    int dim;
    char junk, junk1;
    cout << "Enter dimension: "; cin >> dim;
    float* a1 = new float[dim];
    float* a2 = new float[dim];

    // Read first vector and ignore punctuation
    cin >> junk;
    for (int i = 0; i < dim; i++) {
        cin >> num;
        a1[i] = num;
        cin >> junk1;
    }
    
    // Read second vector and ignore punctuation
    cin >> junk;
    for (int j = 0; j < dim; j++) {
        cin >> num;
        a2[j] = num;
        cin >> junk1;
    }

    // Multiply corresponding elements and sum them up
    for (int k = 0; k < dim; k++) {
        prod += (a1[k] * a2[k]);  
    }
    
    // Check if the result is a whole number
    if (prod == (int)prod) {
        cout << "Dot product = " << (int)prod << endl;
    } else {
        // Prints exactly 2 decimal places (e.g., -3.03 instead of -3.03001)
        cout << "Dot product = " << fixed << setprecision(2) << prod << endl;
    }
    
    delete[] a1;
    delete[] a2;
    
    return 0;
}