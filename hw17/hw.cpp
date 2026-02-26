/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Forwards and Backwards
 * Description: User submits sentence of n length and the sentence is outputted 
 * forwards and backwards
 * Date:        2026-02-22
 ******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num;
    string str;
    cout << "Number of words: "; cin >> num;
    string* s1 = new string[num];
    cout << "Sentence: "; 
    
    // Store each word into the array
    for (int i = 0; i < num; i++) {
        cin >> str;
        s1[i] = str;
    }
    
    // Print the sentence forwards
    for (int j = 0; j < num; j++) {
        if (j == (num-1)) {
            cout << s1[j]; // Print last word without a trailing space
        }
        else cout << s1[j] << " ";
    }
    
    cout << "?";
    for (int k = num - 1; k >= 0; k--) {
        if (k == 0) {
            cout << s1[k]; // Print first word without a trailing space
        }
        else cout << s1[k] << " ";
    }
    
    cout << "!" << endl;
    
    //free allocated memory
    delete[] s1;
    
    return 0;
}