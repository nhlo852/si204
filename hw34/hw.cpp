/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       hw.cpp
 * Description: Recursive implementations of array reading, printing, and 
 * checking if elements are in order without using loops.
 * Date:        2026-04-15
 ******************************************************************************/

#include <iostream>
#include "hw.h"

using namespace std;

// Recursively reads integers into the array
void read(int* A, int start, int end) {
    if (start > end) {
        return; // Base case: end of the array range reached
    }
    
    cin >> A[start];
    read(A, start + 1, end); // Recursive call for the next index
}

// Recursively prints the array elements separated by spaces
void print(int* A, int start, int end) {
    if (start > end) {
        return; // Base case
    }
    
    cout << A[start];
    
    if (start == end) {
        cout << endl; // Print newline at the very last element
    } else {
        cout << " ";
        print(A, start + 1, end); // Recursive call for the next index
    }
}

// Recursively checks if the array is sorted in ascending order
bool inorder(int* A, int start, int end) {
    if (start >= end) {
        return true; // Base case: 1 or 0 elements left means it is sorted
    }
    
    if (A[start] > A[start + 1]) {
        return false; // Found an out-of-order adjacent pair
    }
    
    return inorder(A, start + 1, end); // Recursive call to check the rest
}