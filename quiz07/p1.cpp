#include<iostream>
#include<string>
#include<fstream>
#include<cmath>

using namespace std;
struct fruit {
    string type;
    double price;
};

int main() {
    string filename;
    cout << "Filename: ";
    cin >> filename;

    ifstream fin(filename);
    if (!fin) { 
        cout << "File not found!" << endl;
    return 1;
    }

    int numFruits, i = 0;
    string type1, junk, act = "p";
    char junk1;
    double price1, weight, finalPrice = 0;
    bool found = false;
    bool endgame = true;

    fin >> numFruits >> junk;
    fruit* fruits = new fruit[numFruits];
    while (fin >> type1 >> junk1 >> price1) {
        fruits[i].type = type1;
        fruits[i].price = price1;
        i++;
        
    }
    while (endgame) {
        cout << "command: ";
        cin >> act;
        if (act == "add") {
            cin >> weight >> junk >> type1;
            for (int j = 0; j < numFruits; j++) {
                if (fruits[j].type == type1) {
                    finalPrice += (weight * fruits[j].price);
                    found = true;
                    break;
                }
            }
            if (found == false) cout << "Error! " << type1 << " not found!" << endl;
        }

        if (act == "price") {
            cin >> type1;
            for (int k = 0; k < numFruits; k++) {
                if (fruits[k].type == type1) {
                    cout << type1 << " are $" << fruits[k].price << " per pound" << endl;
                    found = true;
                    break;
                }
            }
            if (found == false) cout << "Error! " << type1 << " not found!" << endl;
        } 
        found = false;
        if (act == "checkout") {
            cout << "total is $" << finalPrice <<  endl;
            endgame = false;
        }
    }


    delete [] fruits;
    return 0;
}

