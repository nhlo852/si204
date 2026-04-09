/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Proj 02 Part 5
 * Description: Plays 3 rounds of Hit/Stand, printing the hands vertically 
 * in a table format using formatted card symbols (pretty print).
 ******************************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

// Prototypes
void initDeck(int* deck);
void shuffleDeck(int* deck);
void printCard(int card);
void printTable(int* p, int pSize, int* d, int dSize);
void deal(int* deck, int* deckTop, int* deckSize, int* hand, int* handSize);

int main() {
    // Allocate memory for the deck and the two hands
    int* deck = new int[52];
    int* p = new int[52];
    int* d = new int[52];
    
    // Set up tracking variables
    int pSize = 0;
    int dSize = 0;
    int deckTop = 0;
    int deckSize = 52;
    
    // Initialize the deck
    initDeck(deck);
    
    // Get the seed and shuffle
    int seed;
    cout << "Seed: "; 
    cin >> seed;
    
    srand(seed);
    shuffleDeck(deck);
    
    // Deal the initial 4 cards
    deal(deck, &deckTop, &deckSize, p, &pSize);
    deal(deck, &deckTop, &deckSize, d, &dSize);
    deal(deck, &deckTop, &deckSize, p, &pSize);
    deal(deck, &deckTop, &deckSize, d, &dSize);
    
    // Print the initial hands using the new pretty-print table format
    cout << endl;
    printTable(p, pSize, d, dSize);
    
    // Loop for exactly 3 rounds
    for (int round = 1; round <= 3; round++) {
        
        // --- Player's Turn ---
        cout << "Round " << round << " Player's turn" << endl;
        cout << "hit or stand ? [h/s] ";
        char choice;
        cin >> choice;
        
        if (choice == 'h') {
            deal(deck, &deckTop, &deckSize, p, &pSize);
        }
        
        cout << endl;
        printTable(p, pSize, d, dSize);
        
        // --- Dealer's Turn ---
        cout << "Round " << round << " Dealer's turn" << endl;
        cout << "hit or stand ? [h/s] ";
        cin >> choice;
        
        if (choice == 'h') {
            deal(deck, &deckTop, &deckSize, d, &dSize);
        }
        
        cout << endl;
        printTable(p, pSize, d, dSize);
    }
    
    // Give memory back
    delete[] deck;
    delete[] p;
    delete[] d;
    
    return 0;
}

// ============================================================================
// Helper Functions
// ============================================================================

// initDeck: Fills the deck array with 52 math integers (suit * 100 + face)
void initDeck(int* deck) {
    int count = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 2; j <= 14; j++) {
            deck[count] = j + (100 * i);
            count++;
        }
    }
}

// shuffleDeck: Randomizes the order of the deck by swapping indexes
void shuffleDeck(int* deck) {
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// printCard: Decodes the integer card value and prints the face and UTF-8 suit
void printCard(int card) {
    int suitVal = card / 100;
    int faceVal = card % 100;

    if (faceVal >= 2 && faceVal <= 9) cout << " " << faceVal;
    else if (faceVal == 10) cout << 10;
    else if (faceVal == 11) cout << " J";
    else if (faceVal == 12) cout << " Q";
    else if (faceVal == 13) cout << " K";
    else if (faceVal == 14) cout << " A";

    if (suitVal == 1) cout << "\u2663";      
    else if (suitVal == 2) cout << "\u2666"; 
    else if (suitVal == 3) cout << "\u2665"; 
    else if (suitVal == 4) cout << "\u2660"; 
}

// printTable: Prints the parsed card hands vertically side-by-side
void printTable(int* p, int pSize, int* d, int dSize) {
    cout << " Player Dealer" << endl;
    
    int maxRows = pSize;
    if (dSize > pSize) maxRows = dSize;
    
    for (int i = 0; i < maxRows; i++) {
        cout << "| ";
        
        // Print Player side
        if (i < pSize) {
            printCard(p[i]);
            cout << "  ";
        } else { cout << "      "; }
        
        cout << "| ";
        
        // Print Dealer side
        if (i < dSize) {
            printCard(d[i]);
            cout << "  |";
        } else { cout << "      |"; }
        
        cout << endl;
    }
}

// deal: Moves a card from the deck to a hand, using pointers to update the sizes permanently
void deal(int* deck, int* deckTop, int* deckSize, int* hand, int* handSize) {
    hand[*handSize] = deck[*deckTop];
    (*handSize)++;
    (*deckTop)++;
    (*deckSize)--;
}