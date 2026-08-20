/************************************************
 * Reads numbers from standard input (std::cin),
 * computes min, max, and average of the numbers,
 * and prints these values. Added functionality of
 * specifying whhich of the computations to print
 * and calculate.
 ************************************************/
#include <iostream>
#include <doublesort.h>

int main(int argc, char* argv[]) {
    double next, min, max, sum;
    doubleNode numbers; 
    std::string arg;

    // Read the first number and initialize.
    if (!(std::cin >> next)) {
        return 0;  // empty input — nothing to report
    }
    min = max = sum = next;
    int count = 1;

    // Read subsequent numbers, updating running stats.
    while (std::cin >> next) {
        add2front(next, numbers); 
        sum += next;
        ++count;
        if (next < min) min = next;
        if (next > max) max = next;
    }
    int median = count/2;

    //convert double node to array
    double* ArrayOfNums = new double[count];
    for (int i = 0; i < count; i++){
       

    }


    doublesort();
    
    

    // Print results.
    for (int i = 0; i < argc; i++) {
        arg = argv[i];
    }
    if (arg == "-max") {
        std::cout << "max = "<< max <<'\n';
    return 0;
    }
    if (arg == "-min") {
        std::cout << "min = " << min << '\n';
    return 0;
    }
    if (arg == "-average") {
        std::cout << "avg = " << sum / count << '\n';
    return 0;
    }
    if (arg == "-median") {
        std::cout << min << ' ' << max << ' ' << sum / count << '\n';
    return 0;
    }
    else {
        std::cout << "min = "
    }
}