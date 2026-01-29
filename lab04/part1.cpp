// Nathan Lo m283852
// Lab04 Part 1
// Average of Temps

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  string filename;
  cin >> filename;

  ifstream fin(filename);
  if (!fin) { //had to lowk search this part up
    cout << "Could not open file '" << filename << "'" << endl;
    return 1;
}

  // Variables for the header and data
  string h1, h2;
  float year, month, date, hour, min, sec, temp;
  char d1, d2, c1, c2;
  
  // Trackers for the average
  double sum = 0;
  int count = 0;

  fin >> h1 >> h2;

  // while the loop reads the pattern
  while (fin >> year >> d1 >> month >> d2 >> date >> hour >> c1 >> min >> c2 >> sec >> temp) {
    double fahr = (1.8 * temp) + 32.0;
    sum = sum + fahr;
    count = count + 1;
  }

  cout << "file: " << filename << endl;
  
  if (count > 0) {
    cout << "ave: " << sum / count << endl;
  }

  return 0;
}