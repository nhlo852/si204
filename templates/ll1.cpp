//This program reads names and numbers, adds them to the front of a linked list, 
//and then processes commands to add or sub (subtract) from a specific person's number.

#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    int number;
    Node* next;
};

void add2front(Node*& head, string name, int number) {
    Node* temp = new Node;
    temp->name = name;
    temp->number = number;
    temp->next = head;
    head = temp;
}

int main() {
    Node* head = nullptr;
    string name;
    int num;

    while (cin >> name && name != "DONE") {
        cin >> num;
        add2front(head, name, num);
    }

    string cmd;
    while (cin >> cmd && cmd != "QUIT") {
        int val;
        string target;
        cin >> val >> target;

        Node* curr = head;
        while (curr != nullptr) {
            if (curr->name == target) {
                if (cmd == "add") {
                    curr->number += val;
                } else if (cmd == "sub") {
                    curr->number -= val;
                }
            }
            curr = curr->next;
        }
    }

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}