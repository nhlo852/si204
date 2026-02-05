/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Fibonacci Sequence
 * Description: Displays N numbers of the Fibonacci series.
 ******************************************************************************/
#include <iostream>
using namespace std;

int main() {
  int count;
  while (true) {
    cout << "Enter total numbers in the Fibonacci series (0 to exit): ";
    cin >> count;

    if (count == 0) {
      break;
    }
    int num1 = 0;
    int num2 = 1;
    int next;

    cout << "Result: ";

    for (int i = 0; i < count; i++) {
      cout << num1;
      cout << " ";
      next = num1 + num2;
      num1 = num2;
      num2 = next;
    }
    cout << endl;
  }

  cout << "Program terminated." << endl;
  return 0;
}