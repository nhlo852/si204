//Nathan Lo m283852
//Decimal to Binary


#include <iostream>
using namespace std;

int main()
{
  int number;
  cout << "Enter a number between 0 and 15: ";
  cin >> number;
  int inputNum = number;

  int num1 = number%2;
  number = number/2;

  int num2 = number%2;
  number = number/2;

  int num3 = number%2;
  number = number/2;

  int num4 = number%2;
  number = number/2;
 
  cout << inputNum << " in binary is " << num4 << num3 << num2 << num1 << endl;
  return 0;
}