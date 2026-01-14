//Nathan Lo m283852
//12 Hour Clock to 24 Hour Clock


#include <iostream>
#include <string> 
using namespace std;

int main()
{
  int hour, minutes;
  char junk;
  string timeOfDay;
  cout << "Enter the time: ";
  cin >> hour >> junk >> minutes >> timeOfDay;
  
  if (((hour >= 1) and (hour <= 11)) and (timeOfDay == "PM")) {
    hour = hour + 12;
  }

  if (hour <= 10) {
    cout << 0;
  }

  if ((hour == 12) and timeOfDay == "AM") {
    cout << 0 << 0;
  }
  else {
    cout << hour;
  }

  if (minutes < 10) {
    cout << ":0" << minutes << endl;;
  }
  else {
    cout <<  ":" << minutes << endl;
  }

  return 0;
}

