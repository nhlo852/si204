//Nathan Lo m283852
//Cesar Shift

#include <iostream>
using namespace std;

int main()
{
  char char1, char2, char3, char4;
  int key;
  cout << "Enter key value: ";
  cin >> key;
  cout << "Enter 4-letter message: ";
  cin >> char1 >> char2 >> char3 >> char4;
  char1 = (char1 - 'a' + key) % 26 + 'a';
  char2 = (char2 - 'a' + key) % 26 + 'a';
  char3 = (char3 - 'a' + key) % 26 + 'a';
  char4 = (char4 - 'a' + key) % 26 + 'a';
  cout << "Encrypted message is: " << char1 << char2 << char3 << char4 <<endl;
  
  return 0;
}