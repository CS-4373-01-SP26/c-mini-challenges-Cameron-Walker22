/* 
    Cameron Walker
    Dr. John Hale
    CS-4373 High Performance Computing
    2/15/26

    C Mini Challenges: Problem 6
    Write a program that accepts a string input from stdio and sends it to a function that transforms it 
    according a transposition function passed in to it as an argument.  The function will print out the string, 
    transform it, and then print out the result. The transposition function, you can assume, simply shuffles 
    the existing characters in the string.  Build a transposition function that reverses the string and apply it.  
    Where appropriate and possible, use dynamic allocation and pointer arithmetic to get the job done.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        char temp = *(str + i);
        *(str + i) = *(str + len - 1 - i);
        *(str + len - 1 - i) = temp;
    }
}

void trans_string(char *str, void (*trans)(char*)) {
    printf("Original: %s\n", str);
    trans(str);
    printf("Transformed: %s\n", str);
}

int main(void) {
    char *input = NULL;
    size_t len = 0;
    int read_len;

    printf("Enter a string: ");
    read_len = getline(&input, &len, stdin);
    if (input[read_len - 1] == '\n') {
        input[read_len - 1] = '\0';
    }

    trans_string(input, reverse);

    free(input);
    return 0;
}