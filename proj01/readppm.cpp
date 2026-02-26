/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Proj 01 Part 1
 * Description: Reads PPM image and prints pixel RGB values.
 * Date:        2026-02-07
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  string filename;
  cout << "Input file: ";
  cin >> filename;

  // Open and validate file
  ifstream fin(filename);
  if (!fin) { 
    cout << "Error: Input file not found" << endl;
    return 1;
  }

  // Read PPM heade
  string fileHeader;
  int width, height, maxVal;
  fin >> fileHeader >> width >> height >> maxVal;

  // Print header info
  cout << fileHeader << endl;
  cout << "width = " << width << ", " << "height = " << height << endl;
  cout << "max value = " << maxVal << endl;

  // Process rows
  for (int row = 0; row < height; row++) {
    cout << "*** row " << row << " ***" << endl;
    
    // Process columns in current row
    for (int col = 0; col < width; col++) {
        int r, g, b;
        fin >> r >> g >> b;

        // Display pixel coordinates and color values
        cout << "row " << row << ", " << "col " << col << ": "; 
        cout << "r" << r << " g" << g << " b" << b << endl;
    }
  }

  fin.close();
  return 0;
}