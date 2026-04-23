#include <iostream>
#include <string>
using namespace std; 
#include "fractals.h"

int main()
{
  cout << "size: ";
  int n;
  cin >> n;

  cout << "Width-" << n << " Cantor set:" << endl;
  cantor_row(n);
  cout << endl;

  return 0;
}

