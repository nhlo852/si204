/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Vote Counter
 * Description: Reads candidate names and votes, tallies them using pointers,
 * and displays the winner.
 * Date:        2026-03-05
 ******************************************************************************/

#include <iostream>
#include <string>
using namespace std;


// TO DO: Give function prototypes

void get_names(string* c1, string* c2);
bool update_counts(string sel, string c1, int* count1, string c2, int* count2);
void display_results(string c1, int count1, string c2, int count2);


// *** DON'T CHANGE main()!! ****
int main() 
{
  string candidate1;
  string candidate2;

  get_names(&candidate1, &candidate2);

  int count1 = 0;
  int count2 = 0;

  cout << "Enter votes, ending with \"END\":" << endl;

  string selection;
  cin >> selection;
  while (update_counts(selection, candidate1, &count1, candidate2, &count2)) 
  {
    cin >> selection;
  }

  display_results(candidate1, count1, candidate2, count2);

  return 0;
}

// TO DO: Give function definitions

void get_names(string* c1, string* c2) 
{
    cout << "Candidate names: ";
    // Dereference the pointers to store the inputs directly in main's variables
    cin >> *c1 >> *c2;
}

bool update_counts(string sel, string c1, int* count1, string c2, int* count2) 
{
    // If the sentinel value "END" is read, return false to break the while loop
    if (sel == "END") {
        return false;
    }
    
    // Check for matches and update the counts at the dereferenced memory addresses
    if (sel == c1) {
        *count1 += 1;
    } 
    else if (sel == c2) {
        *count2 += 1;
    } 
    else {
        cout << "Invalid name" << endl;
    }
    
    // Return true to keep the while loop running
    return true;
}

void display_results(string c1, int count1, string c2, int count2) 
{
    int totalVotes = count1 + count2;
    
    if (count1 > count2) {
        cout << c1 << " wins with " << count1 << " of " << totalVotes << " votes" << endl;
    } 
    else if (count2 > count1) {
        cout << c2 << " wins with " << count2 << " of " << totalVotes << " votes" << endl;
    } 
    else {
        cout << "Tie!" << endl;
    }
}