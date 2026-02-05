/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Christmas Tree
 * Description: Prints a Christmas Tree with height that user chooses
 * Date:        2026-02-02
 ******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
  int h;                                 // tree height
  int stars = 1;                         
  cout << "Enter height of tree: ";
  cin >> h;                             

  int spaces = h;                    // leading spaces for top row
  
  for (int i = 1; i <= h; i++) {         // loop for each row
    int count1 = 0, count2 = 0;          
    while (count1 < spaces) {            // print leading spaces
        cout << " ";
        count1++;
    }
    spaces = spaces - 1;                 // decrease spaces for next row

    while (count2 < stars) {             // print stars for current row
        cout << "*";
        count2++;
    } 
    stars = stars + 2;                   // increase stars for next row
    
    cout << endl;                       
  }
  
  return 0;                              
}