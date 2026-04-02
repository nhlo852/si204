#ifndef DATUM_H
#define DATUM_H

#include <iostream>
#include "hhmmss.h"
#include "point.h"
using namespace std;

struct datum
{
  hhmmss time;
  point position;
};

void read(datum& d, istream& IN);
void write(datum d, ostream& OUT);

#endif