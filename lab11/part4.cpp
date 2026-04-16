/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       part4.cpp
 * Description: Actively filters the list based on the user's accept/reject 
 * choices to build a final sentence and score.
 * Date:        2026-04-13
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "list.h"

using namespace std;

int main() {
    string filename;
    cout << "Input file is: ";
    cin >> filename;
    cout << "\n";

    ifstream fin(filename);
    if (!fin) return 1;

    Node* head = nullptr;
    char p1, p2;
    Pair p;
    
    while (fin >> p1 >> p.word >> p.value >> p2) {
        add2front(head, p);
    }

    Node* curr = head;
    Node* accepted = nullptr; // We use a separate list for accepted words
    
    while (curr != nullptr) {
        cout << "The current node: (" << curr->data.word << " " << curr->data.value << ")\n";
        cout << "Sentence you made so far: ";
        printWords(accepted); // Print words only
        cout << "\n";
        cout << "#words left: " << (countNodes(curr) - 1) << "\n";
        
        cout << "[a]ccept or [r]eject: ";
        char choice;
        cin >> choice;
        cout << "\n";

        // Only add to our new list if they hit 'a'
        if (choice == 'a') {
            add2back(accepted, curr->data);
        }
        curr = curr->next;
    }

    // Print final filtered sentence and score
    cout << "Sentence is: ";
    printWords(accepted);
    cout << "\n";
    cout << "Score is: " << sumValues(accepted) << "\n";

    freeList(head);
    freeList(accepted);
    return 0;
}