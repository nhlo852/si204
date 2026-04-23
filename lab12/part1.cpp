#include <iostream>
#include <string>
using namespace std;

#include "fractals.h"

int main() {
  cout << "10 X's:"<< endl;
  repeat("X", 10);
  cout << endl;

  string DIAMOND = "\u2bc1";
  cout << "8 diamonds:" << endl;
  repeat(DIAMOND, 8);
  cout << endl;

  string TRIANGLE = "\u25b2";
  cout << "13 triangles:" << endl;
  repeat(TRIANGLE, 13);
  cout << endl;
  return 0;
}

