/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Lab 7 Part 4
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
  int N, count = 0, points = 0;
  char pos1, pos2;
  cout << "Welcome to SWARE!" << endl;
  cout << "board> ";
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
        points += 3;
        cout << endl;
    }
    else if (command == "reverse") {
        int minIndex = pos1 - 65; 
        int maxIndex = pos2 - 65; 
        int minIndex1 = pos1 - 65; 
        int maxIndex1 = pos2 - 65; 
        int amt;
        if (((maxIndex - minIndex) % 2) == 0) {
            amt = (maxIndex - minIndex)/2;
        }
        else amt = ((maxIndex - minIndex)/2) +1;
        for (int i = 0; i < amt; i++) {
            temp1 = A[minIndex];
            temp2 = A[maxIndex]; 
            A[maxIndex] = temp1;
            A[minIndex] = temp2;
            minIndex++;
            maxIndex--;
        }
        count++;
        points += 2;
    }
    else {
        cout << "Unknown move " << command << endl; 
    }
  }

  print(A, N);
  cout << points << " points!" << "(" << count << " moves)"<< endl;;

    
  
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
    int max = 0;

    char letter = 65;
    for (int i = 0; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    cout << endl;

    for (int j = max; j >= 1; j--) {
        cout << " ";
        for (int k = 0; k < n; k++) {
            if (A[k] >= j) {
                cout << "#" << " ";
            }
            else if (A[k] < j) {
                cout << "  ";
            }
        }
        cout << endl;
        max--;
    }


    for (int j = 0; j < (2*n)+1; j++) {
        cout << "-";
    }
    cout << endl;
   
    for (int m = 0; m < n; m++) {
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