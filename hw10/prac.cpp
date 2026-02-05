/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Star printer
 * Description: Prints sets of stars with surrounding parenthesis using for loops
 * Date:        2026-02-02
 ******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
  int numSets, starsPerSet;
  cin >> numSets >> starsPerSet;         // read user dimensions

  cout << "[";                           // print opening bracket
  for(int i = 0; i < numSets; i++)       // loop for each group
  {
    cout << "(";                         // start of set
    for(int j = 0; j < starsPerSet; j++) // loop to print stars
      cout << "*";                       // print single star
    cout << ")";                         // end of set
  }
  cout << "]" << endl;                   // print closing bracket

  return 0;
}