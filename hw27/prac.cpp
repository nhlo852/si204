/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       ASCII Art Loader
 * Description: Reads characters (including spaces) from a file to draw a picture.
 * Date:        2026-03-26
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Make a struct box to hold the picture data
struct Pic {
    int rows;
    int cols;
    char** data;
};

// Function prototypes
Pic load(string fname);
void show(Pic p);
void unload(Pic p);

int main(){
  cout << "filename: ";
  string fname;
  cin >> fname;

  Pic p = load(fname);

  string cmd;
  while( cout << "> " && cin >> cmd && cmd != "quit" )
  {
    if( cmd == "show" )
      show(p);
  }

  unload(p);

  return 0;
}

// Read the file and build the 2D character array
Pic load(string fname) {
    Pic p;
    p.rows = 0;
    p.cols = 0;
    p.data = 0;

    ifstream fin(fname);
    
    // Stop if the file doesn't exist
    if (!fin) {
        return p;
    }

    // Get the grid size from the first line
    fin >> p.rows >> p.cols;

    // Make the 2D array
    p.data = new char*[p.rows];
    for (int i = 0; i < p.rows; i++) {
        p.data[i] = new char[p.cols];
    }

    // Skip the invisible "Enter" key press at the end of the first line
    char junk = fin.get();
    while (junk != '\n' && fin) {
        junk = fin.get();
    }

    // Read the actual picture
    for (int i = 0; i < p.rows; i++) {
        for (int j = 0; j < p.cols; j++) {
            // fin.get() gets the exact ASCII character, even spaces!
            p.data[i][j] = fin.get();
        }
        // Throw away the invisible "Enter" key press at the end of each row
        fin.get();
    }

    fin.close();
    return p;
}

// Print the picture to the screen
void show(Pic p) {
    if (p.data == 0) return;

    for (int i = 0; i < p.rows; i++) {
        for (int j = 0; j < p.cols; j++) {
            cout << p.data[i][j];
        }
        cout << endl;
    }
}

// Give the memory back
void unload(Pic p) {
    if (p.data == 0) return;

    for (int i = 0; i < p.rows; i++) {
        delete[] p.data[i];
    }
    delete[] p.data;
}