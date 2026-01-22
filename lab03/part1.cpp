//Nathan Lo m283852
//Lab03 Part 1
//Display triangle points and also surrounding box


#include <iostream>
using namespace std;

int main()
{
  float x1, y1, x2, y2, x3, y3; 
  char c1, c2, c3, p1, p2, p3, p4, p5, p6; 
  cin >> p1 >> x1 >> c1 >> y1 >> p2 >> p3 >> x2 >> c2 >> y2 >> p4 >> p5 >> x3 >> c3 >> y3 >> p6;

  // Print Triangle points and close the loop
  cout << x1 << " " << y1 << endl;
  cout << x2 << " " << y2 << endl;
  cout << x3 << " " << y3 << endl;
  cout << x1 << " " << y1 << endl << endl;

  float minX = x1;
  if (x2 < minX) minX = x2;
  if (x3 < minX) minX = x3;
  float maxX = x1;
  if (x2 > maxX) maxX = x2;
  if (x3 > maxX) maxX = x3;

  float minY = y1;
  if (y2 < minY) minY = y2;
  if (y3 < minY) minY = y3;
  float maxY = y1;
  if (y2 > maxY) maxY = y2;
  if (y3 > maxY) maxY = y3;

  //Print box points starting from Bottom-Left
  cout << minX << " " << minY << endl; 
  cout << minX << " " << maxY << endl; 
  cout << maxX << " " << maxY << endl; 
  cout << maxX << " " << minY << endl; 
  cout << minX << " " << minY << endl; 

  return 0;
}