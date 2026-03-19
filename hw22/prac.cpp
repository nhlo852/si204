/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Min and Max from File
 * Description: Reads numbers from a given file and finds the minimum and maximum.
 * Date:        2026-03-05
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void fileMinMax(string fname, double& min, double& max);

int main(){
  string fname;
  cout << "Filename: ";
  cin >> fname;

  double min, max;

  // A single function call to fileMinMax
  fileMinMax(fname, min, max);

  cout << "min= " << min << " max= " << max << endl;
  
  return 0;
}

void fileMinMax(string fname, double& min, double& max) {
    ifstream fin(fname);

    if (!fin) {
        cout << "Error: File could not be opened." << endl;
        return;
    }

    double num;
    
    // Read the very first number to initialize min and max
    if (fin >> num) {
        min = num;
        max = num;
    } else {
        // If the file is completely empty, exit the function
        return; 
    }

    // Loop through the rest of the numbers in the file
    while (fin >> num) {
        if (num < min) {
            min = num; // Found a new minimum
        }
        if (num > max) {
            max = num; // Found a new maximum
        }
    }
    
    fin.close();
}