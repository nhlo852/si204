/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       part3.cpp
 * Description: Same as Part 2, but prints the final list as a sentence of 
 * words only and calculates the total score.
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
    Node* history = nullptr;
    
    while (curr != nullptr) {
        cout << "The current node: (" << curr->data.word << " " << curr->data.value << ")\n";
        cout << "Nodes before the current: ";
        printPairs(history);
        cout << "\n";
        cout << "#nodes after the current: " << (countNodes(curr) - 1) << "\n";
        
        cout << "[a]ccept or [r]eject: ";
        char choice;
        cin >> choice;
        cout << "\n";

        add2back(history, curr->data);
        curr = curr->next;
    }

    // Print ONLY words this time
    cout << "List is: ";
    printWords(head); 
    cout << "\n";
    
    // Print the sum of all values
    cout << "Score is: " << sumValues(head) << "\n";

    freeList(head);
    freeList(history);
    return 0;
}