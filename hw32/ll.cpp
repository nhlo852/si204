/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       11.cpp
 * Description: Implementation of the linked list operations.
 * Date:        2026-04-12
 ******************************************************************************/

#include "ll.h"
#include <iostream>

using namespace std;

// Adds a new node to the end of the list and returns the head
Node* add2back(int d, Node* L) {
    Node* temp = new Node;
    temp->data = d;
    temp->next = nullptr;

    // If the list is empty, the new node becomes the head
    if (L == nullptr) {
        return temp;
    }
    // Otherwise, traverse to the very end and attach it
    Node* curr = L;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = temp;

    return L;
}

// Inserts a new value 'd' immediately after the first occurrence of 'x'
void enter_after(int d, int x, Node* L) {
    Node* curr = L;
    
    while (curr != nullptr) {
        // Once we find the target:
        if (curr->data == x) {
            Node* temp = new Node; // Create the new node
            temp->data = d;
            
            // Link it into the chain
            temp->next = curr->next;
            curr->next = temp;
            return; // Stop searching after the first occurrence
        }
        curr = curr->next;
    }
}

// Removes the node immediately following the first occurrence of 'target'
void remove_after(int target, Node* L) {
    Node* curr = L;
    
    while (curr != nullptr) {
        // Once we find the target:
        if (curr->data == target) {
            // Make sure there is actually a node AFTER the target to delete
            if (curr->next != nullptr) {
                Node* temp = curr->next; // Save the node to delete
                curr->next = temp->next; // Route around it
                delete temp;             // Free the memory
            }
            return; // Stop searching after the first occurrence
        }
        curr = curr->next;
    }
}

// Prints the list separated by spaces (without a trailing space at the end)
void print(Node* L) {
    Node* curr = L;
    while (curr != nullptr) {
        cout << curr->data;
        if (curr->next != nullptr) {
            cout << " ";
        }
        curr = curr->next;
    }
    cout << endl;
}

// Calculates and returns the sum of all elements in the list
int sum(Node* L) {
    int total = 0;
    Node* curr = L;
    while (curr != nullptr) {
        total += curr->data;
        curr = curr->next;
    }
    return total;
}

// Deletes the entire list to prevent memory leaks
void deletelist(Node* L) {
    while (L != nullptr) {
        Node* temp = L;
        L = L->next;
        delete temp;
    }
}