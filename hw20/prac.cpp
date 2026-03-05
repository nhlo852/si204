/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       String in Reverse
 * Description: Prints User Given Strings in Reverse
 * Date:        2026-02-28
 ******************************************************************************/

#include <iostream>
#include <string>

using namespace std;


int main() {
  string s;
  int num;

  cout << "How many strings? "; 
  cin >> num; 

  // Loop through the specified number of strings
  for (int i = 0; i < num; i++) {
    cin >> s; 

    // Start at the last character and count down to index 0
    for (int j = (s.length() - 1); j >= 0; j--) {
        cout << s[j]; // Print each character in reverse order
    }

    // Print a space between reversed words
    cout << " ";
  }
  cout << endl;
  
  return 0;
}