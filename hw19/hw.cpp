/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Array Visualization and Swapping
 * Description: Reads N integers, visualizes them as histograms, and 
 * allows index swapping.
 * Date:        2026-02-23
 ******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

// ======================================
// Function prototypes below
// ======================================

int readN();
int* readData(int n);
void show(int* A, int n);  
void swap(int* A, int n);  
// main function
// TOUCH NOTHING INSIDE THE FUNCTION!!
// ======================================
int main()
{
  int n = readN();
  int* A = readData(n);

  string cmd;
  cout << "cmd: ";
  while( (cin >> cmd) && cmd != "quit" ) 
  {
    if( cmd == "show" )
      show(A, n);
    else if ( cmd == "swap" )
      swap(A, n);

    cout << "cmd: ";
  }

  delete[] A;

  return 0;
}

// ======================================
// Function definitions below
// ======================================

int readN()
{
   int num;
   char junk1, junk2;
   // Reads "N = " then the integer
   cin >> junk1 >> junk2 >> num;
   return num;
}

int* readData(int n)
{
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return a;
}

void show(int* A, int n)
{
    for (int i = 0; i < n; i++) {
        cout << "[" << i << "] ";
        // Print '*' characters 
        for (int j = 0; j < A[i]; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void swap(int* A, int n)
{
    int i, j;
    cin >> i >> j;
    // Boundary check to ensure indices are actually valid
    if (i >= 0 && i < n && j >= 0 && j < n) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}