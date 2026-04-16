#include <iostream>
#include <string>
using namespace std;

int isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return 1;
    }
    return 0;
}

int main() {
    string* allWords = new string[100];
    string word;
    int count=0, count1 = 0;
    while (cin >> word && word != ";") {
        allWords[count] = word;
        count++;
    }

    int numVowels;
    cin >> numVowels;

    int total = 0;
    for (int i = 0; i < numVowels; i++) {
        cout << i+1 << ": ";
        for (int k = 0; k < count; k++) {
            for (int j = 0; j < allWords[k].length(); j++) {
                total += isVowel(allWords[k][j]);
            }
            if (i + 1 == total) cout << allWords[k] << " ";
            total = 0;
        }

        cout << endl;
    }


    delete[] allWords;

    return 0;
}
