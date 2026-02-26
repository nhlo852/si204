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
    
    // Ask user for inputs
    cout << "Foreground file: "; cin >> fgName;
    cout << "Background file: "; cin >> bgName;
    cout << "Row shift: ";       cin >> rs;
    cout << "Column shift: ";    cin >> cs;
    cout << "Output file: ";     cin >> outName;

    // Open the files
    ifstream ffin(fgName);
    ifstream bfin(bgName);

    // Check if files exist
    if (!ffin || !bfin) {
        cout << "Error: Input file not found" << endl;
        return 1;
    }

    // Read the headers
    string p3;
    int fw, fh, fmax, bw, bh, bmax;
    ffin >> p3 >> fw >> fh >> fmax;
    bfin >> p3 >> bw >> bh >> bmax;

    // Check if foreground fits inside background (check both row and column)
    if (rs + fh > bh || cs + fw > bw || rs < 0 || cs < 0) {
        cout << "Error: The foreground goes past the background" << endl;
        return 1;
    }

    // Create output file with background dimensions
    ofstream fout(outName);
    fout << "P3" << endl << bw << " " << bh << endl << bmax << endl;

    // Loop through every pixel in the background
    for (int r = 0; r < bh; r++) {
        for (int c = 0; c < bw; c++) {
            int br, bg, bb;
            bfin >> br >> bg >> bb; // Read background pixel

            // Check if we are inside the foreground box (row and column)
            if (r >= rs && r < rs + fh && c >= cs && c < cs + fw) {
                int fr, fg, fb;
                ffin >> fr >> fg >> fb; // Read foreground pixel

                // If pixel is exactly Pure Green, use background
                if (fr == 0 && fg == 255 && fb == 0) {
                    fout << br << " " << bg << " " << bb;
                } else {
                    fout << fr << " " << fg << " " << fb;
                }
            } else {
                // Outside the foreground box, just use background
                fout << br << " " << bg << " " << bb;
            }
            
            // Add a space between numbers, but not at the end of the line
            if (c < bw - 1) fout << " ";
        }
        fout << endl; // End the row
    }

    cout << "Image saved to " << outName << endl;
    
    ffin.close();
    bfin.close();
    fout.close();
    return 0;
}