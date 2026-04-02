/******************************************************************************
 * Practicum Master Template
 * Covers: Functions, Arrays, Strings, Pass by Address, 2D Arrays
 ******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

// ============================================================================
// 1. FUNCTION PROTOTYPES
// ============================================================================
// Pass by Address: Requires a pointer (*) to catch the address
void changeValue(int* numPtr); 

// Strings & 1D Arrays: Arrays always need their size passed with them!
void printArrayAndString(int* arr, int size, string word);

// 2D Arrays: Requires a pointer-to-a-pointer (**)
void fill2DGrid(int** grid, int rows, int cols);


// ============================================================================
// 2. MAIN FUNCTION
// ============================================================================
int main() {
    // --- STRINGS ---
    string myWord = "Navy";

    // --- PASS BY ADDRESS ---
    int myScore = 95;
    // Use '&' to send the physical memory address, not just the number 95
    changeValue(&myScore); 

    // --- 1D ARRAYS (Dynamic Allocation) ---
    int size = 5;
    int* myArray = new int[size];
    
    // Call function
    printArrayAndString(myArray, size, myWord);

    // --- 2D ARRAYS (Dynamic Allocation) ---
    int rows = 3;
    int cols = 4;
    
    // Step A: Make the "spine" (array of pointers)
    int** myGrid = new int*[rows];
    
    // Step B: Attach the columns to each row
    for (int i = 0; i < rows; i++) {
        myGrid[i] = new int[cols];
    }
    
    // Call function
    fill2DGrid(myGrid, rows, cols);


    // --- CLEANUP MEMORY (Don't forget this!) ---
    // 1D cleanup
    delete[] myArray;

    // 2D cleanup (Delete inside-out: columns first, then the spine)
    for (int i = 0; i < rows; i++) {
        delete[] myGrid[i];
    }
    delete[] myGrid;

    return 0;
}


// ============================================================================
// 3. FUNCTION DEFINITIONS
// ============================================================================

void changeValue(int* numPtr) {
    // Use '*' to "dereference" and change the actual value inside the box
    *numPtr = 100; 
}

void printArrayAndString(int* arr, int size, string word) {
    // Standard 1D loop
    for (int i = 0; i < size; i++) {
        arr[i] = i * 10; // Just putting some junk data in
    }
    
    // Strings act just like arrays of characters!
    cout << "First letter is: " << word[0] << endl;
}

void fill2DGrid(int** grid, int rows, int cols) {
    // Standard 2D nested loops (Rows outer, Cols inner)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = 0; // Fill every cell with 0
        }
    }
}