/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Lab 9 Part 1
 * Description: Movie Ratings
 * Date:        2026-02-28
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
    double rating, total = 0;
    int num, userID, movieId, count = 0;
    string junk1, junk2, junk3, act = "o", prog = "huh";
    ifstream fin("ratings.tsv");
    double** R = new double*[610];
    for (int i = 0; i < 610; i++) {
        R[i] = new double[9724];
    }
    for (int j = 0; j < 610; j++) {
        for (int k = 0; k < 9724; k++) {
            R[j][k] = 0;
        }
    }
    fin >> junk1 >> junk2 >> junk3;
    while (fin >> userID >> movieId >> rating) {
        R[userID][movieId] = rating;

    }
    while (act != "quit") {
        cin >> act >> num;
        if (act == "movie") {
            for (int i = 0; i < 9724; i++) {
                total += R[num][i]; 
                count ++;
            }
            cout << total/count;
        }
        if (act == "user") {
            for (int i = 0; i < 610; i++) {
                total += R[i][num]; 
                count ++;
            }
            cout << total/count;

        }
        else break;
    }
    fin.close();
    for (int i = 0; i < 9724; i++) {
        delete [] R[i];
    }
    delete [] R[610];
    delete [] R;

}

