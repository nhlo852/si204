/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Proj 02 Part 2
 * Description: Interactive Deck Shell 
 ******************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Function Prototypes
void printHand(int* arr, int size);
void printDeck(int* deck, int startIdx, int size);
void initDeck(int* deck);
void shuffleDeck(int* deck);
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
    
    // Initialize deck
    initDeck(deck);
    
    // Get the seed to start the program
    int seed;
    cout << "Seed: ";
    cin >> seed;
    srand(seed);
    
    string command = "";
    cout << "> ";
    
    // The Interactive Shell
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
        else if (command == "init-deck" || command == "init" || command == "initDeck" || command == "init_deck" || command == "reset") {
            pSize = 0;
            dSize = 0;
            deckTop = 0;
            deckSize = 52;
            initDeck(deck);
        }
        else if (command == "shuffle" || command == "shuffle-deck" || command == "shuffleDeck") {
            shuffleDeck(deck);
        }
        
        cout << "> ";
    }
    
    // Clean up memory
    delete[] p;
    delete[] d;
    delete[] deck;
    return 0;
}

// ============================================================================
// Helper Functions
// ============================================================================

// Build the deck sequentially
void initDeck(int* deck) {
    int count = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 2; j <= 14; j++) {
            deck[count] = j + (100 * i);
            count++;
        }
    }
}

// Shuffle the entire deck using random swaps
void shuffleDeck(int* deck) {
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Prints the deck starting from the current 'top' card
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

// Moves a card from the top of the deck to a hand using pointers
void deal(int* deck, int* deckTop, int* deckSize, int* hand, int* handSize) {
    hand[*handSize] = deck[*deckTop];
    (*handSize)++;
    (*deckTop)++;
    (*deckSize)--;
}