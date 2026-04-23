//This program reads x and y coordinates into the front of a linked list. It then takes commands like greater or less 
//followed by a threshold value to print coordinates that match the condition (comparing against the x value in this example).

#include <iostream>
#include <string>

using namespace std;

struct CoordNode {
    int x;
    int y;
    CoordNode* next;
};

void add2front(CoordNode*& head, int x, int y) {
    CoordNode* temp = new CoordNode;
    temp->x = x;
    temp->y = y;
    temp->next = head;
    head = temp;
}

int main() {
    CoordNode* head = nullptr;
    int x, y;

    while (cin >> x >> y && (x != -999 || y != -999)) {
        add2front(head, x, y);
    }

    string cmd;
    int threshold;
    while (cin >> cmd >> threshold && cmd != "quit") {
        CoordNode* curr = head;
        
        while (curr != nullptr) {
            if (cmd == "greater" && curr->x > threshold) {
                cout << "(" << curr->x << ", " << curr->y << ") ";
            } else if (cmd == "less" && curr->x < threshold) {
                cout << "(" << curr->x << ", " << curr->y << ") ";
            }
            curr = curr->next;
        }
        cout << "\n";
    }

    while (head != nullptr) {
        CoordNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}