/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Percentage of Prime
 * Description: Calculates what percent of numbers are Prime up to n
 * Date:        2026-02-19
 ******************************************************************************/

#include <iostream>
using namespace std;

// Function prototype
bool isprime(int n);

int main()
{
    int n;
    cout << "Enter n: "; cin >> n;
    
    // Counter to keep track of how many primes we find
    int count = 0;
    
    // Loop through the first n positive integers 
    for (int i = 1; i <= n; i++) {
        // If the current number is prime, increment our counter
        if (isprime(i)) {
            count++;
        }
    }
    
    // Calculate percentage: cast n to a double to prevent integer division 
    cout << (count / double(n)) * 100.0 << "% of the first " << n << " integers are prime!" << endl;

    return 0;
}

bool isprime(int n)
{
    // 0 and 1 are mathematically not considered prime numbers
    if (n <= 1) {
        return false;
    }

    // Check divisibility from 2 up to n-1
    for (int i = 2; i < n; i++) {
        // If n is evenly divisible by i, it is not prime
        if (n % i == 0) {
            return false;
        }
    }
    
    // If we make it through the loop without returning false, the number is prime
    return true;
}