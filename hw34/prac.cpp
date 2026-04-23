/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       change.cpp
 * Description: A recursive program to determine the coins needed to make 
 * a specific amount of change using Quarters, Dimes, Nickels, 
 * and Pennies.
 * Date:        2026-04-16
 ******************************************************************************/

#include <iostream>
using namespace std;

// Function prototype
void calculate_change(int remaining);

int main() {
    int total_cents;
    
    // Prompt the user for the starting amount
    cout << "Enter amount: ";
    cin >> total_cents;

    cout << "Change to give is: ";
    
    // Start the recursive coin calculation
    calculate_change(total_cents);
    cout << endl;

    return 0;
}

// Recursively prints the coins needed to make change
void calculate_change(int remaining) {
    // If there are 0 cents left, stop the recursion
    if (remaining == 0) {
        return;
    }

    // Find the largest coin we can use
    int coin_val;
    
    if (remaining >= 25) {
        coin_val = 25;
        cout << 'Q';
    }
    else if (remaining >= 10) {
        coin_val = 10;
        cout << 'D';
    }
    else if (remaining >= 5) {
        coin_val = 5;
        cout << 'N';
    }
    else {
        // If it's less than 5, we have to use pennies
        coin_val = 1;
        cout << 'P';
    }

    // Call the function again with the remaining amount after giving one coin
    calculate_change(remaining - coin_val);
}