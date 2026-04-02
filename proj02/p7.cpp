/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Proj 02 Part 7
 * Description: Hit or Stand (Full Game Simulation)
 * Date:        2026-03-28
 ******************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h> 

using namespace std;

// Function Prototypes
void printTable(int* p, int pSize, int* d, int dSize, bool hideDealer);
void printCard(int card);
void initDeck(int* deck);
void shuffleDeck(int* deck);
int calcScore(int* hand, int size);

int main() {
    int* p = new int[52];
    int* d = new int[52];
    int* deck = new int[52];
    
    int seed;
    cout << "Seed: "; 
    cin >> seed;
    
    // Only set the random seed ONCE for the whole program
    srand(seed);

    // Keep playing the game over and over if it ends in a tie
    while (true) {
        int pSize = 0;
        int dSize = 0;
        int deckTop = 0;   
        
        // Get a brand new deck and shuffle it
        initDeck(deck);
        shuffleDeck(deck); 

        // Deal the first 4 cards
        p[pSize] = deck[deckTop]; pSize++; deckTop++;
        d[dSize] = deck[deckTop]; dSize++; deckTop++;
        p[pSize] = deck[deckTop]; pSize++; deckTop++;
        d[dSize] = deck[deckTop]; dSize++; deckTop++;

        cout << endl;
        // 'true' hides the dealer's first card with **
        printTable(p, pSize, d, dSize, true); 

        bool pStood = false;
        bool dStood = false;
        bool playerBusted = false;
        bool dealerBusted = false;

        // Loop rounds until someone wins
        for (int round = 1; ; round++) {
            
            // --- Player's Turn ---
            cout << "Round " << round << " Player's turn" << endl;
            cout << "hit or stand? [h/s] ";
            char pChoice;
            cin >> pChoice;
            
            // Give the player a card
            if (pChoice == 'h') {
                p[pSize] = deck[deckTop]; 
                pSize++; deckTop++;
                pStood = false; 
            } else {
                pStood = true;
            }
            
            cout << endl;
            
            // Check if player went over 21
            if (calcScore(p, pSize) > 21) {
                playerBusted = true;
                break; // Stop playing
            }
            
            // Stop immediately if both stood (prevents double printing!)
            if (pStood && dStood) break; 
            
            printTable(p, pSize, d, dSize, true);
            
            
            // --- Dealer's Turn ---
            cout << "Round " << round << " Dealer's turn" << endl;
            char dChoice;
            
            // Dealer automatically hits if score is under 17
            if (calcScore(d, dSize) < 17) {
                dChoice = 'h';
            } else {
                dChoice = 's';
            }
            
            cout << "hit or stand? [h/s] " << dChoice << endl;
            
            // Pause the program for 1 second so it looks cool
            sleep(1); 
            
            // Give the dealer a card
            if (dChoice == 'h') {
                d[dSize] = deck[deckTop]; 
                dSize++; deckTop++;
                dStood = false;
            } else {
                dStood = true;
            }
            
            cout << endl;
            
            // Check if dealer went over 21
            if (calcScore(d, dSize) > 21) {
                dealerBusted = true;
                break; // Stop playing
            }

            // Stop immediately if both stood (prevents double printing!)
            if (pStood && dStood) break; 

            printTable(p, pSize, d, dSize, true);
        }

        // --- GAME OVER LOGIC ---

        // Print the table one last time, 'false' reveals the hidden card
        printTable(p, pSize, d, dSize, false);
        
        // Figure out who won
        if (playerBusted) {
            cout << "Player busts, dealer wins" << endl;
            break; // End the program entirely
        } 
        else if (dealerBusted) {
            cout << "Dealer busts, player wins" << endl;
            break; // End the program entirely
        } 
        else {
            int pScore = calcScore(p, pSize);
            int dScore = calcScore(d, dSize);
            
            if (pScore > dScore) {
                cout << "Player wins" << endl;
                break; // End the program entirely
            } 
            else if (dScore > pScore) {
                cout << "Dealer wins" << endl;
                break; // End the program entirely
            } 
            else {
                // TIE! 
                continue; 
            }
        }
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

    // Add up face values
    for (int i = 0; i < size; i++) {
        int faceVal = hand[i] % 100;
        if (faceVal >= 2 && faceVal <= 10) total += faceVal;
        else if (faceVal >= 11 && faceVal <= 13) total += 10;
        else if (faceVal == 14) { total += 1; hasAce = true; }
    }

    // Upgrade Ace to 11 if we have room
    if (hasAce && total <= 11) total += 10;
    return total;
}

// Fill the deck
void initDeck(int* deck) {
    int count = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 2; j <= 14; j++) {
            deck[count] = j + (100 * i);
            count++;
        }
    }
}

// Mix the deck randomly
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

// Draw the table with the cards lined up
void printTable(int* p, int pSize, int* d, int dSize, bool hideDealer) {
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
            // Check if we need to hide the top card
            if (i == 0 && hideDealer) { 
                cout << " ** |"; 
            } 
            else {
                printCard(d[i]);
                cout << "  |";
            }
        } else { cout << "      |"; }
        
        cout << endl;
    }
}