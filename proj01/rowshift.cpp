/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Proj 01 Part 4
 * Description: Shifts the foreground image vertically by rs rows.
 * Date:        2026-02-17
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  string fgName, bgName, outName;
  int rs;
  
  cout << "Foreground file: "; cin >> fgName;
  cout << "Background file: "; cin >> bgName;
  cout << "Row shift: ";       cin >> rs;
  cout << "Output file: ";     cin >> outName;

  ifstream ffin(fgName);
  ifstream bfin(bgName);

  if (!ffin || !bfin) {
    cout << "Error: Input file not found" << endl;
    return 1;
  }

  string p3;
  int fw, fh, fmax, bw, bh, bmax;
  ffin >> p3 >> fw >> fh >> fmax;
  bfin >> p3 >> bw >> bh >> bmax;

  // Requirement: Check if the foreground goes past the background
  if (rs + fh > bh) {
    cout << "Error: The foreground goes past the background" << endl;
    return 1;
  }

  ofstream fout(outName);
  fout << "P3" << endl << bw << " " << bh << endl << bmax << endl;

  

  for (int r = 0; r < bh; r++) {
    for (int c = 0; c < bw; c++) {
      int br, bg, bb;
      bfin >> br >> bg >> bb; 

      // Row shift logic: Only process foreground if within row range and width bounds
      if (r >= rs && r < rs + fh && c < fw) {
        int fr, fg, fb;
        ffin >> fr >> fg >> fb; 

        // Correct threshold to match test cases (r127 g127 b127 should stay)
        if (fg > (fr + fb)) {
          fout << br << " " << bg << " " << bb << " ";
        } else {
          fout << fr << " " << fg << " " << fb << " ";
        }
      } else {
        // Area outside the foreground (including the ??? dot area)
        fout << br << " " << bg << " " << bb << " ";
      }
    }
    fout << endl;
  }

  cout << "Image saved to " << outName << endl;
  
  ffin.close();
  bfin.close();
  fout.close();

  return 0;
}