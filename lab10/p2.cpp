#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unistd.h>
#include "easycurses.h"

using namespace std;

struct Star {
    int r, c;
    char dir;
};

int main() {
    string filename;
    cout << "scenario filename: ";
    cin >> filename;

    ifstream fin(filename);
    string dummy;
    int rows, cols;
    fin >> dummy >> rows >> dummy >> dummy >> cols >> dummy;

    int num_stars;
    fin >> num_stars >> dummy;

    vector<Star> stars(num_stars);
    for (int i = 0; i < num_stars; i++) {
        char p1, comma, p2;
        fin >> p1 >> stars[i].r >> comma >> stars[i].c >> p2 >> stars[i].dir;
    }

    int num_frames;
    fin >> num_frames >> dummy;

    startCurses();

    for (int i = 0; i < num_stars; i++) {
        drawChar('*', stars[i].r, stars[i].c);
    }

    for (int f = 0; f < num_frames; f++) {
        usleep(100000);

        for (int i = 0; i < num_stars; i++) {
            drawChar(' ', stars[i].r, stars[i].c);
        }

        for (int i = 0; i < num_stars; i++) {
            int id;
            char move;
            fin >> id >> move;

            if (move != 'K') {
                stars[i].dir = move;
            }

            if (stars[i].dir == 'N') stars[i].r--;
            else if (stars[i].dir == 'S') stars[i].r++;
            else if (stars[i].dir == 'E') stars[i].c++;
            else if (stars[i].dir == 'W') stars[i].c--;

            if (stars[i].r >= rows) {
                stars[i].r -= 2;
                stars[i].dir = 'N';
            } else if (stars[i].r < 0) {
                stars[i].r += 2;
                stars[i].dir = 'S';
            } else if (stars[i].c >= cols) {
                stars[i].c -= 2;
                stars[i].dir = 'W';
            } else if (stars[i].c < 0) {
                stars[i].c += 2;
                stars[i].dir = 'E';
            }

            drawChar('*', stars[i].r, stars[i].c);
        }
        refreshWindow();
    }

    endCurses();

    return 0;
}