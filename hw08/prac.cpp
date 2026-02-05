//Nathan Lo m283852
//Simple Calculator

#include <iostream>
using namespace std;

int main()
{
  cout << "Enter an expression: ";
  int total, input;
  char op;
  total = 0;
  op = '+';

  while(op != '=')
  {
    cin >> input; // add or subtract value from total
    if (op == '+')
      total = total + input;
    else
      total = total - input;
    cin >> op;
  }
  cout << total << endl; // Print result

  return 0;
}