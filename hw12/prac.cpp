/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Checking Rows for Y
 * Description: Checks a file and outputs the amount of rows with Y
 * Date:        2026-02-04
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  string filename;
  cin >> filename;

  ifstream fin(filename);
  if (!fin) { 
    return 1;
  }

  int row, column, tot = 0; 
  char junk, val;
  bool isY = false;

  // swallow x
  fin >> row >> junk >> column;

  for (int i = 0; i < row; i++) {   //iterate through each row     
    for (int j = 0; j < column; j++) { //iterate through each column      
       fin >> val; 
       if (val == 'Y') {
        isY = true;
       }              
    }
    if (isY) {
        tot++;
    }
    isY = false; // Reset for the next row
  }
  fin.close(); 
  cout << tot << endl;
  
  return 0;
}