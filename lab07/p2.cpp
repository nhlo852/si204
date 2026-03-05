/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Lab 7 Part 2
 * Description: SWARE
 * Date:        2026-02-24
 ******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int* read(int n);
void print(int* A, int n);
bool isInOrder(int* A, int n);

int main() {
  char c;
  int N, count = 0;
  char pos1, pos2;
  cout << "Welcome to SWARE!" << endl;
  cout << "board> " << endl;
  cin >> c >> c >> N >> c;

  int* A = read(N);
  while (!isInOrder(A, N)) {
    string command;
    int temp1, temp2;
    print(A,N);
    cout << "> "; cin >> command >> pos1 >> pos2;
    if (command == "swap") {
        temp1 = A[pos1-65];
        temp2 = A[pos2-65];
        A[pos1-65] = temp2;
        A[pos2-65] = temp1;
        count++;
        cout << endl;
    }
    else {
        cout << "Unknown move " << command << endl; 
    }
  }
  print(A, N);
  cout << count*3 << " points!" << "(" << count << " moves)"<< endl;;

    
  
  delete [] A;
  return 0;
}

// Function to read integers from user
int* read(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    return arr;
}

// Function to print out array with ABCD at bototm
void print(int* A, int n) {
    char letter = 65;
    for (int i = 0; i < n; i++) {
        cout << " " << A[i];
    }
    cout << endl;
    for (int j = 0; j < (2*n)+1; j++) {
        cout << "-";
    }
    cout << endl;
   
    for (int k = 0; k < n; k++) {
        cout << " " << letter;
        letter++;
    }
    cout << endl;
}

bool isInOrder(int* A, int n) {
    bool order = true;
    for (int i = 0; i < n-1; i++) {
      if (A[i] > A[i+1]) {
        order = false;
      }
    }
    return order;
}