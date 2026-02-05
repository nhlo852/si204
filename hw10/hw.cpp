/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Adult and Child Counter
 * Description: Reads names and birthdates to count adults based on 09/27/2000.
 * Date:        2026-02-02
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  string filename, name;
  int month, day, year;
  char s1, s2; // for the slashes
  int adults = 0, children = 0;

  cout << "Filename: ";
  cin >> filename;

  ifstream fin(filename);
  if (!fin) {
    cout << "File not found!" << endl;
    return 1;
  }

  // Read: Name MM / DD / YY
  while (fin >> name >> month >> s1 >> day >> s2 >> year) {
    // Convert 2-digit year to 4-digit year
    if (year >= 20) {
      year += 1900;
    } else {
      year += 2000;
    }

    // Check if born on or before 2000-09-27
    if (year < 2000) {
      adults++;
    } else if (year == 2000) {
      if (month < 9) {
        adults++;
      } else if (month == 9) {
        if (day <= 27) {
          adults++;
        } else {
          children++;
        }
      } else {
        children++;
      }
    } else {
      children++;
    }
  }

  cout << adults << " adults and " << children << " children" << endl;

  return 0;
}