//Nathan Lo m283852
//Lab03 Part 2


#include <iostream>
#include <string> 
using namespace std;

int main()
{
  char type1, junk, type2;
  int number1, number2;

  cin >> type1 >> number1 >> junk >> type2 >> number2;

  
  if (type1 == 'B') {
    int digit4 = number1 % 10;          
    int digit3 = (number1 / 10) % 10;   
    int digit2 = (number1 / 100) % 10;  
    int digit1 = (number1 / 1000) % 10; 
    int finalSum1 = digit1*8 + digit2*4 + digit3*2 + digit4;

    if (type2 == 'B') {
      int digit8 = number2 % 10;          
      int digit7 = (number2 / 10) % 10;   
      int digit6 = (number2 / 100) % 10;  
      int digit5 = (number2 / 1000) % 10; 
      int finalSum2 = digit5*8 + digit6*4 + digit7*2 + digit8;
      int finalSum3 = finalSum1 + finalSum2;

      if (finalSum3 < 16) {
        int number = finalSum3;
        int num1 = number%2;
        number = number/2;
          
        int num2 = number%2;
        number = number/2;
          
        int num3 = number%2;
        number = number/2;
          
        int num4 = number%2;
        number = number/2;
        cout << "B" << num4 << num3 << num2 << num1 << endl;
      }
      else 
        cout << "D" << finalSum3 << endl;

    }
    else {
      int finalSum3 = number2 + finalSum1;
      if (finalSum3 < 16) {
        int number = finalSum3;
        int num1 = number%2;
        number = number/2;
          
        int num2 = number%2;
        number = number/2;
          
        int num3 = number%2;
        number = number/2;
          
        int num4 = number%2;
        number = number/2;
        cout << "B" << num4 << num3 << num2 << num1 << endl;
      }
      else 
        cout << "D" << finalSum1 + number2 << endl;

    }
    
  }

  if (type1 == 'D') {
    int finalSum1 = number1;
    if (type2 == 'B') {
      int digit4 = number2 % 10;          
      int digit3 = (number2 / 10) % 10;   
      int digit2 = (number2 / 100) % 10;  
      int digit1 = (number2 / 1000) % 10; 
      int finalSum2 = digit1*8 + digit2*4 + digit3*2 + digit4;
      int finalSum3 = finalSum1 + finalSum2;

      if (finalSum3 < 16) {
        int number = finalSum3;
        int num1 = number%2;
        number = number/2;
          
        int num2 = number%2;
        number = number/2;
          
        int num3 = number%2;
        number = number/2;
          
        int num4 = number%2;
        number = number/2;
        cout << "B" << num4 << num3 << num2 << num1 << endl;
      }
      else 
        cout << "D" << finalSum1 + finalSum2 << endl;

    }
    else {
      int finalSum3 = number2 + finalSum1;
      if (finalSum3 < 16) {
        int number = finalSum3;
        int num1 = number%2;
        number = number/2;
          
        int num2 = number%2;
        number = number/2;
          
        int num3 = number%2;
        number = number/2;
          
        int num4 = number%2;
        number = number/2;
        cout << "B" << num4 << num3 << num2 << num1 << endl;
      }
      else 
        cout << "D" << number1 + number2 << endl;

    } 
  }

 
  return 0;
}
