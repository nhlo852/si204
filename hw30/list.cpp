#include "list.h"

void add2front(Node*& head, int val) {
    // Create a new dynamically allocated node
    Node* temp = new Node;
    temp->data = val;
    
    // Make the new node point to the old front of the list
    temp->next = head;
    
    // Update the head pointer to point to our new node
    head = temp;
}