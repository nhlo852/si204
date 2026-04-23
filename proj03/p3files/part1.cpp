#include <iostream>
#include <string>
#include "board.h"

using namespace std;

int main() {
    string filename;
    cout << "board file: ";
    cin >> filename;

    Board* b = load_board(filename);
    if (!b) {
        cout << "Error: File not found!\n";
        return 1;
    }

    print_board(b);
    free_board(b);

    return 0;
}