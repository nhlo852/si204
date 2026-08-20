/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       prac1.c
 * Description: Reads numbers into a dynamically allocated array and prints 
 * them in reverse order.
 * Date:        2026-04-26
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("How many? ");
    int n;
    scanf("%d", &n);

    // Dynamically allocate memory for the array in C
    int* A = (int*)malloc(n * sizeof(int));
    
    // Read numbers into the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Print in reverse order
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(A);
    
    return 0;
}