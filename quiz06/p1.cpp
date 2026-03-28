/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Quiz 6
 * Description: 
 * Date:        2026-02-28
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    int num;
    bool n = false;
    string current, word;
    cin >> num;
    string* list = new string[num];
    for (int i = 0; i < num; i++) {
        cin >> current;
        list[i] = current;
    }
    while (cin >> word && word != "END") {
        for (int i = 0; i < num; i++) {
            if (word != list[i]) {
                n = true;
            }
        }
        for (int i = 0; i < num; i++) {
            if (word == list[i]) {
                for (int j = 0; j < word.length(); j++) {
                    cout << "*";
                }
                n = false;
            }
        
        }
        
        if (n) cout << word;
        cout << " ";
    }
    cout << endl;
    delete [] list;

    return 0;
}