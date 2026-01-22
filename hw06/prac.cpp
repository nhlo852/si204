//Nathan Lo m283852
//Letter Identifier

#include <iostream>
using namespace std;

int main()
{
  char char1;
 
  cout << "Enter a letter: ";
  cin >> char1;
  
  //Identify letters
  if (((char1 >= 65) and (char1 <= 90)) or ((char1 >= 97) and (char1 <= 122))) {
    cout << "Letter" << endl;
  }
  //Not Letter
  else {
    cout << "Not a Letter" <<endl;
  }
  return 0;
}