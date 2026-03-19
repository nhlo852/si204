#include <iostream>
#include <string>

using namespace std;

void printMap(int** map, int rows, int cols);

int main() {
    int rows, cols;
    string junk;
    
    cin >> rows >> junk >> cols >> junk;
    
    int** map = new int*[rows];
    for (int i = 0; i < rows; i++) {
        map[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            cin >> map[i][j];
        }
    }
    
    string command;
    cout << "> ";
    
    while (cin >> command && command != "quit") {
        if (command == "crash") {
            int r, c;
            string j1, j2, j3;
            
            cin >> r >> j1 >> j2 >> c >> j3;
            
            if (r >= 0 && r < rows && c >= 0 && c < cols) {
                map[r][c]++;
            }
            
            printMap(map, rows, cols);
        }
        
        cout << "> ";
    }
    
    for (int i = 0; i < rows; i++) {
        delete[] map[i];
    }
    delete[] map;
    
    return 0;
}

void printMap(int** map, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << map[i][j];
            if (j < cols - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}