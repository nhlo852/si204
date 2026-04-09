/******************************************************************************
 * Author: Nathan Lo
 * Alpha: m283852
 * Title: Proj 02 Part 1
 * Description: Prints Deck, Deals Card, or Quits
 * Date: 2026-03-12
 ******************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Function Prototypes
void printHand(int* arr, int size);
void printDeck(int* deck, int startIdx, int size);
void deal(int* deck, int* deckTop, int* deckSize, int* hand, int* handSize);

int main() {
    int* p = new int[52];
    int* d = new int[52];
    int* deck = new int[52];
    
    // Variables to track sizes and the top of the deck
    int pSize = 0;
    int dSize = 0;
    int deckTop = 0;
    int deckSize = 52;
    int count = 0;
    
    // Initialize deck
    for (int i = 1; i <= 4; i++) {
        for (int j = 2; j <= 14; j++) {
            deck[count] = j + (100 * i);
            count++;
        }
    }
    
    string command = "";
    cout << "> ";
    
    while (cin >> command && command != "quit") {
        if (command == "print-deck") {
            printDeck(deck, deckTop, deckSize);
        }
        else if (command == "print-p") {
            printHand(p, pSize);
        }
        else if (command == "print-d") {
            printHand(d, dSize);
        }
        else if (command == "deal-p") {
            if (deckSize > 0) {
                deal(deck, &deckTop, &deckSize, p, &pSize);
            }
        }
        else if (command == "deal-d") {
            if (deckSize > 0) {
                deal(deck, &deckTop, &deckSize, d, &dSize);
            }
        }
        cout << "> ";
    }
    
    delete[] p;
    delete[] d;
    delete[] deck;
    return 0;
}

// Prints the deck starting from the current 'top' card
void printDeck(int* deck, int startIdx, int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << deck[startIdx + i];
        cout << " ";
    }
    cout << "]" << endl;
}

// Prints a player or dealer hand
void printHand(int* arr, int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        cout << " ";
    }
    cout << "]" << endl;
}

// Moves a card from the top of the deck to a hand
void deal(int* deck, int* deckTop, int* deckSize, int* hand, int* handSize) {
    hand[*handSize] = deck[*deckTop];
    (*handSize)++;
    (*deckTop)++;
    (*deckSize)--;
}