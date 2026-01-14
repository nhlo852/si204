//Nathan Lo m283852
//Leap Year Detector


#include <iostream>
#include <string> 
using namespace std;

int main()
{
  int year;
  cout << "Enter year: ";
  cin >> year;
  
 if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
        cout << "Is Leap Year" << endl;
      }
      else {
        cout << "Is Not Leap Year" << endl;
      }
    }
    else {
      cout << "Is Leap Year" << endl;
    }
  }
  else {
    cout << "Is Not Leap Year" << endl;
  }



  return 0;
}
