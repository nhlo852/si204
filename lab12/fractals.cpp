#include "fractals.h"
#include <iostream>

using namespace std;

void repeat(string s, int count) {
    if (count <= 0) {
        return;
    }
    cout << s;
    repeat(s, count - 1);
}

void cantor_row(int length) {
    if (length <= 1) {
        cout << "X";
        return;
    }

    int third = length / 3;

    cantor_row(third);
    repeat("_", third);
    cantor_row(third);
}

void cantor_row(int width, int row_index) {
    if (row_index <= 1) {
        repeat("X", width);
        return;
    }

    int next_width = width / 3;
    int next_index = row_index / 3;

    cantor_row(next_width, next_index);
    repeat("_", next_width);
    cantor_row(next_width, next_index);
}

void repeat_cantor_row(int width, int row_index_counter) {
    if (row_index_counter > width) {
        return;
    }

    cantor_row(width, row_index_counter);
    cout << endl;
    
    repeat_cantor_row(width, row_index_counter * 3);
}

void carpet_row(int width, int row_index) {
    if (width <= 1) {
        string DIAMOND = "\u2bc1";
        cout << DIAMOND;
        return;
    }

    int third = width / 3;
    int sub_row = row_index % third; 

    if (row_index >= third && row_index < 2 * third) {
        carpet_row(third, sub_row);
        repeat(" ", third);
        carpet_row(third, sub_row);
    } 
    else {
        carpet_row(third, sub_row);
        carpet_row(third, sub_row);
        carpet_row(third, sub_row);
    }
}

void repeat_carpet_row(int width, int row_index_counter) {
    if (row_index_counter >= width) {
        return;
    }

    carpet_row(width, row_index_counter);
    cout << endl;
    
    repeat_carpet_row(width, row_index_counter + 1);
}

void triangle_row(int height, int row_index) {
    if (height <= 1) {
        cout << "\u25b2";
        return;
    }

    int half = height / 2;

    if (row_index < half) {
        triangle_row(half, row_index);
    } 
    else {
        int sub_row = row_index - half;
        
        triangle_row(half, sub_row);
        
        int num_dots = 2 * height - 2 * row_index - 1;
        repeat(".", num_dots);
        
        triangle_row(half, sub_row);
    }
}

void repeat_triangle_row(int height, int row_index_counter) {
    if (row_index_counter >= height) {
        return;
    }

    int num_spaces = height - 1 - row_index_counter;
    repeat(" ", num_spaces);

    triangle_row(height, row_index_counter);
    cout << endl;

    repeat_triangle_row(height, row_index_counter + 1);
}