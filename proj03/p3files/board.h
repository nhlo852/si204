#pragma once
#include <string>

using namespace std;

struct Position {
    int r;
    int c;
};

struct Board {
    int rows;
    int cols;
    int num_Zs;
    char** grid;
    Position goal;
    Position start;
    Position* spawns;
};

Board* load_board(string filename);
void print_board(Board* b);
void free_board(Board* b);