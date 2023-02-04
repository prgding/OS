#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

void calculate_pi(int intervals);

int monte_carlo_multitasks() {

    clock_t start, delta;
    start = clock();

    for (int i = 0; i < 10; ++i) {
        calculate_pi(2000 * (i + 1));
    }

    delta = clock() - start;

    printf("Total time : %lf seconds\n", (double) delta / CLOCKS_PER_SEC);
    return 0;
}


void calculate_pi(int intervals) {
    clock_t start, delta;
    double used_time = 0;
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
    used_time = (double) delta / CLOCKS_PER_SEC;
    printf("The time taken : %lf seconds\n", used_time);
}