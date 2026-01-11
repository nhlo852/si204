#include <iostream>
using namespace std;

int main()
{
  // Take inputs
  int feet1, feet2;
  int inches1, inches2;
  char junk;
  cout << "Enter two lengths in feet and inches (larger first!)"<<endl;
  cin >> feet1 >> junk;
  cin >> inches1 >> junk >> junk;
  cin >> feet2 >> junk; 
  cin >> inches2 >> junk >> junk;

  // Convert feet to inches
  int totalInches1 = (feet1 * 12) + inches1;
  int totalInches2 = (feet2 * 12) + inches2;

  //Subtract and convert back
  int totalInches3 = totalInches1 - totalInches2;
  int finalFeet = totalInches3/12;
  int finalInches = totalInches3%12;

  
  cout << "Difference is "<< finalFeet <<"' "<<finalInches<<"''"<<endl;
  
  
  return 0;
}