#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
    // Initialize MPI
    MPI_Init(&argc, &argv);

    // Get the rank (ID) of the process and the total number of processes
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Total number of points 
    long npoints = (int)1e10;
    // Compute how many points each process should handle
    long points_per_proc = npoints / size;
    // Local count of points inside the circle
    long local_count = 0;

    // Seed the random number generator differently for each rank
    srand(time(NULL) + rank);

    // Record the start time (on each process; we'll use rank 0's value for overall timing)
    clock_t start = clock();

    // Generate random points and count how many fall inside the unit circle
    for (long i = 0; i < points_per_proc; i++) {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        if (x * x + y * y <= 1.0) {
            local_count++;
        }
    }

    // The master will collect the total count from all processes
    long global_count = 0;
    // Use MPI_Reduce to sum up local_count into global_count on rank 0
    MPI_Reduce(&local_count, &global_count, 1, MPI_LONG, MPI_SUM, 0, MPI_COMM_WORLD);

    // On rank 0, record the end time and compute pi, including the reduction time.
    if (rank == 0) {
        
        // Estimate pi using the total points and points inside the circle
        double pi_estimate = 4.0 * (double)global_count / (double)npoints;

        clock_t end = clock();
        // Compute the elapsed CPU time in seconds
        double cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;

        printf("Total points: %ld\n", npoints);
        printf("Points inside circle: %ld\n", global_count);
        printf("Estimated Pi = %f\n", pi_estimate);
        printf("Elapsed CPU time (seconds) = %f\n", cpu_time_used);
    }

    // Finalize MPI
    MPI_Finalize();
    return 0;
}
