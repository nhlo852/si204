/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       prac.cpp
 * Description: Recursive linked list functions to add, print, find length, 
 * find the max string, and delete the list.
 * Date:        2026-04-22
 ******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
};

// Function prototypes
Node* add2back(string s, Node* list);
void print(Node* list);
int length(Node* list);
string max(Node* list);
void deletelist(Node* list);

int main() {
    string s;
    Node* L = nullptr;

    // Read words until we see a semicolon
    while (cin >> s && s != ";") {
        L = add2back(s, L);
    }

    // Print the list and its stats
    print(L);
    cout << "length=" << length(L) << endl;
    cout << "max=" << max(L) << endl;

    // Free the memory
    deletelist(L);
    
    return 0;
}

// ============================================================================
// Function Definitions
// ============================================================================

// Adds a string to the back of the list
Node* add2back(string s, Node* list) {
    // If list is empty, make a new node
    if (list == nullptr) {
        Node* temp = new Node;
        temp->data = s;
        temp->next = nullptr;
        return temp;
    }

    // Otherwise, keep going to the end
    list->next = add2back(s, list->next);
    
    return list;
}

// Prints the list separated by spaces
void print(Node* list) {
    // Stop at the end of the list
    if (list == nullptr) {
        cout << endl;
        return;
    }

    // Print current word and move to the next
    cout << list->data << " ";
    print(list->next);
}

// Finds the alphabetically largest string in the list
string max(Node* list) {
    // Return empty string if the list is empty
    if (list == nullptr) {
        return "";
    }

    // Get the max string from the rest of the list (saved in a variable to be faster)
    string subMax = max(list->next);

    // Compare the current word with the biggest word from the rest of the list
    if (list->data > subMax) {
        return list->data;
    } else {
        return subMax;
    }
}

// Calculates the total number of nodes
int length(Node* list) {
    // An empty list has 0 length
    if (list == nullptr) {
        return 0;
    }

    // Current node counts as 1, plus the length of the rest
    return 1 + length(list->next);
}

// Deletes the list to free memory
void deletelist(Node* list) {
    // Stop at the end
    if (list == nullptr) {
        return;
    }

    // Delete the rest of the list first
    deletelist(list->next);
    
    // Then delete the current node
    delete list;
}