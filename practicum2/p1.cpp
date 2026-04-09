#include <iostream>
using namespace std;

void positives(double* A, int n, char c);
void max(double* A, int n, char c);
int readN();
double* readnums(int n, char* c);

int main()
{
  int n = readN();
  char cA, cB;
  double* A = readnums(n, &cA);
  double* B = readnums(n, &cB);

  string cmd;
  while( cout << "> " && cin >> cmd && cmd != "quit" )
  {
    if( cmd == "positives" )
    {
      positives(A, n, cA);
      positives(B, n, cB);
    }
    else if ( cmd == "max" )
    {
      max(A, n, cA);
      max(B, n, cB);
    }
    else
    {
      cout << "invalid command!" << endl;
    }
  }

  delete [] A;
  delete [] B;

  return 0;
}

int readN() {
    int num;
    cin >> num;
    return num;
}

double* readnums(int n, char* c) {
    double num;
    char d, junk;
    cin >> d >> junk;
    *c = d;
    double* A = new double[50];
    for (int i = 0; i < n; i++) {
        cin >> num;
        A[i] = num;
    }
    
    return A;
}

void positives(double* A, int n, char c) {
    cout << c << ": ";
    for (int i = 0; i < n; i++) {
        if (A[i] > 0) cout << A[i];
    }
    cout << endl;
}

void max(double* A, int n, char c) {
    cout << c << ": ";
    double max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) max = A[i];
    }
    cout << max;
    cout << endl;
}