/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Hankel Matrix
 * Description: Prints a matrix of length n (user input) horizontally and vertically
 * Date:        2026-02-02
 ******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter value n, where n < 50: ";
  cin >> n;

  for (int i = 1; i <= n; i++) {         // Loop through each row
    for (int j = 1; j <= n; j++) {       // Loop through each column
      int tot = i + j - 1;               // Calculate the Hankel value
      if (tot < 10)
        cout << ' ';
      cout << tot << ' ';
    }
    cout << endl;
  }
  
  return 0;
}