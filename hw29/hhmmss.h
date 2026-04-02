#ifndef HHMMSS_H
#define HHMMSS_H

#include <iostream>
using namespace std;

struct hhmmss
{
  int h, m, s;
};

void read(hhmmss& t, istream& IN);
void write(hhmmss t, ostream& OUT);
bool before(hhmmss a, hhmmss b);

#endif