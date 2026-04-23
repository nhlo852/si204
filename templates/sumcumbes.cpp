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
    
    cout << "Enter a number: ";
    cin >> n;
    
    int result = sumOfCubes(n);
    
    cout << "The sum of cubes up to " << n << " is: " << result << "\n";
    
    return 0;
}