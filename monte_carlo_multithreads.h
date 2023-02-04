#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

void *calculate_pi2(void *arg);

int monte_carlo_multithreads() {
    clock_t start, delta;
    start = clock();

    pthread_t calculate_pi_threads[10];

    int args[10];

    for (int i = 0; i < 10; ++i) {
        args[i] = 2000 * (i + 1);
        pthread_create(calculate_pi_threads + i, NULL, calculate_pi2, args + i);
    }

    for (int i = 0; i < 10; ++i) {
        pthread_join(calculate_pi_threads[i], NULL);
    }

    delta = clock() - start;

    printf("Total time : %lf seconds\n", (double) delta / CLOCKS_PER_SEC);
    return 0;
}

void *calculate_pi2(void *arg) {
    clock_t start, delta;
    double used_time = 0;
    start = clock();

    srand(time(NULL));
    int circle_points = 0;
    int square_points = 0;
    int intervals = *((int *) arg);


    for (int i = 0; i < intervals * intervals; ++i) {
        double rand_x = (double) rand() / RAND_MAX;
        double rand_y = (double) rand() / RAND_MAX;

        if ((rand_x * rand_x + rand_y * rand_y) <= 1) {
            circle_points++;
        }

        square_points++;
    }
    double pi = (double) (4.0 * circle_points) / square_points;
    printf("Estimated PI is %lf in %d times\t", pi, intervals * intervals);
    delta = clock() - start;
    used_time = (double) delta / CLOCKS_PER_SEC;
    printf("The time taken : %lf seconds\n", used_time);
}