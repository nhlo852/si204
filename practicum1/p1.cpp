/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Practicum 1 Part 1
 * Description: Percentage or Fraction of People
 * Date:        2026-02-012
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

  float num1, num2, num3;
  char act;
  string junk1, junk2, junk3;

  cin >> num1 >> act;
  if (act == '/') {
    cin >> num2 >> junk1 >> num3 >> junk2, junk3;
    cout << (num1/num2) * num3 << " " << junk2  << endl;
  }
  if (act == '%') {
    cin >> junk1 >> num2 >> junk2 >> junk3;
    cout << 0.01 * num1 * num2 <<  " " << junk2 << endl;
  }

  

  return 0;
}