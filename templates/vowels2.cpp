/******************************************************************************
 * Title:       File Vowel Counter
 * Description: Reads a text file, determines the word count, dynamically 
 * allocates an array to store the words, and counts the total vowels.
 ******************************************************************************/

#include <iostream>
#include <fstream>
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
    string filename;
    cout << "Enter the name of the text file (e.g., words.txt): ";
    cin >> filename;

    // 1. Open the file
    ifstream fin(filename);
    if (!fin) {
        cout << "Error: File '" << filename << "' not found!" << endl;
        return 1; // Exit program if file doesn't exist
    }

    // 2. PASS ONE: Count how many words are in the file
    int numWords = 0;
    string tempWord;
    while (fin >> tempWord) {
        numWords++;
    }

    // 3. Rewind the file back to the very beginning!
    fin.clear();             // Clears the "End of File" flag
    fin.seekg(0, ios::beg);  // Moves the reading cursor back to byte 0 (beginning)

    // 4. Dynamically allocate the array now that we know the exact size
    string* words = new string[numWords];

    // 5. PASS TWO: Actually store the words into the array
    for (int i = 0; i < numWords; i++) {
        fin >> words[i];
    }

    fin.close(); // Good practice to close the file when done with it

    // 6. Nested loops to count the vowels
    int totalVowels = 0;
    
    for (int i = 0; i < numWords; i++) {
        // words[i] is the current string
        for (int j = 0; j < (int)words[i].length(); j++) {
            
            // words[i][j] grabs the exact character at index j inside the string at index i
            if (isVowel(words[i][j])) {
                totalVowels++;
            }
        }
    }

    // 7. Print the final results
    cout << "Successfully read " << numWords << " words from the file." << endl;
    cout << "Total number of vowels: " << totalVowels << endl;

    // 8. Give the memory back
    delete[] words;

    return 0;
}