// Nathan Lo m283852
// Lab04 Part 3
// Add a fout :(

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  string filename, outfile;
  cin >> filename >> outfile;

  ifstream fin(filename);
  ofstream fout(outfile);
  if (!fin) { 
    cout << "Could not open file '" << filename << "'" << endl;
    return 1;
}
  

  // Variables for the header and data
  string h1, h2;
  float year, month, date, hour, min, sec, temp;
  char d1, d2, c1, c2;
  
  // Trackers 
  double sum = 0;
  int count = 0;
  int minDate, minMonth, minYear;
  int maxDate, maxMonth, maxYear; 
  double minTemp, maxTemp;

  fin >> h1 >> h2; //swallow time and temp header
  fout << "day" << '\t' << "hour" << '\t' << "temp" << endl;

  // while the loop reads the pattern
  while (fin >> year >> d1 >> month >> d2 >> date >> hour >> c1 >> min >> c2 >> sec >> temp) {
    double fahr = (1.8 * temp) + 32.0;
    //ts the fout
    string e1 = "", e2 = "";
    if (month < 10) 
        e1 = "0";
    if (date < 10) 
        e2 = "0";
    hour = hour + 1;
    fout << year << "-" << e1 << month << "-" << e2 << date << " " << hour << '\t' << fahr << endl; // fout 
    //fout ends 

    sum = sum + fahr;
    count = count + 1;
    if (count == 1) {
      minTemp = fahr;
      maxTemp = fahr;
      minDate = date;
      maxDate = date;
      minMonth = month;
      minYear = year;
      maxMonth = month;
      maxYear = year;

    } else {
      // Less than
      if (fahr < minTemp) {
        minTemp = fahr;
        minDate = date;
        minMonth = month;
        minYear = year;
      }
      // Greater than
      if (fahr > maxTemp) {
        maxTemp = fahr;
        maxDate = date;
        maxMonth = month;
        maxYear = year;
      }
    } 
  }

  cout << "file: " << filename << endl;

  //Extra 0's case if under 10. Prolly more efficient way to do this but idk
  string e1 = "", e2 = "", e3 = "", e4 = ""; // extra zeroes
  if (minMonth < 10) 
    e1 = "0";
  if (minDate < 10) 
    e2 = "0";
  if (maxMonth < 10) 
    e3 = "0";
  if (maxDate < 10) 
    e4 = "0";
  
  if (count > 0) { //only if file opens
    cout << "ave: " << sum / count << endl;
    cout << "min: " << minTemp << " on " << minYear << "-" << e1 << minMonth << "-" << e2 << minDate << endl;
    cout << "max: " << maxTemp << " on " << maxYear << "-" << e3 << maxMonth << "-" << e4 << maxDate << endl;
    cout << "output in: " << outfile << endl;
  }

  return 0;
}