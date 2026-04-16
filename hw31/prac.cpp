/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       prac.cpp
 * Description: Practice program for searching and deleting in a linked list.
 * Date:        2026-04-10
 ******************************************************************************/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// 1. Define the Node struct first
struct Node {
    double data;
    Node* next;
};

// 2. Function Prototypes
Node* add2front(double value, Node* L);
Node* search(double value, Node* L);
Node* deletefront(Node* L);
void deletelist(Node* L);

// 3. Main Function
int main() {
    Node* L = NULL;
    double x;
    char c;

    // Read and store numbers
    while (cin >> x >> c) {
        L = add2front(x, L);
        if (c == ';') break;
    }

    // Process search commands
    string comm;
    while (cin >> comm && comm == "search" && cin >> x) {
        Node* p = search(x, L);
        if (p != NULL) {
            cout << "Found:" << p->data << endl; 
        } else {
            cout << "Not Found!" << endl;
        }
    }

    // Delete the list to prevent memory leaks
    deletelist(L);

    return 0;
}

// ============================================================================
// Helper Functions
// ============================================================================

// Adds a new node to the front of the list
Node* add2front(double value, Node* L) {
    Node* temp = new Node;
    temp->data = value;
    temp->next = L;
    return temp;
}

// Searches the linked list for a specific value (within 1.0 difference)
Node* search(double value, Node* L) {
    while (L != NULL) {
        if (abs(L->data - value) < 1.0) {
            return L; // Match found
        }
        L = L->next;
    }
    return NULL; // No match found
}

// Deletes the front node and returns the new head of the list
Node* deletefront(Node* L) {
    if (L == NULL) return NULL;
    
    Node* second = L->next; // Store the 2nd node
    delete L;               // Delete the front node
    return second;          // Return the 2nd node so it becomes the new head
}

// Keeps deleting the front node until the list is empty
void deletelist(Node* L) {
    while (L != NULL) {
        L = deletefront(L);
    }
}