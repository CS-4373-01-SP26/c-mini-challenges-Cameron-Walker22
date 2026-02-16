/* 
    Cameron Walker
    Dr. John Hale
    CS-4373 High Performance Computing
    2/11/26

    C Mini Challenges: Problem 2
    Implement Archimedes algorithm to estimate pi for inscribed/circumscribed polygons 
    with n sides, up to 100, doubling n at each step, and time it.
*/

#include <stdio.h>
#include <time.h>
#include <math.h>
#define M_PI 3.14159265358979323846

int main(void) {

    int max_n = 100; // Stopping Criteria
    int start_n = 3; // Starting Criteria

    int n = start_n; // Looping Variable (Sides of Polygons)
    while(n <= max_n) {
        clock_t start = clock();

        double theta = M_PI/n;

        double pi_lower = n*sin(theta); // Inscribed Polygon
        double pi_upper = n*tan(theta); // Circumscribed Polygon

        clock_t end = clock();

        printf("n = %d, pi_lower = %f, pi_upper = %f, diff = %f, clocks = %ld \n",
                n, pi_lower, pi_upper, pi_upper - pi_lower, end-start);

        n *= 2;
    }

    return 0;
}