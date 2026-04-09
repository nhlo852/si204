#include <iostream>
using namespace std;

struct Node {
    int num;
    Node* next;
};

Node* add2front(int num, Node* List);

int main() {
    Node* list = nullptr;
    int num;
    
    while (cin >> num && num > 0) list = add2front(num, list);
    
    cout << list->num << endl;
    cout << list->next->num << endl;
    
    return 0;
}

Node* add2front(int num, Node* List) {
    Node* temp = new Node;
    temp->num = num;
    temp->next = List;
    return temp;
}