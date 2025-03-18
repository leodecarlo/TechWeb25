#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Number of points to sample
    int npoints = (int)1e10;  // Increase for better accuracy
    int circle_count = 0;

    // Seed the random number generator
    srand((unsigned)time(NULL));

    // Record the start time
    clock_t start = clock();

    // Generate random points and count how many fall inside the quarter-circle
    for (int i = 0; i < npoints; i++) {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;

        if ((x * x + y * y) <= 1.0) {
            circle_count++;
        }
    }

    

    // Estimate pi
    double pi_estimate = 4.0 * (double)circle_count / (double)npoints;

    // Record the end time
    clock_t end = clock();

    // Compute the elapsed CPU time in seconds: The difference (end - start) is the number of CPU clock ticks spent executing the loop.
    double cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Total points: %d\n", npoints);
    printf("Points inside quarter-circle: %d\n", circle_count);
    printf("Estimated Pi = %f\n", pi_estimate);
    printf("Loop time (CPU time): %f seconds\n", cpu_time_used);

    return 0;
}
