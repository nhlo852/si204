/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       prac.c
 * Description: Computes the product of all integers between two given numbers.
 * Date:        2026-04-23
 ******************************************************************************/

#include <stdio.h>

int main() {
    int n1, n2;
    
    printf("Enter two integers: ");
    scanf("%d %d", &n1, &n2);

    // Using long long to prevent integer overflow for larger products
    long long product = 1;
    
    for (int i = n1; i <= n2; i++) {
        product *= i;
    }

    printf("Product of all integers between %d and %d is %lld\n", n1, n2, product);

    return 0;
}