/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Proj 02 Part 2
 * Description: Prints Deck, Deals Card, Shuffles, Resets, or Quits
 * Date:        2026-03-12
 ******************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Function Prototypes
void printHand(int* arr, int size);
void printDeck(int* deck, int startIdx, int size);
void shuffleDeck(int* deck);
void initDeck(int* deck);

int main() {
    int* p = new int[52];
    int* d = new int[52];
    int* deck = new int[52];
    
    // Variables to track sizes and the top of the deck
    int pSize = 0;
    int dSize = 0;
    int deckTop = 0;   
    int deckSize = 52; 
    int seed;
    
    // Initialize deck to starting sorted order
    initDeck(deck);

    string command = "";
    cout << "Seed: "; cin >> seed;
    srand(seed);
    
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
                p[pSize] = deck[deckTop]; 
                pSize++;                  
                deckTop++;                
                deckSize--;               
            }
        }
        else if (command == "deal-d") {
            if (deckSize > 0) {
                d[dSize] = deck[deckTop]; 
                dSize++;                  
                deckTop++;                
                deckSize--;               
            }
        }
        else if (command == "shuffle-deck") {
            // Only allow shuffling if no cards have been dealt
            if (deckSize != 52) {
                cout << "Error: Not a full deck" << endl;
            } else {
                shuffleDeck(deck);
            }
        }
        else if (command == "reset") {
            // Reset all tracking variables to zero/max
            deckTop = 0;
            deckSize = 52;
            pSize = 0;
            dSize = 0;
            // Re-sort the deck back to its original state
            initDeck(deck);
        }
        else {
            cout << "Unknown command" << endl;
        }
        
        cout << "> ";
    }

    // Clean up memory
    delete[] p;
    delete[] d;
    delete[] deck;
    
    return 0;
}

// Rebuilds the deck in perfect sorted order 
void initDeck(int* deck) {
    int count = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 2; j <= 14; j++) {
            deck[count] = j + (100 * i);
            count++;
        }
    }
}

// Shuffles the deck using the provided random index 
void shuffleDeck(int* deck) {
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Prints the deck starting from the current top card
void printDeck(int* deck, int startIdx, int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << deck[startIdx + i];
        if (i < size - 1) {
            cout << " ";
        }
    }
    cout << "]" << endl;
}

// Prints a player or dealer hand
void printHand(int* arr, int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) {
            cout << " ";
        }
    }
    cout << "]" << endl;
}