#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

int monte_carlo_multitasks(int intervals) {
    clock_t start, delta;
    start = clock();

    srand(time(NULL));

    int circle_points = 0;
    int square_points = 0;
    double pi;
    for (int i = 0; i < intervals * intervals; ++i) {
        double rand_x = (double) rand() / RAND_MAX;
        double rand_y = (double) rand() / RAND_MAX;

        if ((rand_x * rand_x + rand_y * rand_y) <= 1) {
            circle_points++;
        }

        square_points++;
    }
    pi = (double) (4.0 * circle_points) / square_points;
    printf("Estimated PI is %lf in %d times\t", pi, intervals * intervals);
    delta = clock() - start;
    printf("The time taken : %lf seconds\n", (double) delta / CLOCKS_PER_SEC);
    return 0;
}