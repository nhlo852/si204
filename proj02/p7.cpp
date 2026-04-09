/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Proj 02 Part 7
 * Description: Hit or Stand (Full Game Simulation). Features automatic dealer 
 * logic, busting, hidden hole cards, and automatic tie-breakers.
 ******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <unistd.h> 

using namespace std;

// Prototypes
void initDeck(int* deck);
void shuffleDeck(int* deck);
void printCard(int card);
void printTable(int* p, int pSize, int* d, int dSize, bool hideDealer);
int calcScore(int* hand, int size);
void deal(int* deck, int* deckTop, int* deckSize, int* hand, int* handSize);

int main() {
    // Allocate memory for the deck and the two hands
    int* deck = new int[52];
    int* p = new int[52];
    int* d = new int[52];
    
    // Get the seed from the user once for the whole program
    int seed;
    cout << "Seed: "; 
    cin >> seed;
    srand(seed);

    // Main game loop (repeats automatically if there is a tie)
    while (true) {
        
        // Reset tracking variables for a brand new game
        int pSize = 0;
        int dSize = 0;
        int deckTop = 0;   
        int deckSize = 52; 
        
        // Initialize and shuffle a fresh deck
        initDeck(deck);
        shuffleDeck(deck); 

        // Deal the initial 4 cards
        deal(deck, &deckTop, &deckSize, p, &pSize);
        deal(deck, &deckTop, &deckSize, d, &dSize);
        deal(deck, &deckTop, &deckSize, p, &pSize);
        deal(deck, &deckTop, &deckSize, d, &dSize);

        cout << endl;
        
        // Print the initial table with the dealer's first card hidden (true)
        printTable(p, pSize, d, dSize, true); 

        bool pStood = false;
        bool dStood = false;
        bool playerBusted = false;
        bool dealerBusted = false;

        // Loop rounds until someone wins, busts, or both stand
        for (int round = 1; ; round++) {
            
            // --- Player's Turn ---
            cout << "Round " << round << " Player's turn" << endl;
            cout << "hit or stand? [h/s] ";
            char pChoice;
            cin >> pChoice;
            
            if (pChoice == 'h') {
                deal(deck, &deckTop, &deckSize, p, &pSize);
                pStood = false; 
            } else {
                pStood = true;
            }
            
            cout << endl;
            
            // Check if player went over 21
            if (calcScore(p, pSize) > 21) {
                playerBusted = true;
                break; 
            }
            
            // Stop immediately if both players stood
            if (pStood && dStood) break; 
            
            printTable(p, pSize, d, dSize, true);
            
            
            // --- Dealer's Turn ---
            cout << "Round " << round << " Dealer's turn" << endl;
            char dChoice;
            
            // Dealer logic: automatically hits if score is under 17
            if (calcScore(d, dSize) < 17) {
                dChoice = 'h';
            } else {
                dChoice = 's';
            }
            
            cout << "hit or stand? [h/s] " << dChoice << endl;
            
            // The dramatic pause using unistd.h!
            sleep(1);
            
            if (dChoice == 'h') {
                deal(deck, &deckTop, &deckSize, d, &dSize);
                dStood = false;
            } else {
                dStood = true;
            }
            
            cout << endl;
            
            // Check if dealer went over 21
            if (calcScore(d, dSize) > 21) {
                dealerBusted = true;
                break; 
            }

            // Stop immediately if both players stood
            if (pStood && dStood) break; 

            printTable(p, pSize, d, dSize, true);
        }

        // --- GAME OVER LOGIC ---
        
        // Print the final table with the dealer's card revealed (false)
        printTable(p, pSize, d, dSize, false);
        
        // Determine the winner
        if (playerBusted) {
            cout << "Player busts, dealer wins" << endl;
            break; 
        } 
        else if (dealerBusted) {
            cout << "Dealer busts, player wins" << endl;
            break; 
        } 
        else {
            int pScore = calcScore(p, pSize);
            int dScore = calcScore(d, dSize);
            
            if (pScore > dScore) {
                cout << "Player wins" << endl;
                break; 
            } 
            else if (dScore > pScore) {
                cout << "Dealer wins" << endl;
                break; 
            } 
            else {
                // TIE! Loop back to the top of the while(true) to play again!
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

// ============================================================================
// Helper Functions
// ============================================================================

// calcScore: Calculates the best possible Blackjack score for a hand
int calcScore(int* hand, int size) {
    int total = 0;
    bool hasAce = false;

    for (int i = 0; i < size; i++) {
        int faceVal = hand[i] % 100;
        
        if (faceVal >= 2 && faceVal <= 10) total += faceVal;
        else if (faceVal >= 11 && faceVal <= 13) total += 10;
        else if (faceVal == 14) { 
            total += 1; 
            hasAce = true; 
        }
    }

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

// printTable: Prints the parsed card hands vertically, with an option to hide the dealer's hole card
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
            // Hide the dealer's first card if the flag is true
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

// deal: Moves a card from the deck to a hand, using pointers to update the sizes permanently
void deal(int* deck, int* deckTop, int* deckSize, int* hand, int* handSize) {
    hand[*handSize] = deck[*deckTop];
    (*handSize)++;
    (*deckTop)++;
    (*deckSize)--;
}