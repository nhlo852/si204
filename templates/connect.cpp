/******************************************************************************
 * Title:       Connect 4 (Vertical Only)
 * Description: A 6x7 Connect 4 game where pieces fall to the bottom. 
 * Users input a column letter (A-G). Wins are strictly vertical!
 ******************************************************************************/

#include <iostream>

using namespace std;

// Function Prototypes
void printBoard(char** grid, int rows, int cols);
bool checkWin(char** grid, int rows, int cols, char player);
bool isBoardFull(char** grid, int rows, int cols);

int main() {
    int rows = 6;
    int cols = 7;

    // 1. Dynamically allocate the 6x7 2D array
    char** grid = new char*[rows];
    for (int i = 0; i < rows; i++) {
        grid[i] = new char[cols];
        
        // Fill the board with periods '.'
        for (int j = 0; j < cols; j++) {
            grid[i][j] = '.';
        }
    }

    char currentPlayer = 'X';
    bool gameOver = false;

    // 2. Main Game Loop
    while (!gameOver) {
        printBoard(grid, rows, cols);
        
        char input;
        cout << "Player " << currentPlayer << ", enter a column letter (A-G): ";
        cin >> input;

        // Convert the letter into a column index (0 to 6)
        int col = toupper(input) - 'A';

        // Validate the input
        if (col < 0 || col >= cols) {
            cout << "Invalid column! Please pick A-G." << endl;
            continue; 
        }

        // 3. Gravity Logic: Start at the bottom row and go UP
        bool placed = false;
        for (int i = rows - 1; i >= 0; i--) {
            if (grid[i][col] == '.') {
                grid[i][col] = currentPlayer;
                placed = true;
                break; // Stop looking once the piece is placed
            }
        }

        if (!placed) {
            cout << "Column " << input << " is full! Pick another one." << endl;
            continue; 
        }

        // 4. Check for Win or Tie
        if (checkWin(grid, rows, cols, currentPlayer)) {
            printBoard(grid, rows, cols);
            cout << "Player " << currentPlayer << " gets 4 in a row vertically and WINS!" << endl;
            gameOver = true;
        } 
        else if (isBoardFull(grid, rows, cols)) {
            printBoard(grid, rows, cols);
            cout << "The board is full. It's a tie!" << endl;
            gameOver = true;
        } 
        else {
            // Swap turns
            if (currentPlayer == 'X') {
                currentPlayer = 'O';
            } else {
                currentPlayer = 'X';
            }
        }
    }

    // 5. Cleanup 2D Array Memory
    for (int i = 0; i < rows; i++) {
        delete[] grid[i];
    }
    delete[] grid;

    return 0;
}

// ============================================================================
// Helper Functions
// ============================================================================

// Prints the board with column headers
void printBoard(char** grid, int rows, int cols) {
    cout << endl;
    cout << "  A B C D E F G" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "| ";
        for (int j = 0; j < cols; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << "-----------------" << endl;
}

// Scans the board strictly for a VERTICAL 4-in-a-row
bool checkWin(char** grid, int rows, int cols, char p) {
    
    // Check Vertical (Stop 3 rows early so we don't scan out of bounds)
    for (int i = 0; i < rows - 3; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == p && grid[i+1][j] == p && grid[i+2][j] == p && grid[i+3][j] == p) {
                return true;
            }
        }
    }

    return false; // No wins found
}

// Checks if the top row is completely full
bool isBoardFull(char** grid, int rows, int cols) {
    for (int j = 0; j < cols; j++) {
        if (grid[0][j] == '.') {
            return false;
        }
    }
    return true;
}