#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

struct point
{
  double x, y;
};

void read(point& p, istream& IN);
void write(point p, ostream& OUT);

#endif