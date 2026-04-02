/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Proj 02 Part 5
 * Description: Hit or Stand (Pretty Printing)
 * Date:        2026-03-28
 ******************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Function Prototypes
void printTable(int* p, int pSize, int* d, int dSize);
void printCard(int card);
void initDeck(int* deck);
void shuffleDeck(int* deck);

int main() {
    int* p = new int[52];
    int* d = new int[52];
    int* deck = new int[52];
    
    int pSize = 0;
    int dSize = 0;
    int deckTop = 0;   
    int seed;
    
    // Set up the deck
    initDeck(deck);

    // Get seed and shuffle
    cout << "Seed: "; 
    cin >> seed;
    srand(seed);
    shuffleDeck(deck);

    // Initial Deal: Player, Dealer, Player, Dealer
    p[pSize] = deck[deckTop]; pSize++; deckTop++;
    d[dSize] = deck[deckTop]; dSize++; deckTop++;
    p[pSize] = deck[deckTop]; pSize++; deckTop++;
    d[dSize] = deck[deckTop]; dSize++; deckTop++;

    // Print starting table
    cout << endl;
    printTable(p, pSize, d, dSize);

    // Play exactly 3 rounds
    for (int round = 1; round <= 3; round++) {
        char choice;
        
        // --- Player's Turn ---
        cout << "Round " << round << " Player's turn" << endl;
        cout << "hit or stand? [h/s] ";
        cin >> choice;
        
        // Add card if they hit
        if (choice == 'h') {
            p[pSize] = deck[deckTop]; 
            pSize++; 
            deckTop++;
        }
        
        cout << endl;
        printTable(p, pSize, d, dSize);
        
        // --- Dealer's Turn ---
        cout << "Round " << round << " Dealer's turn" << endl;
        cout << "hit or stand? [h/s] ";
        cin >> choice;
        
        // Add card if they hit
        if (choice == 'h') {
            d[dSize] = deck[deckTop]; 
            dSize++; 
            deckTop++;
        }
        
        cout << endl;
        printTable(p, pSize, d, dSize);
    }

    // Clean up memory
    delete[] p;
    delete[] d;
    delete[] deck;
    
    return 0;
}

// Build the deck
void initDeck(int* deck) {
    int count = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 2; j <= 14; j++) {
            deck[count] = j + (100 * i);
            count++;
        }
    }
}

// Shuffle the deck
void shuffleDeck(int* deck) {
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Translate integer into formatted face value and suit
void printCard(int card) {
    int suitVal = card / 100;
    int faceVal = card % 100;

    // Print face value (taking exactly 2 spaces)
    if (faceVal >= 2 && faceVal <= 9) {
        cout << " " << faceVal;
    } else if (faceVal == 10) {
        cout << 10;
    } else if (faceVal == 11) {
        cout << " J";
    } else if (faceVal == 12) {
        cout << " Q";
    } else if (faceVal == 13) {
        cout << " K";
    } else if (faceVal == 14) {
        cout << " A";
    }

    // Print suit symbol
    if (suitVal == 1) cout << "\u2663";      // Clubs
    else if (suitVal == 2) cout << "\u2666"; // Diamonds
    else if (suitVal == 3) cout << "\u2665"; // Hearts
    else if (suitVal == 4) cout << "\u2660"; // Spades
}

// Print hands vertically in a table with pretty formatting
void printTable(int* p, int pSize, int* d, int dSize) {
    cout << " Player Dealer" << endl;
    
    // Find who has more cards so we know how many rows to print
    int maxRows = pSize;
    if (dSize > pSize) {
        maxRows = dSize;
    }
    
    // Print row by row
    for (int i = 0; i < maxRows; i++) {
        cout << "| ";
        
        // Print player card or 6 empty spaces to keep the pipe aligned
        if (i < pSize) {
            printCard(p[i]);
            cout << "  ";
        } else {
            cout << "      ";
        }
        
        cout << "| ";
        
        // Print dealer card or 6 empty spaces for alignment
        if (i < dSize) {
            printCard(d[i]);
            cout << "  |";
        } else {
            cout << "      |";
        }
        
        cout << endl;
    }
}