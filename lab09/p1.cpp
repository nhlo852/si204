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
    double rating;
    int num, userID, movieId;
<<<<<<< HEAD
    string junk1, junk2, junk3, act = "o", prog = "huh";
=======
    string junk1, junk2, junk3, act = "";
    
>>>>>>> 472bda79fb8cf19cdbce22699b8329ddc9471e7a
    ifstream fin("ratings.tsv");
    if (!fin) {
        cout << "Error opening file." << endl;
        return 1;
    }

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
<<<<<<< HEAD

    }
    while (cin >> act && act != "quit") {
        double total = 0;
        int count = 0;
        cin >>  num;
        if (act == "movie") {
            for (int i = 0; i < 9724; i++) {
                total += R[i][num]; 
                count ++;
            }
            cout << total/count;
        }
        if (act == "user") {
            for (int i = 0; i < 610; i++) {
                total += R[num][i]; 
                count ++;
            }
            cout << total/count;

        }
=======
>>>>>>> 472bda79fb8cf19cdbce22699b8329ddc9471e7a
    }
    fin.close();

    while (cin >> act && act != "quit") {
        cin >> num;
        double total = 0;
        int count = 0;
        
        if (act == "user") {
            for (int i = 0; i < 9724; i++) {
                if (R[num][i] != 0) {
                    total += R[num][i]; 
                    count++;
                }
            }
            if (count > 0) cout << total / count << endl;
            else cout << "No ratings" << endl;
        }
        else if (act == "movie") {
            for (int i = 0; i < 610; i++) {
                if (R[i][num] != 0) {
                    total += R[i][num]; 
                    count++;
                }
            }
            if (count > 0) cout << total / count << endl;
            else cout << "No ratings" << endl;
        }
        else {
            cout << "Unknown command" << endl;
        }
    }

    // Safely delete exactly the 610 rows we allocated
    for (int i = 0; i < 610; i++) {
        delete [] R[i];
    }
    delete [] R;

    return 0;
}