/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Greatest Common Divisor 
 * Description: Finds the GCD of two positive 
 * integers provided by the user.
 * Date:        2026-02-17
 ******************************************************************************/
#include <iostream>
using namespace std;

int getposint();
int gcd(int a, int b);

int main()
{
  // Read two positive integers from the user
  int a = getposint();
  int b = getposint();
  cout << "The gcd is " << gcd(a, b) << endl;
  
  return 0;
}

// Prompts user for a positive integer and validates input
int getposint()
{
  int k;
  cout << "Enter a positive integer: ";
  cin >> k;
  
  // Error check loop to ensure value is strictly greater than 0
  while(k <= 0)
  {
    cout << "I said *positive*, try again: ";
    cin >> k;
  }

  return k;
}

// Calculates the Greatest Common Divisor using the Euclidean Algorithm
int gcd(int a, int b)
{

  while(b != 0)
  {
    // Find the remainder of a divided by b
    int r = a % b;
    
    // Shift values: b becomes the new a, remainder becomes the new b
    a = b;
    b = r;
  }
  
  // When b reaches 0, a contains the GCD
  return a;
}