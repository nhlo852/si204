/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       hw.cpp
 * Description: Reads ints into a linked list until a negative number is 
 * entered, then prints the 3rd-to-last number entered.
 * Date:        2026-04-07
 ******************************************************************************/

#include <iostream>
#include "list.h"

using namespace std;

int main() {
    Node* head = nullptr; // Start with an empty list
    int input;

    // Read integers until a negative number is encountered
    while (cin >> input && input >= 0) {
        add2front(head, input);
    }

    cout << head->next->next->data << endl;

    // Clean up memory
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}