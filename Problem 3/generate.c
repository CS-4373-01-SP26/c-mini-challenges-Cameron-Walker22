/* 
    Cameron Walker
    Dr. John Hale
    CS-4373 High Performance Computing
    2/15/26

    nxn Integer M-V File Generator
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 1000;
    FILE *fp = fopen("mv_large.txt", "w");

    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Write matrix dimensions
    fprintf(fp, "%d %d\n", n, n);

    // Generate matrix values (small integers to avoid overflow)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(fp, "%d ", rand() % 10);
        }
        fprintf(fp, "\n");
    }

    // Write vector length
    fprintf(fp, "%d\n", n);

    // Generate vector
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", rand() % 10);
    }

    fprintf(fp, "\n");

    fclose(fp);
    return 0;
}
