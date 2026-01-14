//Nathan Lo m283852
//Binary to Decimal


#include <iostream>
using namespace std;

int main()
{
  int number;
  cout << "Enter a 4-bit binary number: ";
  cin >> number;
  
  int digit4 = number % 10;          
  int digit3 = (number / 10) % 10;   
  int digit2 = (number / 100) % 10;  
  int digit1 = (number / 1000) % 10; 
  
  
  int finalSum = digit1*8 + digit2*4 + digit3*2 + digit4;
  cout << "In decimal " << digit1 << digit2 << digit3 << digit4 << " = " << finalSum << endl;
  return 0;
}