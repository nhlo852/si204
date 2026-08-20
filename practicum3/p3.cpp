//This program reads x and y coordinates into the front of a linked list. It then takes commands like greater or less 
//followed by a threshold value to print coordinates that match the condition (comparing against the x value in this example).

#include <iostream>
#include <string>

using namespace std;

struct CoordNode {
    double x;
    double y;
    CoordNode* next;
};

void add2front(CoordNode*& head, double x, double y) {
    CoordNode* temp = new CoordNode;
    temp->x = x;
    temp->y = y;
    temp->next = head;
    head = temp;
}

int main() {
    CoordNode* head = nullptr;
    char junk;
    double x, y;
    string cmd = "a";
    double threshold;
    while (cmd != "q") {
        cout << "command: "; 
        cin >> cmd;
        CoordNode* curr = head;
        if (cmd == "add") {
            cin >> junk >> x >> junk >> y >> junk;
            add2front(head, x, y);

        }
        else {
            cin >> threshold;
        }

        while (curr != nullptr) {
            if (cmd == "gt-x" && curr->x > threshold) {
                cout << "(" << curr->x << ", " << curr->y << ") ";
            } 
            else if (cmd == "gt-y" && curr->y > threshold) {
                cout << "(" << curr->x << ", " << curr->y << ") ";
            }
            else if (cmd == "lt-x" && curr->x < threshold) {
                cout << "(" << curr->x << ", " << curr->y << ") ";
            } 
            else if (cmd == "lt-y" && curr->y < threshold) {
                cout << "(" << curr->x << ", " << curr->y << ") ";
            }
            curr = curr->next;
        }
        if (cmd == "gt-x" || cmd == "gt-y" || cmd == "lt-x" || cmd == "lt-y") cout << endl;
    }

    while (head != nullptr) {
        CoordNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}