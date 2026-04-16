/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       list.h
 * Description: Header file defining the Node struct and linked list functions.
 * Date:        2026-04-10
 ******************************************************************************/

#pragma once
#include <string>

// Defines a single node in the linked list
struct Node {
    std::string word; // Stores the actual word
    Node* next;       // Pointer to the next node in the list
};

// Function prototypes
void add2front(Node*& head, std::string w);
void freeList(Node*& head);