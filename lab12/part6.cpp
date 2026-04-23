// part6.cpp
#include <iostream>
using namespace std;
#include "fractals.h"

int main()
{
  cout << "size: ";
  int n;
  cin >> n;

  cout << "Height-" << n << " Sierpinski triangle:" << endl;
  repeat_triangle_row(n, 0); 

  return 0;
}
