//Nathan Lo m283852
//Money Converter


#include <iostream>
#include <string> 
using namespace std;

int main()
{
  float money;
  string junk1, junk2;
  cin >> junk1 >> money >> junk2;
  
  if ((junk2 == "Euros") or (junk2 == "euros")) {
    cout << money*1.17 << " Dollars" << endl;  
  }
  
  if ((junk2 == "Pounds") or (junk2 == "pounds")) {
    cout << money*1.36 << " Dollars" << endl; 
  }

  return 0;
}

