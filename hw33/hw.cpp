/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       hw.cpp
 * Description: Program returning the recursive function for function harm.n
 * Date:        2026-04-12
 ******************************************************************************/

#include <iostream>
using namespace std;

// Function prototype
double harm(int n); 

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << harm(n) << endl;
    return 0;
}

// Returns a double
double harm(int n) {
    if (n == 1) {
        return 1.0; // Base case
    }
    else {
        // Use 1.0 to force float division
        return harm(n - 1) + (1.0 / n);
    }
}