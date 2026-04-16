#include <iostream>

using namespace std;


void printBoard(char** grid, int rows, int cols);
bool checkWin(char** grid, int rows, int cols, char player);
bool isBoardFull(char** grid, int rows, int cols);

int main() {
    int rows = 6;
    int cols = 7;

    char** grid = new char*[rows];
    for (int i = 0; i < rows; i++) {
        grid[i] = new char[cols];
        
        // Fill the board with periods '.'
        for (int j = 0; j < cols; j++) {
            grid[i][j] = '.';
        }
    }

    bool gameOver = false;

    while (!gameOver) {
        printBoard(grid, rows, cols);
        int col;
        char letter;
        cout << "Column and Letter: ";
        cin >> col >> letter;
        bool placed = false;
        for (int i = rows - 1; i >= 0; i--) {
            if (grid[i][col] == '.') {
                grid[i][col] = letter;
                placed = true;
                break; 
            }
        }
        if (checkWin(grid, rows, cols, letter)) {
            printBoard(grid, rows, cols);
            gameOver = true;
        } 
    }

    for (int i = 0; i < rows; i++) {
        delete[] grid[i];
    }
    delete[] grid;

    return 0;
}


void printBoard(char** grid, int rows, int cols) {
    cout << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool checkWin(char** grid, int rows, int cols, char p) {
    
    for (int i = 0; i < rows - 3; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(grid[i][j] == '.') && !(grid[i+1][j] == '.') && !(grid[i+2][j] == '.') && !(grid[i+3][j] == '.')) {
                return true;
            }
        }
    }

    return false; 
}

