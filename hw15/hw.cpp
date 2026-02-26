/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Prime Factorization
 * Description: Finds the smallest factor of a number to compute factorization.
 * Date:        2026-02-17
 ******************************************************************************/
#include <iostream>
using namespace std;


//==========================================
// main function
int firstfactor(int n);
int main()
{
  // Get integer n, n > 1, from user
  int n;
  cout << "Enter an integer larger than 1: ";
  cin >> n;

  // Print out factorization
  cout << "The factorization of " << n << " is ";
  while(n > 1)
  {
    // get & print next prime factor
    int f = firstfactor(n);
    cout << '(' << f << ')';
    n = n / f;
  }
  cout << endl;

  return 0;
}




//==========================================
// firstfactor Function
int firstfactor(int n) {
  // Start searching from 2 up to n
  for (int i = 2; i <= n; i++) {
    // If n is divisible by i, then i is the smallest factor
    if (n % i == 0) {
      return i;
    }
  }
  return n; // Fallback (should not be reached for n > 1)
}

