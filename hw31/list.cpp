/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       list.cpp
 * Description: Implementation of the linked list functions.
 * Date:        2026-04-10
 ******************************************************************************/

#include "list.h"

// Adds a new word to the front of the linked list
void add2front(Node*& head, std::string w) {
    Node* temp = new Node; // Create a new node
    temp->word = w;        // Store the word
    temp->next = head;     // Point the new node to the old front
    head = temp;           // Update head to be the new node
}

// Safely deletes all nodes in the list to prevent memory leaks
void freeList(Node*& head) {
    while (head) {
        Node* temp = head; 
        head = head->next; 
        delete temp;      
    }
}