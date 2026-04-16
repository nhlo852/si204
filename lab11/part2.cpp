/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       part2.cpp
 * Description: Iterates through the list, showing the history and prompting 
 * the user (but ignoring their input for now).
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
    Node* history = nullptr; // Keeps track of nodes we've passed
    
    while (curr != nullptr) {
        cout << "The current node: (" << curr->data.word << " " << curr->data.value << ")\n";
        cout << "Nodes before the current: ";
        printPairs(history);
        cout << "\n";
        
        // Count nodes remaining (subtract 1 so we don't count the current node)
        cout << "#nodes after the current: " << (countNodes(curr) - 1) << "\n";
        
        cout << "[a]ccept or [r]eject: ";
        char choice;
        cin >> choice; // We read the choice but do nothing with it in Part 2
        cout << "\n";

        // Add the current node to history and move forward
        add2back(history, curr->data);
        curr = curr->next;
    }

    cout << "List is: ";
    printPairs(head);
    cout << "\n";

    freeList(head);
    freeList(history);
    return 0;
}