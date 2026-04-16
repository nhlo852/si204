/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       list.h
 * Description: Header file defining the Pair and Node structs, and the 
 * prototypes for our linked list library.
 * Date:        2026-04-13
 ******************************************************************************/

#pragma once
#include <string>

// Struct to hold the word and its point value
struct Pair {
    std::string word;
    int value;
};

// Defines a single node in the linked list
struct Node {
    Pair data;
    Node* next;
};

// Function prototypes
void add2front(Node*& head, Pair p);
void add2back(Node*& head, Pair p);
int countNodes(Node* head);
void printPairs(Node* head);
void printWords(Node* head);
int sumValues(Node* head);
void freeList(Node*& head);