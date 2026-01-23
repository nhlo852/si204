//Nathan Lo m283852
//Computing the average and maximum

#include <iostream>
using namespace std;

int main()
{
 
  float int1;
  float temp;
  cout << "Give a number: ";
  cin >> int1;
  cout << "Multiples of " << int1 << " that are at most 100:" << endl;
  temp = int1;

  while (int1 <= 100) {
    cout << int1 << " ";
    int1 = int1 + temp;

  }
  
  return 0;
}