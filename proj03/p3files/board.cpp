#include "board.h"
#include <iostream>
#include <fstream>

using namespace std;

Board* load_board(string filename) {
    ifstream fin(filename);
    if (!fin) {
        return nullptr;
    }

    Board* b = new Board;
    char x;
    fin >> b->rows >> x >> b->cols >> b->num_Zs;

    string dummy;
    getline(fin, dummy);

    b->grid = new char*[b->rows];
    b->spawns = new Position[b->num_Zs];
    int z_count = 0;

    for (int r = 0; r < b->rows; r++) {
        b->grid[r] = new char[b->cols];
        for (int c = 0; c < b->cols; c++) {
            char ch = fin.get();
            if (ch == 'X') {
                b->goal.r = r;
                b->goal.c = c;
                b->grid[r][c] = ' ';
            } else if (ch == 'Y') {
                b->start.r = r;
                b->start.c = c;
                b->grid[r][c] = ' ';
            } else if (ch == 'Z') {
                b->spawns[z_count].r = r;
                b->spawns[z_count].c = c;
                z_count++;
                b->grid[r][c] = ' ';
            } else {
                b->grid[r][c] = ch;
            }
        }

        char next = fin.peek();
        while (next == '\r' || next == '\n') {
            fin.get();
            next = fin.peek();
        }
    }

    return b;
}

void print_board(Board* b) {
    cout << "Goal position: (" << b->goal.r << "," << b->goal.c << ")\n";
    cout << "Player start: (" << b->start.r << "," << b->start.c << ")\n";
    cout << "Spawn spots :";
    
    for (int i = 0; i < b->num_Zs; i++) {
        cout << " (" << b->spawns[i].r << "," << b->spawns[i].c << ")";
    }
    cout << "\n";

    for (int r = 0; r < b->rows; r++) {
        for (int c = 0; c < b->cols; c++) {
            cout << "'" << b->grid[r][c] << "'";
            if (c < b->cols - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

void free_board(Board* b) {
    if (!b) return;
    
    for (int r = 0; r < b->rows; r++) {
        delete[] b->grid[r];
    }
    delete[] b->grid;
    delete[] b->spawns;
    delete b;
}