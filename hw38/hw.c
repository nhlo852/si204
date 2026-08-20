/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       hw.c
 * Description: Reads an array of numbers and processes commands to either 
 * show them as asterisks or swap their positions.
 * Date:        2026-04-26
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int readN();
int* readData(int n);
void show(int* A, int n);
void swap(int* A, int n);

int main() {
    int n = readN();
    int* A = readData(n);

    char cmd[20]; // C-string to hold the command
    printf("cmd: ");
    
    // Read strings and check if it's NOT "quit" using strcmp
    while (scanf("%19s", cmd) == 1 && strcmp(cmd, "quit") != 0) {
        if (strcmp(cmd, "show") == 0) {
            show(A, n);
        } 
        else if (strcmp(cmd, "swap") == 0) {
            swap(A, n);
        }

        printf("cmd: ");
    }

    // Free dynamically allocated memory
    free(A);
    return 0;
}

// Reads the "N = 5" format
int readN() {
    char c1, c2;
    int n;
    // Reads two characters and an integer, skipping whitespace
    scanf(" %c %c %d", &c1, &c2, &n);
    return n;
}

// Dynamically allocates the array and reads data
int* readData(int n) {
    int* A = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    return A;
}

// Prints the array elements as rows of asterisks
void show(int* A, int n) {
    for (int i = 0; i < n; i++) {
        printf("[%d] ", i);
        for (int j = 0; j < A[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Swaps two elements in the array
void swap(int* A, int n) {
    int i, j;
    scanf("%d %d", &i, &j);
    int t = A[i];
    A[i] = A[j];
    A[j] = t;
}