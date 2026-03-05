/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Combine and leave only letters
 * Description: Combines user given strings, removes non-letters, and 
 * prints the result forwards and backwards.
 * Date:        2026-02-28
 ******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  string combinedS = ""; 
  int num;
  if (!(cin >> num)) return 0;

  // Loop through the specified number of words
  for (int i = 0; i < num; i++) {
    cin >> s; 
    
    // Process each character in the current word 
    for (int j = 0; j < (int)s.length(); j++) {
      char c = s[j];
      if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
        combinedS += c; // Build the string containing only letters
      }
    }
  }

  cout << combinedS << endl;

  // Second output: Reverse order
  for (int k = (int)combinedS.length() - 1; k >= 0; k--) {
    cout << combinedS[k];
  }
  
  cout << endl;
  
  return 0;
}