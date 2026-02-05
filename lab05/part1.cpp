/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Lab 5 Part 1
 * Description: Death trap game using character-by-character reading.
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  string filename;
  cin >> filename;
  ifstream fin(filename);

  if (!fin) {
    cout << "File not found!" << endl;
    return 1;
  }
    
  string junk1, junk2;
  int width;
  // Get the width first so we can use it in the prompt
  fin >> junk1 >> junk2 >> width; 

  int pos;
  cout << "Enter position between 1 and " << width << ": ";
  cin >> pos; 

  if (pos < 1 || pos > width) {
    cout << "Invalid position!" << endl;
    return 1;
  }

  char cell;
  int currentStep = 0;
  bool death = false;

  // Outer loop: Read the starting '@' of each row
  while (fin >> cell) { 
    currentStep++;

    // Inner loop: Check every column in the row
    for (int i = 1; i <= width; i++) {
      fin >> cell; 
      if (i == pos && cell == 'X') {
        death = true;
      }
    }

    fin >> cell;

    if (death) { //Exit if death
      break;
    }
  }

  if (death) {
    cout << "You died on step " << currentStep << endl;
  } else {
    cout << "You survived!" << endl;
  }

  fin.close();
  return 0;
}