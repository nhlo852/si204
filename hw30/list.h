#pragma once // Searched this up

struct Node {
    int data;
    Node* next;
};

void add2front(Node*& head, int val);