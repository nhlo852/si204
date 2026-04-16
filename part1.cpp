/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       part1.cpp
 * Description: Reads pairs from a file, stores them in reverse order using 
 * add2front, and prints the count and the list.
 * Date:        2026-04-13
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "list.h"

using namespace std;

int main() {
    string filename;
    cout << "Input file is: ";
    cin >> filename;

    ifstream fin(filename);
    if (!fin) {
        cout << "Error: File " << filename << " not found!\n";
        return 1;
    }

    Node* head = nullptr;
    char p1, p2; // To absorb the parentheses '(' and ')'
    Pair p;
    
    // Read the format: (word value)
    while (fin >> p1 >> p.word >> p.value >> p2) {
        add2front(head, p);
    }

    cout << "Count is " << countNodes(head) << "\n";
    printPairs(head);
    cout << "\n";

    freeList(head);
    return 0;
}