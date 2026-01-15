//Nathan Lo m283852
//Letter Identifier

#include <iostream>
#include <string>
#include <math>
using namespace std;

int main()
{
  double a ,b;
  string act;
  cout << "Values for a and b?";
  cin >> a >> b;
  cout << "What do you want?";
  cin >> act;

  //Add
  if (act == "add") {
    string junk, who;
    double add; 
    cin >> add >> string >> who;
    //Who we adding to?
    if (who == "a") {
        cout << "a = " << a + sum << " and " << "b = " << b << endl;
    }
    if (who == "b") {
        cout << "a = " <<  << " and " << "b = " << b << endl;
    }
  }
  //Square
  if (act == "square") {
    string who;
    cout << square << who <<endl;
    double square;
    //Who we squaring?
    if (who == "a") {
        cout << "a = " << a*a << " and " << "b = " << b << endl;
    }
    if (who == "b") {
        cout << "a = " << a << " and " << "b = " << b*b << endl;
    }

  }
  return 0;
}