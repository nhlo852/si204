/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Lab 06 Part 2
 * Description: Craps
 * Date:        2026-02-19
 ******************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

// This function simulates a single roll of a die.
int rolldie();
int throwdice();

int main()
{
  int seed;
  cout << "Enter seed value: ";
  cin >> seed;
  srand(seed);


  // ADD CODE HERE 
  while (true) {
    int val;
    val = throwdice();
    if (val == 0) {
        cout << "Player wins!" << endl;
        break;
    }
    else if (val == -1) {
        cout << "House wins!" << endl;
        break;

    }
    else cout << "roll again" << endl;
  }
 
  return 0;
}



// DEFINE rolldie() HERE
int rolldie() 
{
    int ranNum = 0;
    while (!((ranNum >= 1) && (ranNum <= 6))) {
        ranNum = rand() % 8;
    }
    return ranNum;

}
int throwdice()
{
    int num1 = rolldie();
    int num2 = rolldie();
    int sum;
    sum = num1 + num2;
    cout << "Player rolled " << num1 << " + " << num2 << " = " << sum << " ";
    if (sum == 7 || sum == 11) return 0;
    if ((sum == 2) || (sum == 3) || (sum == 12)) return -1;
    else return sum;

}

