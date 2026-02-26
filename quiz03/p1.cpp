/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Quiz 3
 * Description: Navy or Army win? + score
 * Date:        2026-02-05
 *****************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename;
    cin >> filename;
    ifstream fin(filename);

    // check if input file opened successfully
    if (!fin) {
        cout << "File not found!" << endl;
        return 1;
    }

    string junk1, junk2;
    int num1, num2, highScore = 0, tot = 0;

    fin >> junk1 >> junk2; 

    while (fin >> num1 >> num2) {
        if (num1 > num2) {
            tot++;
        }
        if (num1 > highScore) {
            highScore = num1;
        }
    }
    cout << "Navy won " << tot << " times" << endl;
    cout << "The highest Navy score is " << highScore << endl;
    fin.close();

    return 0;
}