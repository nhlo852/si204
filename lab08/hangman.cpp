/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Lab 8 Part 2
 * Description: Hangman Game
 * Date:        2026-03-05
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// Helper Function Prototypes
void printSpaced(string s);
string mkShadowString(string s);
string uncover(string original, string covered, char c);
string crossOut(char c, string s);

int main()
{
    cout << "Welcome to hangman!" << endl;
    
    int seed;
    cout << "Enter a seed value: ";
    cin >> seed;
    srand(seed);
    int n = rand() % 1466;
    ifstream fin("words07.txt");
    
    if (!fin) {
        cout << "Error: File not found!" << endl;
        return 1;
    }

    string secretWord;
    for (int i = 0; i <= n; i++) {
        fin >> secretWord;
    }
    fin.close();

    int wrongGuesses = 8;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string currentGuess = mkShadowString(secretWord); 
    char guess;

    while (wrongGuesses > 0 && currentGuess != secretWord) {
        cout << "Wrong guesses remaining: " << wrongGuesses << "\t" << alphabet << endl;
        printSpaced(currentGuess);
        cout << endl;
        cout << ": ";
        cin >> guess;
        
        alphabet = crossOut(guess, alphabet);
        string nextGuess = uncover(secretWord, currentGuess, guess);

        if (nextGuess == currentGuess) {
            cout << "There were no " << guess << "'s!" << endl;
            wrongGuesses--;
        } else {
            currentGuess = nextGuess;
        }
    }

    if (currentGuess == secretWord) {
        cout << "You win!!!! The word was " << secretWord << endl;
    } else {
        cout << "You lose!!!! The word was " << secretWord << endl;
    }

    return 0;
}

// ==========================================
// Helper Function Definitions
// ==========================================

void printSpaced(string s) {
    for (int i = 0; i < s.length(); i++) {
        cout << s[i];
        if (i < (int)s.length() - 1) {
            cout << " ";
        }
    }
}

string mkShadowString(string s) {
    string shadow = "";
    for (int i = 0; i < s.length(); i++) {
        shadow += "_";
    }
    return shadow;
}

string uncover(string original, string covered, char c) {
    string result = covered;
    for (int i = 0; i < original.length(); i++) {
        if (original[i] == c) {
            result[i] = c;
        }
    }
    return result;
}

string crossOut(char c, string s) {
    string result = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == c) {
            result += "*";
        }
        else {
            result += s[i];
        }
    }
    return result;
}