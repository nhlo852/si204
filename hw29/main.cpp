/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Roach Tracker (Multi-file)
 * Description: This program reads trial data from a roach experiment, reads 
 * a time from the user, and tells the user where the roach was 
 * going at that point in time using custom libraries.
 * Date:        2026-04-01
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include "point.h"
#include "hhmmss.h"
#include "datum.h"

using namespace std;

int main()
{
  // Open file and read heading info
  ifstream fin("trial.txt");

  int n;
  string s;
  fin >> n >> s >> s;

  datum* A = new datum[n];
  for(int i=0; i<n; i++)
    read(A[i], fin);

  // Get the query time from the user
  hhmmss T;
  cout << "Enter a time: ";
  read(T,cin);

  // Find the first sighting at or after given time
  int k = 0; 
  while (k < n && before(A[k].time,T) )
    k++;
  
  // Write result
  if (k == 0)
  {
    cout << "This was before the first sighting at ";
    write(A[0].position,cout);
    cout << endl;
  }
  else if (k == n)
  {
    cout << "This was after the last sighting at ";
    write(A[n-1].position,cout);
    cout << endl;
  }
  else
  {
    cout << "The roach was somewhere between ";
    write(A[k-1].position,cout);
    cout << " and ";
    write(A[k].position,cout);    
    cout << endl;
  }

  delete [] A;

  return 0;
}