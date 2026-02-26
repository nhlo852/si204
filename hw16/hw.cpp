/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Lowest Terms Fraction Checker
 * Description: Reads a comma-separated list of fractions ending with a semicolon and prints only those in their lowest terms.
 * Date:        2026-02-19
 ******************************************************************************/

#include <iostream>
using namespace std;

int get_gcd(int a, int b);

int main() {
    int num, den;
    char slash, sep;

    // Loop continuously until we hit the semicolon break condition
    while (true) {
        // Number, character ('/'), number, character (',' or ';')
        cin >> num >> slash >> den >> sep;

        // if the GCD of the numerator and denominator is 1
        if (get_gcd(num, den) == 1) {
            cout << num << "/" << den << " is in lowest terms!" << endl;
        }

        // If the separator we just read is the semicolon, terminate the loop
        if (sep == ';') {
            break;
        }
    }

    return 0;
}

// Greatest Common Divisor 
int get_gcd(int a, int b) {
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}