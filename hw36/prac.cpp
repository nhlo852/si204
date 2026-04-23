/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       prac.cpp
 * Description: Recursive linked list functions to search for a word by its 
 * first letter and remove a specific word from the list.
 * Date:        2026-04-22
 ******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

// Struct definition
struct Node {
    string data;
    Node* next;
};

// Function prototypes
Node* add2back(string s, Node* list);
void print(Node* list);
void deletelist(Node* list);
Node* search(char c, Node* list);
Node* remove(string s, Node* list);

int main() {
    string s;
    Node* L = nullptr;

    // Read words until a semicolon
    while (cin >> s && s != ";") {
        L = add2back(s, L);
    }
    print(L);

    string cmd;
    while (cout << "> " && cin >> cmd && cmd != "quit") {
        if (cmd == "remove") {
            string word;
            cin >> word;
            L = remove(word, L);
            print(L);
        }
        else if (cmd == "search") {
            char c;
            cin >> c;
            Node* p = search(c, L);

            if (p != nullptr)
                cout << "Yes: " << p->data << endl;
            else
                cout << "No" << endl;
        }
    }

    deletelist(L);
    return 0;
}

// Recursively searches for the first node starting with character 'c'
Node* search(char c, Node* list) {
    // Base Case 1: Reached the end of the list, letter not found
    if (list == nullptr) {
        return nullptr;
    }

    // Base Case 2: The first letter of the current word matches 'c'
    if (list->data[0] == c) {
        return list; 
    }

    // Recursive Step: Check the rest of the list
    return search(c, list->next);
}

// Recursively removes the first occurrence of string 's'
Node* remove(string s, Node* list) {
    // Base Case 1: Reached the end of the list, word not found
    if (list == nullptr) {
        return nullptr;
    }

    // Base Case 2: We found the word!
    if (list->data == s) {
        Node* newHead = list->next; // Save the rest of the chain
        delete list;                // Delete the target node
        return newHead;             // Return the rest of the chain to patch the gap
    }

    // Recursive Step: Keep searching and patch up the links on the way back
    list->next = remove(s, list->next);
    
    return list;
}

Node* add2back(string s, Node* list) {
    if (list == nullptr) {
        Node* temp = new Node;
        temp->data = s;
        temp->next = nullptr;
        return temp;
    }
    list->next = add2back(s, list->next);
    return list;
}

void print(Node* list) {
    if (list == nullptr) {
        cout << endl;
        return;
    }
    cout << list->data << " ";
    print(list->next);
}

void deletelist(Node* list) {
    if (list == nullptr) {
        return;
    }
    deletelist(list->next);
    delete list;
}