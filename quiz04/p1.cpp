/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Quiz 4
 * Description: Print average from list
 * Date:        2026-02-28
 ******************************************************************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int avgList(string filename);

int main() {
  string filename;
  cin >> filename;
  cout << avgList(filename) << endl;

  return 0;
}

int avgList(string filename) {
  ifstream fin(filename);
  if (!fin) { 
    cout << "Could not open file '" << filename << "'" << endl;
    return 1;
  }
  int sum = 0, num = 0, input;
  while (fin >> input) {
    sum += input;
    num++;
  }
  return sum/num;

}