/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Proj 02 Part 6
 * Description: Hit or Stand (Scores). Plays until both players stand, 
 * calculating and displaying the best Blackjack score for each hand.
 ******************************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

// Prototypes
void initDeck(int* deck);
void shuffleDeck(int* deck);
void printCard(int card);
void printTable(int* p, int pSize, int* d, int dSize);
int calcScore(int* hand, int size);
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
    
    // Print the initial table and scores
    cout << endl;
    printTable(p, pSize, d, dSize);
    cout << "Player " << calcScore(p, pSize) << ", Dealer " << calcScore(d, dSize) << endl;
    
    bool lastStood = false;
    bool gameOver = false;
    
    // Loop rounds until both players stand
    for (int round = 1; ; round++) {
        
        // --- Player's Turn ---
        cout << "Round " << round << " Player's turn" << endl;
        cout << "hit or stand ? [h/s] ";
        char choice;
        cin >> choice;
        
        if (choice == 'h') {
            deal(deck, &deckTop, &deckSize, p, &pSize);
            lastStood = false; // Reset the stand tracker
        } else {
            // If the dealer stood last turn and now the player stands, game over
            if (lastStood) gameOver = true;
            lastStood = true;
        }
        
        cout << endl;
        printTable(p, pSize, d, dSize);
        cout << "Player " << calcScore(p, pSize) << ", Dealer " << calcScore(d, dSize) << endl;
        
        // Break out of the loop immediately if both stood
        if (gameOver) break;
        
        // --- Dealer's Turn ---
        cout << "Round " << round << " Dealer's turn" << endl;
        cout << "hit or stand ? [h/s] ";
        cin >> choice;
        
        if (choice == 'h') {
            deal(deck, &deckTop, &deckSize, d, &dSize);
            lastStood = false; // Reset the stand tracker
        } else {
            // If the player stood last turn and now the dealer stands, game over
            if (lastStood) gameOver = true;
            lastStood = true;
        }
        
        cout << endl;
        printTable(p, pSize, d, dSize);
        cout << "Player " << calcScore(p, pSize) << ", Dealer " << calcScore(d, dSize) << endl;
        
        // Break out of the loop immediately if both stood
        if (gameOver) break;
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

// calcScore: Calculates the best possible Blackjack score for a hand
int calcScore(int* hand, int size) {
    int total = 0;
    bool hasAce = false;

    // First pass: add up native values
    for (int i = 0; i < size; i++) {
        int faceVal = hand[i] % 100;
        
        if (faceVal >= 2 && faceVal <= 10) total += faceVal;
        else if (faceVal >= 11 && faceVal <= 13) total += 10;
        else if (faceVal == 14) { 
            total += 1; 
            hasAce = true; 
        }
    }

    // Second pass: upgrade the Ace if we won't bust
    if (hasAce && total <= 11) {
        total += 10;
    }
    
    return total;
}

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