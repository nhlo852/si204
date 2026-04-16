/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       list.cpp
 * Description: Implementation of the shared linked list library functions.
 * Date:        2026-04-13
 ******************************************************************************/

#include "list.h"
#include <iostream>

// Adds a new Pair to the front of the list
void add2front(Node*& head, Pair p) {
    Node* temp = new Node;
    temp->data = p;
    temp->next = head;
    head = temp;
}

// Adds a new Pair to the end of the list (useful for keeping historical order)
void add2back(Node*& head, Pair p) {
    Node* temp = new Node;
    temp->data = p;
    temp->next = nullptr;
    
    if (head == nullptr) {
        head = temp;
    } else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

// Counts and returns the number of nodes currently in the list
int countNodes(Node* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}

// Prints the list in the format: (word value) (word value) 
void printPairs(Node* head) {
    while (head != nullptr) {
        std::cout << "(" << head->data.word << " " << head->data.value << ") ";
        head = head->next;
    }
}

// Prints ONLY the words in the list, separated by spaces
void printWords(Node* head) {
    while (head != nullptr) {
        std::cout << head->data.word << " ";
        head = head->next;
    }
}

// Calculates the total score by summing up all the values in the list
int sumValues(Node* head) {
    int sum = 0;
    while (head != nullptr) {
        sum += head->data.value;
        head = head->next;
    }
    return sum;
}

// Safely deletes all nodes to prevent memory leaks
void freeList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}