/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Proj 01 Part 5
 * Description: Places a smaller foreground onto a background at a specific 
 * row and column offset using chroma keying.
 * Date:        2026-02-17
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string fgName, bgName, outName;
    int rs, cs;
    cout << "Foreground file: "; cin >> fgName;
    cout << "Background file: "; cin >> bgName;
    cout << "Row shift: ";       cin >> rs;
    cout << "Column shift: ";    cin >> cs;
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

    // Bounds check
    if (rs + fh > bh || cs + fw > bw || rs < 0 || cs < 0) {
        cout << "Error: The foreground goes past the background" << endl;
        return 1;
    }

    ofstream fout(outName);
    // Write header using background dimensions
    fout << "P3" << endl << bw << " " << bh << endl << bmax << endl;

    

   // Iterate through every row of the background image
    for (int r = 0; r < bh; r++) {
        // Iterate through every column in the current row
        for (int c = 0; c < bw; c++) {
            int br, bg, bb;
            // Always read the background pixel to keep the file pointer in sync
            bfin >> br >> bg >> bb; 

            // Check if the current background coordinate falls within the foreground's offset "box"
            if (r >= rs && r < rs + fh && c >= cs && c < cs + fw) {
                int fr, fg, fb;
                // Read the next foreground pixel only when inside the placement area
                ffin >> fr >> fg >> fb; 

                // Chroma key logic: if foreground is "green enough," replace with background
                if (fg > (fr + fb)) {
                    fout << br << " " << bg << " " << bb << " ";
                } else {
                  
                    fout << fr << " " << fg << " " << fb << " ";
                }
            } else {
                // Outside the foreground area: simply write the background pixel
                fout << br << " " << bg << " " << bb << " ";
            }
        }
        // Move to the next line in the PPM file after completing a full row
        fout << endl;
    }

    cout << "Image saved to " << outName << endl;
    return 0;
}