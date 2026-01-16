//Nathan Lo m283852
//Add or Square

#include <iostream>
#include <string>

using namespace std;

int main()
{
  double a ,b;
  char comma;
  string act;
  cout << "Values for a and b? ";
  cin >> a >> comma >> b;
  cout << "What do you want? ";
  cin >> act;

  //Add
  if (act == "add") {
    string junk, who;
    double add; 
    cin >> add >> junk >> who;

    //Who we adding to?
    if (who == "a") {
        cout << "a = " << a + add << " and " << "b = " << b << endl;
    }
    if (who == "b") {
        cout << "a = " << a << " and " << "b = " << b + add << endl;
    }
  }
  //Square
  if (act == "square") {
    string who;
    cin >> who;

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