/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       ll.h
 * Description: Header file defining the Node struct and list functions.
 * Date:        2026-04-12
 ******************************************************************************/

#pragma once

// Defines a single node in the linked list
struct Node {
    int data;
    Node* next;
};

// Function prototypes
Node* add2back(int d, Node* L);
void enter_after(int d, int x, Node* L);
void remove_after(int target, Node* L);
void print(Node* L);
int sum(Node* L);
void deletelist(Node* L);