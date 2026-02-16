/*
    Cameron Walker
    Dr. John Hale
    CS-4373 High Performance Computing
    2/15/2026

    C Mini Challenges: Problem 4
    Compare the speed of *,/,sqrt, sin operations/functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ITER 1000000
#define REPEATS 100

// Function to compute mean and standard deviation
void mean_stddev(double clocks[], double *avg, double *stddev) {
    double mean = 0;
    for (int i = 0; i < REPEATS; i++) mean += clocks[i];
    mean /= REPEATS;

    double sd = 0;
    for (int i = 0; i < REPEATS; i++) sd += (clocks[i] - mean) * (clocks[i] - mean);
    sd = sqrt(sd / REPEATS);

    *stddev = sd;  // store standard deviation
    *avg = mean;   // store average
}

int main(void) {
    clock_t begin = clock();

    double *nums = malloc(ITER * sizeof(double));
    if (nums == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    double result;
    double clocks_mul[REPEATS], clocks_div[REPEATS], clocks_sqrt[REPEATS], clocks_sin[REPEATS];

    for (int r = 0; r < REPEATS; r++) {
        // Generate new random numbers each repeat
        for (int i = 0; i < ITER; i++) {
            nums[i] = ((double)rand() / RAND_MAX) * 10.0;
        }

        clock_t start, stop;

        // Multiplication
        start = clock();
        for (int i = 0; i < ITER; i++) result = nums[i] * 10.0;
        stop = clock();
        clocks_mul[r] = stop-start;

        // Division
        start = clock();
        for (int i = 0; i < ITER; i++) result = nums[i] / 10.0;
        stop = clock();
        clocks_div[r] = stop-start;

        // Square root
        start = clock();
        for (int i = 0; i < ITER; i++) result = sqrt(nums[i]);
        stop = clock();
        clocks_sqrt[r] = stop-start;

        // Sine
        start = clock();
        for (int i = 0; i < ITER; i++) result = sin(nums[i]);
        stop = clock();
        clocks_sin[r] = stop-start;
    }

    // Average and Standard Deviation
    double mean, sd;

    mean_stddev(clocks_mul, &mean, &sd);
    printf("Multiplication: Mean = %f clocks, StdDev = %f clocks\n", mean, sd);

    mean_stddev(clocks_div, &mean, &sd);
    printf("Division      : Mean = %f clocks, StdDev = %f clocks\n", mean, sd);

    mean_stddev(clocks_sqrt, &mean, &sd);
    printf("Square Root   : Mean = %f clocks, StdDev = %f clocks\n", mean, sd);

    mean_stddev(clocks_sin, &mean, &sd);
    printf("Sine          : Mean = %f clocks, StdDev = %f clocks\n", mean, sd);

    clock_t end = clock();
    printf("Total Time    : Clocks = %ld \n", end-begin);

    free(nums);
    return 0;
}