//Nathan Lo m283852
//Upper to Lowercase

#include <iostream>
using namespace std;

int main()
{
  char char1, char2, char3;
  cout << "Input a 3-letter word in uppercase letters: ";
  cin >> char1 >> char2 >> char3;
  char1 = char1 + 32;
  char2 = char2 + 32;
  char3 = char3 + 32;
  cout << "Output: " << char1 << char2 << char3 <<endl;
  
  return 0;
}