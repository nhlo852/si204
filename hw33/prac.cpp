/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       prac.cpp
 * Description: Program demonstrating recursion to print an upside-down 
 * triangle of stars.
 * Date:        2026-04-12
 ******************************************************************************/

#include <iostream>
using namespace std;

// Function Prototypes
void tri(int n); 
void stars(int n);

int main()
{
    int n;
    cin >> n;
    
    // Start the recursive printing process if n is valid
    if (n > 0) {
        tri(n);
    }
    
    return 0;
}

void tri(int n) {
    if (n == 1) {
        cout << "*" << endl; 
    }
    else {
        stars(n);   
        // Move to the next row with 1 less star
        tri(n - 1); 
    }
}

void stars(int n) {
    if (n == 0) {
        cout << endl; 
    }
    else {
        cout << "*";  
        // Recursively print the rest of the stars for this row
        stars(n - 1); 
    }
}