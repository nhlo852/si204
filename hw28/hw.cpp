/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       DivBox Webpage Generator
 * Description: Reads rectangle data from a file and outputs HTML code to 
 * draw colored boxes.
 * Date:        2026-03-28
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

//-- DEFININING POINT ---//
struct Point
{
  double x, y;
};

//-- DEFININING RECTANGLE ---//
struct Rectangle
{
  Point lowerLeft;
  double width, height;
};

//-- DEFININING COLOR ---//
struct Color
{
  int r, g, b;
};

//-- DEFININING DIVBOX ---//
struct DivBox
{
  Rectangle R;
  Color C;
  bool filled;
};

void read(istream& in, DivBox &DB);
void write(ostream &out, DivBox A);

//---------- MAIN -----------//
int main()
{
  cout << "Input filename: ";
  string ifn;
  cin >> ifn;
  ifstream fin(ifn);
  if (!fin)
  {
    cout << "File '" << ifn << "' not found!" << endl;
    return 1;
  }

  cout << "Output filename: ";
  string ofn;
  cin >> ofn;
  ofstream fout(ofn);
  fout << "<html><head></head><body>" << endl;
  string comm;
  while(fin >> comm && comm != "quit")
  {
    DivBox A;
    read(fin,A);
    write(fout,A);
  }
  fout << "</body></html>" << endl;  
  cout << "Output in file " << ofn << endl;
  return 0;
}

//---------- FUNCTION DEFINITIONS -----------//
void read(istream& in, DivBox &DB)
{
  char junk;
  string fillStatus;

  // Read the point: (x,y)
  in >> junk >> DB.R.lowerLeft.x >> junk >> DB.R.lowerLeft.y >> junk;

  // Read the rectangle dimensions: widthxheight
  in >> DB.R.width >> junk >> DB.R.height;

  // Read the color: r,g,b
  in >> DB.C.r >> junk >> DB.C.g >> junk >> DB.C.b;

  // Read the word at the end: "filled" or "hollow"
  in >> fillStatus;
  
  if (fillStatus == "filled") {
      DB.filled = true;
  } else {
      DB.filled = false;
  }
}

// PLEASE DON'T LOOK AT THIS!  USE YOUR OWN UNDERSTANDING TO FIGURE OUT YOUR PART
void write(ostream &out, DivBox A)
{
  out << "<div style=\"position: fixed; border-style: solid; border-width: 2pt;"; 
  out << "left: " << A.R.lowerLeft.x << "pt; ";
  out << "top: " << A.R.lowerLeft.y - A.R.height << "pt; ";
  out << "height: " << A.R.height << "pt; ";
  out << "width: " << A.R.width << "pt; ";
  out << "color: rgb(" << A.C.r << "," << A.C.g << "," << A.C.b << "); "; 

  if (A.filled) 
      out << "background-color: rgb(" << A.C.r << "," << A.C.g << "," << A.C.b << "); ";

  out << "\"></div>" << endl;
}