/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       
 * Description: 
 * Date:        2026-02-02
 ******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
  int height, width, offset;          // Initialize Inputs                                             
  cout << "Enter height (greater than 2): ";
  cin >> height;
  cout << "Enter width (greater than 2): ";
  cin >> width;
  cout << "Enter offset: ";
  cin >> offset;                                               // leading spaces for top row
  
  
  for (int i = 0; i < height; i++) {         // loop for each row
    int spaces = 0;
    int spaces1 = 0;
    while (spaces < offset) {
        cout << " ";
    }
    for (int j = 2; j < width; j++) {
        cout << "*";
        while (spaces)




    }      
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