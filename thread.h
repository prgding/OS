#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

int value;

void *hello(void *arg) {
    for (int i = 0; i < 3; ++i) {
        printf("hello(%d)\n", value++);
    }
}

void *world(void *arg) {
    for (int i = 0; i < 3; ++i) {
        printf("world(%d)\n", value++);
    }
}

int thread() {
    srand(time(NULL));
    pthread_t tid,tid2;

    pthread_create(&tid, NULL, hello, NULL);
    pthread_create(&tid2, NULL, world, NULL);

    pthread_join(tid, NULL);
    pthread_join(tid2, NULL);

    printf("In main thread(%d) \n",value);

    return 0;

}