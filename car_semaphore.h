#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define CARS 5
#define ROADS 2

sem_t *road;

void *cross(void *argc) {
    printf("(%u) Waiting\n", pthread_self());
    sem_wait(road);
    printf("(%u) Crossing\n", pthread_self());
    printf("(%u) Crossed\n", pthread_self());
    sem_post(road);

    pthread_exit(0);

}

int car_semaphore() {
    pthread_t tid[CARS];
    road = sem_open("road", O_CREAT, 0666, ROADS);

    for (int i = 0; i < CARS; ++i) {
        pthread_create(tid + i, NULL, cross, NULL);
    }

    for (int i = 0; i < CARS; ++i) {
        pthread_join(tid[i], NULL);
    }

    sem_close(road);

    sem_unlink("road");
}