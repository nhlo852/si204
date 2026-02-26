/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Practicum 1 Part 3
 * Description: Percentage or Fraction of People
 * Date:        2026-02-012
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

  int num;
  cout << "Give an odd number n (n>= 3): ";

  cin >> num;
  for (int i = 1; i <= num; i++) {
    if (i == ((num/2) + 1)) { 
        for (int j = 0; j < num; j++) cout << "#";
    }
    else {
        cout << "#";
        for (int j = 1; j < (num-1); j++) {
            cout << ".";
        }
        cout << "#";
    }
    cout << endl;
  }
  

  return 0;
}