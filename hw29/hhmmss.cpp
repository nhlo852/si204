#include "hhmmss.h"

void read(hhmmss& t, istream& IN)
{
  char c;
  IN >> c >> t.h >> c >> t.m >> c >> t.s >> c;
}

void write(hhmmss t, ostream& OUT)
{
  OUT << "[";
  if( t.h < 10 )
    OUT << "0";

  OUT << t.h << ":";

  if( t.m < 10 )
    OUT << "0";

  OUT << t.m << ":";

  if( t.s < 10 )
    OUT << "0";

  OUT << t.s << "]";
}

bool before(hhmmss a, hhmmss b)
{
  int seconds_a = a.h*3600 + a.m*60 + a.s;
  int seconds_b = b.h*3600 + b.m*60 + b.s;
  return seconds_a < seconds_b;
}