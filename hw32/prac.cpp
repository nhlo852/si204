/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       prac.cpp
 * Description: Practice program for building a linked list by adding nodes 
 * to the back, printing the list, and safely deleting it.
 * Date:        2026-04-12
 ******************************************************************************/

#include <iostream>

using namespace std;

// ============================================================================
// Struct Definition
// ============================================================================

struct Node {
    int data;
    Node* next;
};

// ============================================================================
// Function Prototypes
// ============================================================================

Node* add2back(int val, Node* L);
void printlist(Node* L);
Node* deletefront(Node* L);
void deletelist(Node* L);

// ============================================================================
// Main Function
// ============================================================================

int main() {
    Node* A = nullptr; // Initialize an empty list
    int n;

    // Get integers from the user and store them in order
    cout << "Enter integers ending with a negative number" << endl;
    while (cin >> n && n >= 0) {
        A = add2back(n, A);
    }

    // Print the final list
    printlist(A);

    // Clean up  memory
    deletelist(A);

    return 0;
}

// ============================================================================
// Function Definitions
// ============================================================================

// Adds a new node with 'val' to the very end of the linked list 'L'
Node* add2back(int val, Node* L) {
    // If the list is empty, create the very first node
    if (L == nullptr) {
        Node* t = new Node;
        t->data = val;
        t->next = nullptr;
        L = t;
    } 
    // Otherwise, find the last node in the chain
    else {
        Node* last = L;
        while (last->next != nullptr) {
            last = last->next;
        }

        // Create the new node and attach it after the last node
        Node* t = new Node;
        t->data = val;
        t->next = nullptr;
        last->next = t;
    }

    // Return the head of the modified list
    return L;
}

// Prints all elements in the linked list separated by spaces
void printlist(Node* L) {
    for (Node* t = L; t != nullptr; t = t->next) {
        cout << t->data << " ";
    }
    cout << endl;
}

// Deletes the very first node of the list and returns the new head
Node* deletefront(Node* L) {
    if (L == nullptr) return nullptr; // Safety check
    
    Node* second = L->next; // Store the 2nd node
    delete L;               // Delete the 1st node
    return second;          // Return the 2nd node to become the new head
}

// Deletes the entire list by repeatedly deleting the front node
void deletelist(Node* L) {
    while (L != nullptr) {
        L = deletefront(L);
    }
}