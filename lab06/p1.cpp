/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Lab 06 Part 1
 * Description: Roll a Dice
 * Date:        2026-02-19
 ******************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

// This function simulates a single roll of a die.
int rolldie();

int main()
{
  int seed;
  cout << "Enter seed value: ";
  cin >> seed;
  srand(seed);


  // ADD CODE HERE 
  for (int i = 0; i < 5; i++) {
    int num1 = rolldie();
    int num2 = rolldie();
    cout << "Player rolled " << num1 << " + " << num2 << " = " << num1 + num2 << endl;
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
