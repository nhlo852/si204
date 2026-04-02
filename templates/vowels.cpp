/******************************************************************************
 * Title:       Vowel Counter
 * Description: Reads a list of words into a dynamically allocated string array 
 * and counts the total number of vowels across all words.
 ******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

// Helper function to check if a single character is a vowel
bool isVowel(char c) {
    // Check both lowercase and uppercase vowels
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return true;
    }
    return false;
}

int main() {
    int numWords;
    
    // 1. Ask the user how many words they are going to type
    cout << "How many words will you enter? ";
    cin >> numWords;

    // 2. Dynamically allocate an array of strings
    string* words = new string[numWords];

    // 3. Read the words into the array
    cout << "Enter the words: " << endl;
    for (int i = 0; i < numWords; i++) {
        cin >> words[i];
    }

    int totalVowels = 0;

    // 4. Nested loops to check every letter of every word
    for (int i = 0; i < numWords; i++) {
        
        // words[i] is the current string
        // words[i].length() tells us how many characters are in that specific string
        for (int j = 0; j < (int)words[i].length(); j++) {
            
            // words[i][j] grabs the exact character at index j inside the string at index i
            if (isVowel(words[i][j])) {
                totalVowels++;
            }
        }
    }

    // 5. Print the final count
    cout << "Total number of vowels: " << totalVowels << endl;

    // 6. Give the memory back
    delete[] words;

    return 0;
}


