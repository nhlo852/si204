/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Car Data Tracker
 * Description: Reads car locations and speeds, then prints where they are 
 * for 8 hours.
 * Date:        2026-03-24
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Make a struct box to hold each car's info
struct Car {
    char tag;
    double location;
    double velocity;
};

int main() {
    string filename;
    cin >> filename; 

    ifstream fin(filename);
    
    // Stop if the file doesn't exist
    if (!fin) {
        return 0; 
    }

    int numCars;
    string junk1, junk2;
    
    // Read the top line
    fin >> junk1 >> junk2 >> numCars;

    // Make an array for the cars
    Car cars[100];

    // Read exactly that many cars
    for (int i = 0; i < numCars; i++) {
        // junk1 catches "pos", junk2 catches "vel"
        fin >> cars[i].tag >> junk1 >> cars[i].location >> junk2 >> cars[i].velocity;
    }
    fin.close();

    // Loop from hour 0 to hour 8
    for (int h = 0; h <= 8; h++) {
        cout << "hour " << h << " ";
        
        // Print the spot for every car
        for (int i = 0; i < numCars; i++) {
            // Starting spot + (speed * number of hours)
            double currentSpot = cars[i].location + (cars[i].velocity * h);
            
            // Print format [A:-120]
            cout << "[" << cars[i].tag << ":" << currentSpot << "]";
        }
        
        // Move to the next line for the next hour
        cout << endl; 
    }

    return 0;
}