// part3.cpp
#include <iostream>
#include <string>
using namespace std; 
#include "fractals.h"

int main()
{
  cantor_row(1,1); 
  cout << endl << endl << endl;
 
  cantor_row(3,1); 
  cout << endl; 
  cantor_row(3,3);
  cout << endl << endl << endl;
  
  cantor_row(9,1);
  cout << endl; 
  cantor_row(9,3);
  cout << endl; 
  cantor_row(9,9);
  cout << endl << endl << endl;

  cantor_row(27,1);
  cout << endl;
  cantor_row(27,3);
  cout << endl;
  cantor_row(27,9);
  cout << endl;
  cantor_row(27,27);
  cout << endl;

  return 0;
}