/* 
    Cameron Walker
    Dr. John Hale
    CS-4373 High Performance Computing
    2/11/26

    C Mini Challenges: Problem 1
    Print “Hello, NAME” where NAME is input from the keyboard.
*/

#include <stdio.h>

int main(void) {
    char name[50];

    printf("Please Input Your Name: ");
    scanf("%49s", name);
    printf("Hello, %s!\n", name);

    return 0;
}