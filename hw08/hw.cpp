//Nathan Lo m283852
//Cookie Jar Tracker

#include <iostream>
using namespace std;

int main()
{
  int jar, eaten, totalEaten = 0, day = 1, piggiest = 0;
  
  cout << "How many cookies? ";
  cin >> jar;
  while (totalEaten < jar) // Loop until the jar is empty
  {
    cout << "Cookies eaten on day " << day << ": ";
    cin >> eaten;

    if (totalEaten + eaten > jar) { // Check if user exceeded the jar capacity
      cout << "Not enough cookies!" << endl;
      return 0; // Exit immediately
    }

    // Trackers
    totalEaten = totalEaten + eaten;
    if (eaten > piggiest) {
      piggiest = eaten;
    }

    day = day + 1;
  }

  // day - 1 because incremented for the next day at the end of loop
  cout << "You ate " << totalEaten << " cookies over " << day - 1 << " days." << endl;
  cout << "On your piggiest day you ate " << piggiest << " cookies." << endl;

  return 0;
}