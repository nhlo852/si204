/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       prac2.c
 * Description: Reads a string from the user and prints it in reverse order.
 * Date:        2026-04-26
 ******************************************************************************/

#include <stdio.h>
#include <string.h>

// Function prototype using a C-style string (character array)
void print_reverse(char s[]);

int main() {
    // Dynamically sizing strings isn't automatic in C, so we set a fixed buffer size
    char s[100]; 

    printf("Enter a string: ");
    // %99s ensures we don't overflow the buffer (leaving 1 spot for the null terminator '\0')
    scanf("%99s", s);

    printf("The reverse of '%s' is '", s);
    print_reverse(s);
    printf("'\n");

    return 0;
}

// Prints the input string reversed
void print_reverse(char s[]) {
    // strlen() from <string.h> gives us the length of the string
    int length = strlen(s);
    
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", s[i]);
    }
}