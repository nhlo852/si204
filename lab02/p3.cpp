//Nathan Lo m283852
//Chmod Triple Review


#include <iostream>
using namespace std;

int main()
{
  int number;
  cout << "Permissions: ";
  cin >> number;
  cout << '\n';

  //User
  int num1 = (number/100)%10;
  cout << "User: " << endl;
  cout << "read " << (num1/4)%2 << '\n' << "write " << (num1/2)%2 << '\n' << "execute "<< num1%2 << '\n' << endl;
  
  //Group
  int num2 = (number/10)%10;
  cout << "Group: " << endl;
  cout << "read " << (num2/4)%2 << '\n' << "write " << (num2/2)%2 << '\n' << "execute "<< num2%2 << '\n' << endl;

  //Other
  int num3 = number%10;
  cout << "Other: " << endl;
  cout << "read " << (num3/4)%2 << '\n' << "write " << (num3/2)%2 << '\n' << "execute "<< num3%2 << endl;
  
  return 0;
}