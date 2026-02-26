/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Practicum 1 Part 2
 * Description: Longest move
 * Date:        2026-02-012
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  string filename;
  char dir, dir1;
  int step, big = 0, x = 0, y = 0;
  cout << "Filename: ";
  cin >> filename;

  ifstream fin(filename);
  if (!fin) { 
    cout << "File not found!" << endl;
    return 1;
  }
  char end;
  fin >> dir >> step;
  while (dir != 'Q') {
    if (dir == 'E') {
        x += step;
        cout << "(" << x << ", " << y << ")" << endl;
        if (step > big) big = step, dir1 = dir;
    }
    if (dir == 'W') {
        x -= step;
        cout << "(" << x << ", " << y << ")" << endl;
        if (step > big) big = step, dir1 = dir;
    }
    if (dir == 'N') {
        y += step;
        cout << "(" << x << ", " << y << ")" << endl;
        if (step > big) big = step, dir1 = dir;
    }
    if (dir == 'S') {
        y -= step;
        cout << "(" << x << ", " << y << ")" << endl;
        if (step > big) big = step, dir1 = dir;
    }
    fin >> dir >> step;
  }
  cout << "The longest move: " << dir1 << big << endl;

  

  return 0;
}