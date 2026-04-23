/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       hw.cpp
 * Description: Recursive linked list functions. No loops used!
 * Date:        2026-04-22
 ******************************************************************************/

#include "hw.h"
#include <iostream>

using namespace std;

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
    
    // Return the updated list
    return list; 
}

// Prints the list
void print(Node* list) {
    // Stop at the end of the list
    if (list == nullptr) {
        cout << endl;
        return;
    }

    // Print the word
    cout << list->data << " ";
    
    // Print the rest of the list
    print(list->next);
}

// Checks if the list is in alphabetical order
bool inorder(Node* list) {
    // 0 or 1 items are always in order
    if (list == nullptr || list->next == nullptr) {
        return true;
    }

    // If the current word is bigger than the next, it's not in order
    if (list->data > list->next->data) {
        return false;
    }

    // Check the rest of the list
    return inorder(list->next);
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