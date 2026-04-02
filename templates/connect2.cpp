/******************************************************************************
 * Title:       Sequential Connect 4 (Solo Mode)
 * Description: A 6x7 grid that automatically fills from bottom-left to top-right. 
 * The user continuously inputs letters. 4 of the same letter vertically wins.
 ******************************************************************************/

#include <iostream>

using namespace std;

// Function Prototypes
void printBoard(char** grid, int rows, int cols);

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

    // Keep track of exactly where the next piece MUST go
    // Start at bottom-left: row 5 (bottom), col 0 (far left)
    int currentRow = rows - 1; 
    int currentCol = 0;        
    
    bool gameOver = false;

    // 2. Main Game Loop (Stops if you win, or if the board fills completely)
    while (!gameOver && currentCol < cols) {
        printBoard(grid, rows, cols);
        
        char input;
        cout << "Enter any letter to place at column " 
             << (char)('A' + currentCol) << ": ";
        cin >> input;

        // Place the letter in the mandatory spot
        grid[currentRow][currentCol] = input;

        // 3. Check for a Vertical Win
        // We only need to check if there is room for 4 pieces below the current one
        if (currentRow <= rows - 4) {
            if (grid[currentRow][currentCol] == input &&
                grid[currentRow + 1][currentCol] == input &&
                grid[currentRow + 2][currentCol] == input &&
                grid[currentRow + 3][currentCol] == input) {
                
                printBoard(grid, rows, cols);
                cout << "You stacked four '" << input << "'s vertically and WON!" << endl;
                gameOver = true;
                break; 
            }
        }

        // 4. Move the target spot for the NEXT turn
        currentRow--; // Move UP one row

        // If we just filled the top row of the current column
        if (currentRow < 0) {
            currentRow = rows - 1; // Reset to the bottom row
            currentCol++;          // Move to the next column to the right
        }
    }

    // 5. Check for a Full Board
    // If the loop finished because currentCol hit the max (board full) and nobody won
    if (!gameOver) {
        printBoard(grid, rows, cols);
        cout << "The board is entirely full. Game over!" << endl;
    }

    // 6. Cleanup 2D Array Memory
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