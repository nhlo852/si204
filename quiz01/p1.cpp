//Nathan Lo m283852
//Quiz 01
//Display triangle points and also surrounding box


#include <iostream>
using namespace std;

int main()
{
  int hours1, mins1, hours2, mins2, time1, time2;
  cout << "Enter start time: ";
  cin >> time1;
  hours1 = time1 / 100;
  mins1 = time1 % 100;

  cout << "Enter end time: "; 
  cin >> time2;
  hours2 = time2 / 100;
  mins2 = time2 % 100;

  if (mins2 < mins1) {
    hours2 = hours2 - 1;
    mins2 = mins2 + 60;
  }

  int finalHours = hours2 - hours1;
  int finalMins = mins2 - mins1; 

  cout << "Duration: " << finalHours << " hours " << finalMins << " minutes" << endl;


  return 0;
}