#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
    string name;
    int number;
};

int main() {
    string filename, namee, junk1;
    int num, size, i = 0, g = 0;
    char junk;
    cout << "File: ";
    cin >> filename;
    ifstream fin(filename);

    if (!fin) { 
        cout << "Could not open file '" << filename << "'" << endl;
    return 1;
    }

    fin >> junk >> junk >> size;
    Node* list = new Node[size];
    while (fin >> namee >> num) {
        list[i].name = namee;
        list[i].number = num;
        i++;
        
    }

    string cmd = "a";
    while (cmd != "quit") {
        int val;
        string target;
        cout << "> ";
        cin >> cmd >> val >> junk1 >> target;

        if (cmd == "give") {
            for (int i = 0; i < size; i++) {
                if (list[i].name == target) {
                    list[i].number += val;
                    cout << list[i].number << endl;
                    g = -100;
                }
                g++;
            }
        }
        else if (cmd == "take") {
            for (int i = 0; i < size; i++) {
                if (list[i].name == target) {
                    list[i].number -= val;
                    cout << list[i].number << endl;
                    g = -100;
                }
                g++;
            }
        }
        if (g == size) cout << "Name not found";
        g = 0;

   
    }
    delete [] list;
    fin.close();
    return 0;
}
