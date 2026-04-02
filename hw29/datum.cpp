#include "datum.h"

void read(datum& d, istream& IN)
{
  char c;
  IN >> c;
  read(d.time, IN);
  IN >> c;
  read(d.position, IN);
  IN >> c;
}

void write(datum d, ostream& OUT)
{
  OUT << "{";
  write(d.time, OUT);
  OUT << ",";
  write(d.position, OUT);
  OUT << "}";
}