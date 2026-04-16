/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       hw.cpp
 * Description: Reads words until "END", stores them in a linked list, and 
 * prints all words starting with a specific letter in reverse order.
 * Date:        2026-04-10
 ******************************************************************************/

#include <iostream>
#include <string>
#include "list.h"

using namespace std;

int main() {
    Node* head = nullptr; // Start with an empty list
    string input;

    // Read words until the user types END
    cout << "Enter words followed by END:";
    while (cin >> input && input != "END") {
        add2front(head, input); 
    }

    // Ask the user for a single letter to search for
    char letter;
    cout << "What letter? ";
    cin >> letter;

    // Traverse the list and print words that start with the target letter
    Node* curr = head;
    while (curr) {
        // Make sure the string isn't empty, then check the first character
        if (!curr->word.empty() && curr->word[0] == letter) {
            cout << curr->word << "\n";
        }
        curr = curr->next; // Move to the next node
    }
    freeList(head);

    return 0;
}