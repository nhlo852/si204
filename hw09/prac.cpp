/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Simple Data Bucketing 
 * Description: Takes input file and puts odd numbers in odd doc and even numbers in even doc
 * Date:        2026-01-30
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
 cout << "Filename? ";
 string fname;
 cin >> fname; 
 ifstream fin(fname);

  // check if file exists
  if(!fin)
  {
    cout << "File doesn't exist!" << endl;
    return 1;
  }
 
 int input;
 ofstream feven("even.txt"); //make even text
 ofstream fodd("odd.txt"); //make odd text 
 while (fin >> input) {
    if(input % 2 == 0 ) //if even add to even doc if odd add to odd doc
      feven << input << " ";
    else
      fodd << input << " ";
  
 }
 
 return 0;
}