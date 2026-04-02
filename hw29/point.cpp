#include "point.h"

void read(point& p, istream& IN)
{
  char c;
  IN >> c >> p.x >> c >> p.y >> c;
}

void write(point p, ostream& OUT)
{
  OUT << "(" << p.x << "," << p.y << ")";
}