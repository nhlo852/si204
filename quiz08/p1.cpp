/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       p1.cpp
 * Description: Program that reads characters and integers into a linked list
 * and processes commands to modify and search the list.
 * Date:        2026-04-16
 ******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

struct Node {
    char label;
    int value;
    Node* next;
};

void add2front(Node*& head, char l, int v) {
    Node* temp = new Node;
    temp->label = l;
    temp->value = v;
    temp->next = head;
    head = temp;
}

int main() {
    Node* head = nullptr;
    char l;
    int v;
    while (cin >> l >> v && l != '$') {
        add2front(head, l, v);
    }

    string cmd;
    while (cin >> cmd && cmd != "quit") {
        if (cmd == "more_than") {
            int threshold;
            cin >> threshold;
            while (curr != nullptr) {
                if (curr->value > threshold) {
                    cout << curr->label << curr->value << " ";
                }
                curr = curr->next;
            }
            cout << "\n";
            
        } else if (cmd == "add") {
            int add_val;
            string to_word;
            char target;
            cin >> add_val >> to_word >> target;

            Node* curr = head;
            while (curr != nullptr) {
                if (curr->label == target) {
                    curr->value += add_val;
                }
                curr = curr->next;
            }
        }
    }

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}