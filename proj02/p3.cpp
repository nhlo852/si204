/******************************************************************************
 * Author: Nathan Lo
 * Alpha: m283852
 * Title: Proj 02 Part 3
 * Description: Hit or Stand
 * Date: 2026-03-22
 ******************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Function Prototypes
void printHand(int* arr, int size);
void initDeck(int* deck);
void shuffleDeck(int* deck);
void deal(int* deck, int* deckTop, int* deckSize, int* hand, int* handSize);

int main() {
    int* p = new int[52];
    int* d = new int[52];
    int* deck = new int[52];
    
    int pSize = 0;
    int dSize = 0;
    int deckTop = 0;
    int deckSize = 52;
    int seed;
    
    // Set up the deck
    initDeck(deck);
    
    // Get seed and shuffle
    cout << "Seed: ";
    cin >> seed;
    srand(seed);
    shuffleDeck(deck);
    
    // Show the starting deck
    printHand(deck, 52);
    
    // Initial Deal: Player, Dealer, Player, Dealer
    deal(deck, &deckTop, &deckSize, p, &pSize);
    deal(deck, &deckTop, &deckSize, d, &dSize);
    deal(deck, &deckTop, &deckSize, p, &pSize);
    deal(deck, &deckTop, &deckSize, d, &dSize);
    
    // Print starting hands
    cout << endl;
    cout << "Player: "; printHand(p, pSize);
    cout << "Dealer: "; printHand(d, dSize);
    
    // Play exactly 3 rounds
    for (int round = 1; round <= 3; round++) {
        char choice;
        
        // Player's Turn
        cout << endl << "Round " << round << " Player's turn" << endl;
        cout << "hit or stand ? [h/s] ";
        cin >> choice;
        
        if (choice == 'h') {
            deal(deck, &deckTop, &deckSize, p, &pSize);
        }
        cout << endl;
        cout << "Player: "; printHand(p, pSize);
        cout << "Dealer: "; printHand(d, dSize);
        
        // Dealer's Turn
        cout << endl << "Round " << round << " Dealer's turn" << endl;
        cout << "hit or stand ? [h/s] ";
        cin >> choice;
        
        if (choice == 'h') {
            deal(deck, &deckTop, &deckSize, d, &dSize);
        }
        cout << endl;
        cout << "Player: "; printHand(p, pSize);
        cout << "Dealer: "; printHand(d, dSize);
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

// Print array items on one line
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

// Moves a card from the top of the deck to a hand
void deal(int* deck, int* deckTop, int* deckSize, int* hand, int* handSize) {
    hand[*handSize] = deck[*deckTop];
    (*handSize)++;
    (*deckTop)++;
    (*deckSize)--;
}