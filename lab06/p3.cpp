/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Lab 06 Part 3
 * Description: You're Fired!
 * Date:        2026-02-19
 ******************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

// This function simulates a single roll of a die.
int rolldie();
int throwdice(int set, int count);


int main()
{
  int seed, val, count = 1, setpoint = 0;
  char game, end = 'y';
  cout << "Enter seed value: ";
  cin >> seed;
  srand(seed);
  while (end != 'e') {
    int val = throwdice(setpoint, count);
    if (val == 0) {
        cout << "Player wins!" << endl;
        cout << "Play again? "; cin >> game;
        if (game == 'n') {
            end = 'e';
        }
        else {
            count = 1;
        }
    }

    else if (val == -1) {
        cout << "House wins!" << endl;
        cout << "Play again? "; cin >> game;
        if (game == 'n') {
            end = 'e';
        }
        else {
            count = 1;
        }
    }
    
    else if (count == 1){
        setpoint = val;
        cout << "setpoint is " << val << "!" << endl;
        count++;
    }

    else {
        cout << "roll again" << endl;
        count++;

    }

    }
    return 0;
}

  // ADD CODE HERE 
  



// DEFINE rolldie() HERE
int rolldie() 
{
    int ranNum = 0;
    while (!((ranNum >= 1) && (ranNum <= 6))) {
        ranNum = rand() % 8;
    }
    return ranNum;

}
int throwdice(int set, int count)
{
    int num1 = rolldie();
    int num2 = rolldie();
    int sum;
    sum = num1 + num2;
    cout << "Player rolled " << num1 << " + " << num2 << " = " << sum << " ";
    if (count != 1) {
        if (sum == set) return 0;
        if ((sum == 7) || (sum == 12)) return -1;
        else return sum;
    }
    else {
        if (sum == 7 || sum == 11) return 0;
        if ((sum == 2) || (sum == 3) || (sum == 12)) return -1;
        else return sum;
    }

}

