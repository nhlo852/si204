/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Quiz 5
 * Description: 
 * Date:        2026-03-19
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
    char junk;
    int num;
    double arrVal;
    cin >> junk >> junk >> num;

    double* x = new double[num];
    double* y = new double[num];
    double* z = new double[num];
    double* sum = new double[num];



    if (num > 1) {
    cin >> junk >> junk;
    for (int i = 0; i < num; i++) {
        cin >> junk >> arrVal;
        x[i] = arrVal;
    }
    cin >> junk;

    cin >> junk >> junk;
    for (int i = 0; i < num; i++) {
        cin >> junk >> arrVal;
        y[i] = arrVal;
    }
    cin >> junk;

    cin >> junk >> junk;
    for (int i = 0; i < num; i++) {
        cin >> junk >> arrVal;
        z[i] = arrVal;
    }
    cin >> junk;

    cout << "X - Y + Z = (";
    for (int i = 0; i < num; i++) {
        sum[i] = x[i] - y[i] + z[i];
        if (i != num-1) cout << sum[i] << ", ";
        else cout << sum[i];
    }
    cout << ")" << endl;
    }

    else {
    cin >> junk >> junk >> junk;
    for (int i = 0; i < num; i++) {
        cin >> arrVal;
        x[i] = arrVal;
    }
    cin >> junk;

    cin >> junk >> junk >> junk;
    for (int i = 0; i < num; i++) {
        cin >>  arrVal;
        y[i] = arrVal;
    }
    cin >> junk;

    cin >> junk >> junk >> junk;
    for (int i = 0; i < num; i++) {
        cin >> arrVal;
        z[i] = arrVal;
    }
    cin >> junk;

    cout << "X - Y + Z = (";
    for (int i = 0; i < num; i++) {
        sum[i] = x[i] - y[i] + z[i];
        if (i != num-1) cout << sum[i] << ", ";
        else cout << sum[i];
    }
    cout << ")" << endl;

    }
    delete [] x;
    delete [] y;
    delete [] z;
    delete [] sum;


    

}

