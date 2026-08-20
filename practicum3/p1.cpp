#include <iostream>

using namespace std;

int sumOfCubes(int n) {
    if (n <= 0) {
        return 0;
    }
    
    return (n * n * n) + sumOfCubes(n - 1);
}

int main() {
    int n;
    
    cout << "Enter n: ";
    cin >> n;
    
    int result = sumOfCubes(n);
    
    cout << result << endl;
    
    return 0;
}