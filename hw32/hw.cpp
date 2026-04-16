/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       hw.cpp
 * Description: Main program that reads ints into a linked list and processes 
 * commands to manipulate and print the list.
 * Date:        2026-04-12
 ******************************************************************************/

#include <iostream>
#include <string>
#include "ll.h"

using namespace std;

int main()
{
  Node* L = NULL;

  // read the numbers into list L
  int d;
  while( cin >> d && d > 0)
    L = add2back(d, L);

  // handle the commands
  string cmd;
  while( cout << "> " && cin >> cmd && cmd != "quit" )
  {
    if( cmd == "enter" )
    {
      // enter d after x
      string s;
      int x;
      cin >> d >> s >> x;
      enter_after(d, x, L); 
    }
    else if ( cmd == "remove" )
    {
      // remove after d
      string s;
      cin >> s >> d;
      remove_after(d, L); 
    }
    else if ( cmd == "print" )
    {
      // print L
      print(L);
    }
    else if ( cmd == "sum" )
    {
      cout << sum(L) << endl;
    } 
  }

  // delete the list 
  deletelist(L);
  return 0;
}