#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define CARS 5
#define ROADS 2

void *cross(void *argc) {
    printf("(%u) Waiting\n", pthread_self());
    sleep(1);
    printf("(%u) Crossing\n", pthread_self());
    sleep(1);
    printf("(%u) Crossed\n", pthread_self());
    pthread_exit(0);

}

int car() {
    pthread_t tid[CARS];

    for (int i = 0; i < CARS; ++i) {
        pthread_create(tid + i, NULL, cross, NULL);
    }

    for (int i = 0; i < CARS; ++i) {
        pthread_join(tid[i], NULL);
    }
}