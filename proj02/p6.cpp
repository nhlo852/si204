/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Proj 02 Part 6
 * Description: Hit or Stand (Scores)
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
int calcScore(int* hand, int size);

int main() {
    // Make arrays to hold the cards
    int* p = new int[52];
    int* d = new int[52];
    int* deck = new int[52];
    
    int pSize = 0;
    int dSize = 0;
    int deckTop = 0;   
    int seed;
    
    // Fill the deck and shuffle it based on user input
    initDeck(deck);
    cout << "Seed: "; 
    cin >> seed;
    srand(seed);
    shuffleDeck(deck);

    // Deal the first 4 cards: Player, Dealer, Player, Dealer
    p[pSize] = deck[deckTop]; pSize++; deckTop++;
    d[dSize] = deck[deckTop]; dSize++; deckTop++;
    p[pSize] = deck[deckTop]; pSize++; deckTop++;
    d[dSize] = deck[deckTop]; dSize++; deckTop++;

    // Show the starting table and scores
    cout << endl;
    printTable(p, pSize, d, dSize);
    cout << "Player " << calcScore(p, pSize) << ", Dealer " << calcScore(d, dSize) << endl;

    // Track if someone stood so we know when to end the game
    bool lastStood = false;
    bool gameOver = false;

    // Keep playing rounds until someone wins
    for (int round = 1; ; round++) {
        
        // --- Player's Turn ---
        cout << "Round " << round << " Player's turn" << endl;
        cout << "hit or stand ? [h/s] ";
        char choice;
        cin >> choice;
        
        // Give the player a card
        if (choice == 'h') {
            p[pSize] = deck[deckTop]; 
            pSize++; deckTop++;
            lastStood = false; // Reset the stand tracker
        } else {
            // If the dealer stood last turn, and now we stand, the game is over
            if (lastStood) gameOver = true; 
            lastStood = true;
        }
        
        cout << endl;
        printTable(p, pSize, d, dSize);
        cout << "Player " << calcScore(p, pSize) << ", Dealer " << calcScore(d, dSize) << endl;
        
        // Stop playing if both stood
        if (gameOver) break;


        // --- Dealer's Turn ---
        cout << "Round " << round << " Dealer's turn" << endl;
        cout << "hit or stand ? [h/s] ";
        cin >> choice;
        
        // Give the dealer a card
        if (choice == 'h') {
            d[dSize] = deck[deckTop]; 
            dSize++; deckTop++;
            lastStood = false; // Reset the stand tracker
        } else {
            // If the player stood last turn, and now we stand, the game is over
            if (lastStood) gameOver = true; 
            lastStood = true;
        }
        
        cout << endl;
        printTable(p, pSize, d, dSize);
        cout << "Player " << calcScore(p, pSize) << ", Dealer " << calcScore(d, dSize) << endl;
        
        // Stop playing if both stood
        if (gameOver) break;
    }

    // Give memory back
    delete[] p;
    delete[] d;
    delete[] deck;
    
    return 0;
}

// Figure out how many points a hand is worth
int calcScore(int* hand, int size) {
    int total = 0;
    bool hasAce = false;

    // Add up the face value of all cards
    for (int i = 0; i < size; i++) {
        int faceVal = hand[i] % 100;
        
        // Number cards are worth their number
        if (faceVal >= 2 && faceVal <= 10) total += faceVal;
        // Face cards are worth 10
        else if (faceVal >= 11 && faceVal <= 13) total += 10;
        // Aces start as 1 point
        else if (faceVal == 14) {
            total += 1;
            hasAce = true;
        }
    }

    // If we have an Ace and we won't bust, make the Ace worth 11 instead of 1
    if (hasAce && total <= 11) {
        total += 10;
    }
    
    return total;
}

// Fill the deck with the 52 math numbers representing cards
void initDeck(int* deck) {
    int count = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 2; j <= 14; j++) {
            deck[count] = j + (100 * i);
            count++;
        }
    }
}

// Mix up the cards randomly
void shuffleDeck(int* deck) {
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Turn a math number into a pretty card symbol
void printCard(int card) {
    int suitVal = card / 100;
    int faceVal = card % 100;

    // Print the letter or number for the card
    if (faceVal >= 2 && faceVal <= 9) cout << " " << faceVal;
    else if (faceVal == 10) cout << 10;
    else if (faceVal == 11) cout << " J";
    else if (faceVal == 12) cout << " Q";
    else if (faceVal == 13) cout << " K";
    else if (faceVal == 14) cout << " A";

    // Print the special shape for the suit
    if (suitVal == 1) cout << "\u2663";      
    else if (suitVal == 2) cout << "\u2666"; 
    else if (suitVal == 3) cout << "\u2665"; 
    else if (suitVal == 4) cout << "\u2660"; 
}

// Draw the table with the cards lined up
void printTable(int* p, int pSize, int* d, int dSize) {
    cout << " Player Dealer" << endl;
    
    // Find out who has the most cards so we know how tall to make the table
    int maxRows = pSize;
    if (dSize > pSize) maxRows = dSize;
    
    // Print row by row
    for (int i = 0; i < maxRows; i++) {
        cout << "| ";
        
        // Print player card or empty spaces
        if (i < pSize) {
            printCard(p[i]);
            cout << "  ";
        } else { cout << "      "; }
        
        cout << "| ";
        
        // Print dealer card or empty spaces
        if (i < dSize) {
            printCard(d[i]);
            cout << "  |";
        } else { cout << "      |"; }
        
        cout << endl;
    }
}