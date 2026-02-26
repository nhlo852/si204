/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Average Calculator
 * Description: Reads N integers into a dynamic array and calculates their average.
 * Date:        2026-02-24
 ******************************************************************************/

#include <iostream>

using namespace std;

int* readints(int n);
int sum(int* A, int n);

int main() {
    int N;
    cout << "How many numbers? ";
    cin >> N;
    int* A = readints(N);
    int s = sum(A, N);

    double avg = s / double(N);

    cout << "Average is " << avg << endl;

    delete[] A;
    return 0;
}

// Function to read integers from user
int* readints(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return arr;
}

// Function to calculate the sum of all elements in the array
int sum(int* A, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += A[i];
    }
    return total;
}