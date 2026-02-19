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

    // Get file names from user
    cout << "Foreground file: "; cin >> fgName;
    cout << "Background file: "; cin >> bgName;
    cout << "Output file: ";     cin >> outName;

    // Open input files
    ifstream ffin(fgName);
    ifstream bfin(bgName);

    // Check if files exist
    if (!ffin || !bfin) {
        cout << "Error: Input file not found" << endl;
        return 1;
    }

    // Read PPM headers
    string p3;
    int fw, fh, fmax, bw, bh, bmax;
    ffin >> p3 >> fw >> fh >> fmax;
    bfin >> p3 >> bw >> bh >> bmax;

    // Check if images are the same size
    if (fw != bw || fh != bh) {
        cout << "Error: Images have different sizes" << endl;
        return 1;
    }

    // Prepare output file and write header
    ofstream fout(outName);
    fout << "P3" << endl << bw << " " << bh << endl << bmax << endl;

    // Loop through every pixel
    for (int r = 0; r < bh; r++) {
        for (int c = 0; c < bw; c++) {
            int fr, fg, fb, br, bg, bb;
            // Read RGB values
            ffin >> fr >> fg >> fb;
            bfin >> br >> bg >> bb;

            // Only replace if the pixel is EXACTLY Pure Green (0 255 0)
            if (fr == 0 && fg == 255 && fb == 0) {
                fout << br << " " << bg << " " << bb;
            } else {
                fout << fr << " " << fg << " " << fb;
            }

            // Only print space if NOT the last column
            if (c < bw - 1) fout << " ";
        }
        fout << endl; // Newline at end of row
    }

    cout << "Image saved to " << outName << endl;
    
    // Close all files
    ffin.close();
    bfin.close();
    fout.close();
    return 0;
}