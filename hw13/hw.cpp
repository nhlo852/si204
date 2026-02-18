/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Hollow Rectangle with Offset
 * Description: Draws a hollow rectangle using height, width, and offset.
 * Date:        2026-02-07
 ******************************************************************************/
#include <iostream>
using namespace std;

int main() {
    int height, width, offset;
    cout << "Enter height (greater than 2): ";
    cin >> height;
    cout << "Enter width  (greater than 2): ";
    cin >> width;
    cout << "Enter offset: ";
    cin >> offset;

    for (int i = 0; i < height; i++) {
        for (int s = 0; s < offset; s++) { // Print the offset spaces for every row
            cout << " ";
        }
        if (i == 0 || i == height - 1) { // Decide what to print based on the row number
            for (int j = 0; j < width; j++) {  // Print full width of stars
                cout << "*";
            }
        } 
        else { // Print star, then spaces, then star
            cout << "*";
            for (int j = 0; j < width - 2; j++) {
                cout << " ";
            }
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}