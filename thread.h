#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


void *threadFunc(void *arg) {
    printf("In New thread\n");
}

int thread() {
    pthread_t tid;

    pthread_create(&tid, NULL, threadFunc, NULL);

    pthread_join(tid, NULL);

    printf("In main thread \n");

    return 0;

}