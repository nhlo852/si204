/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Proj 01 Part 3
 * Description: Replaces green pixels in a foreground image with pixels 
 * from a background image.
 * Date:        2026-02-17
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  string fgName, bgName, outName;

  // Get filenames
  cout << "Foreground file: ";
  cin >> fgName;
  cout << "Background file: ";
  cin >> bgName;
  cout << "Output file: ";
  cin >> outName;

  // Open input files
  ifstream ffin(fgName);
  ifstream bfin(bgName);
  if (!ffin || !bfin) {
    cout << "Error: Input file not found" << endl;
    return 1;
  }

  // Read foreground header
  string p3;
  int fW, fH, fMax;
  ffin >> p3 >> fW >> fH >> fMax;

  // Read background header
  int bW, bH, bMax;
  bfin >> p3 >> bW >> bH >> bMax;

  // Check if sizes match
  if (fW != bW || fH != bH) {
    cout << "Error: Images have different sizes" << endl;
    return 1;
  }

  // Open output file and write header
  ofstream fout(outName);
  fout << "P3" << endl;
  fout << fW << " " << fH << endl;
  fout << fMax << endl;

  // Process every pixel
  int fr, fg, fb; // Foreground RGB
  int br, bg, bb; // Background RGB

  

  for (int i = 0; i < fW * fH; i++) {
    ffin >> fr >> fg >> fb;
    bfin >> br >> bg >> bb;

    // Use the specific Project 1 threshold: 
    // Green must be greater than the SUM of Red and Blue
    if (fg > (fr + fb)) {
      // It's a green screen pixel so use background
      fout << br << " " << bg << " " << bb << " ";
    } else {
      // It's a subject pixel so use foreground
      fout << fr << " " << fg << " " << fb << " ";
    }

    if ((i + 1) % fW == 0) {
      fout << endl;
    }
  }

  cout << "Image saved to " << outName << endl;

  ffin.close();
  bfin.close();
  fout.close();

  return 0;
}