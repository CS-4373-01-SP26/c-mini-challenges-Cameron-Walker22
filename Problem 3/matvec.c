/* 
    Cameron Walker
    Dr. John Hale
    CS-4373 High Performance Computing
    2/15/26

    C Mini Challenges: Problem 3
    Implement matrix – vector multiplication. 
    Read in the following text file (mv.txt) which contains the matrix and vector to be multiplied. 
    Print your answer to the screen and time the computation. 
    The format of mv.txt is: line 1 contains numrows, numcols. 
    The next numrows contains the rows of the matrix, each with numcols integer values. 
    The next line contains the length of the vector. The next line contains the vector of that length.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    FILE *fp = fopen("mv_large.txt", "r"); // Open mv file
    if (fp == NULL) {
        printf("Error, No File Found\n");
        return 1;
    }

    int *A, *x, *y; // Create pointers for the Matrix, Vector, and Resultant Vector

    int numrows, numcols;
    if (fscanf(fp, "%d %d", &numrows, &numcols) != 2) {
        printf("File format error\n");
        return 1;
    }

    A = malloc(numrows * numcols * sizeof(int)); // Allocate space for the matrix
    if (A == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    for (int i = 0; i < numrows; i++) {
        for (int j = 0; j < numcols; j++) {
            fscanf(fp, "%d", &A[i*numcols + j]);
        }
    }

    int veclen;
    fscanf(fp, "%d", &veclen);
    if (veclen != numcols) {
        printf("Size Incompatibility between Vector and Matrix\n");
        return 1;
    }

    x = malloc(veclen * sizeof(int)); // Allocate space for x
    for (int i = 0; i < veclen; i++) {
        fscanf(fp, "%d", &x[i]);
    }

    y = malloc(numrows * sizeof(int)); // Allocate space for y

    fclose(fp); // Close file

    clock_t start = clock();

    // y = Ax vector multiplication
    for (int i = 0; i < numrows; i++) {
        y[i] = 0;
        
        for (int j = 0; j < numcols; j++) {
            y[i] += A[i*numcols + j] * x[j];
        }
    }

    clock_t end = clock();

    // Print Clocks
    printf("Clocks: %ld \n", end-start);

    // Print Resultant Vector
    for (int i = 0; i < numrows; i++) {
        printf("%d\n", y[i]);
    }

    // Make sure to free memory
    free(A); 
    free(x); 
    free(y);
    return 0;
}