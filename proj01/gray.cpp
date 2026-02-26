/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Proj 01 Part 2
 * Description: Turns image to grayscale by averaging RGB.
 * Date:        2026-02-08
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string inName, outName;
    cout << "Input file: ";
    cin >> inName;
    cout << "Output file: ";
    cin >> outName;

    // Open and validate file
    ifstream fin(inName);
    if (!fin) {
        cout << "Error: Input file not found" << endl;
        return 1;
    }

    ofstream fout(outName);

    // Read header
    string header;
    int width, height, maxVal;
    fin >> header >> width >> height >> maxVal;

    // Transfer header to output file
    fout << header << endl;
    fout << width << " " << height << endl;
    fout << maxVal << endl;

    int r, g, b, gray;
    for (int i = 0; i < width * height; i++) {
        // Read the original color triplet
        fin >> r >> g >> b;

        // Calculate the average
        gray = (r + g + b) / 3;
        
        // Replace RGB values with grayscale
        fout << gray << " " << gray << " " << gray << " ";

    }

    cout << "Image saved to " << outName << endl;

    fin.close();
    fout.close();

    return 0;
}