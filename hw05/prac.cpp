//Nathan Lo m283852
//Area of Circle/Triangle


#include <iostream>
#include <string> 
using namespace std;

int main()
{
  float l1, l2;
  string shape;
  cin >> shape;
  
  if ((shape == "Circle") or (shape == "circle")) {
    cin >> l1;
    cout << "Area equals " << 3.14*l1*l1 << endl;  
  }
  
  if ((shape == "Triangle") or (shape == "triangle")) {
    cin >> l1 >> l2;
    cout << "Area equals " << 0.5*l1*l2 << endl;
  }

  return 0;
}

