//Nathan Lo m283852
//Computing the average and maximum

#include <iostream>
using namespace std;

int main()
{
 
  float int1;
  float totalSum = 0, count = 0, max = 0;
  cout << "Enter numbers separated by spaces and terminated with a negative number." << endl;
  cin >> int1;
  
  //while int1 is greater than 0 keep adding int1 to total sum and count goes up by 1
  while (int1 > 0) {
    if (int1 > max) {
        max = int1;
    }
    totalSum = totalSum + int1;
    cin >> int1;
    count = count + 1;
    
  }
  cout << "The average is " << totalSum/count << endl;
  cout << "The maximum is " << max << endl;
  
  return 0;
}