/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Proj 02 Part 4
 * Description: Hit or Stand (Vertical Hands)
 * Date:        2026-03-28
 ******************************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

// Function Prototypes
void printDeck(int* arr, int size);
void printTable(int* p, int pSize, int* d, int dSize);
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
    
    // Show the starting deck horizontally
    printDeck(deck, 52);

    // Initial Deal for Player, Dealer, Player, Dealer
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
        
        // Player's Turn 
        cout << "Round " << round << " Player's turn" << endl;
        cout << "hit or stand ? [h/s] ";
        cin >> choice;
        
        // Add card if they hit
        if (choice == 'h') {
            p[pSize] = deck[deckTop]; 
            pSize++; 
            deckTop++;
        }
        
        cout << endl;
        printTable(p, pSize, d, dSize);
        
        // Dealer's Turn 
        cout << "Round " << round << " Dealer's turn" << endl;
        cout << "hit or stand ? [h/s] ";
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

// Print array items on one line (for the deck)
void printDeck(int* arr, int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) {
            cout << " ";
        }
    }
    cout << "]" << endl;
}

// Print hands vertically in a table
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
        
        // Print player card or 5 empty spaces to line up the pipe
        if (i < pSize) {
            cout << p[i] << "  ";
        } else {
            cout << "     ";
        }
        
        cout << "| ";
        
        // Print dealer card or 4 empty spaces to line up the pipe
        if (i < dSize) {
            cout << d[i] << " |";
        } else {
            cout << "    |";
        }
        
        cout << endl;
    }
}