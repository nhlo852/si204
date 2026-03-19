#include <iostream>
#include <fstream>
using namespace std;

// ADD PROTOTYPE HERE


float avg(string filename);

// DO NOT TOUCH THE MAIN FUNCTION
int main()
{
  cout << "Filename: ";
  string fname;
  cin >> fname;

  cout << avg(fname) << endl;
  return 0; 
}

// ADD DEFINITION HERE 


float avg(string filename) {
  ifstream fin(filename);
  float sum = 0, num = 0, input;
  if (!fin) { 
    cout << "Could not open file '" << filename << "'" << endl;
    return 1;
  }
  else {
    while (fin >> input) {
      sum += input;
      num++;
    }
  }
  fin.close();
  return sum/num;

}