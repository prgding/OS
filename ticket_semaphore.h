#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int ticketAmount = 2;

sem_t *mutex;

void *ticketAgent(void *arg) {
    sem_wait(mutex);

    int t = ticketAmount;

    printf("One ticket sold!\n");
    t--;

    ticketAmount = t;

    sem_post(mutex);

    pthread_exit(0);
}


int ticket_semaphore() {
    mutex = sem_open("/semaphore_example", O_CREAT, 0666, 1);

    pthread_t ticketAgent_tid[2];

    for (int i = 0; i < 2; ++i) {
        pthread_create(&ticketAgent_tid[i], NULL, ticketAgent, (void *) i);
    }

    for (int i = 0; i < 2; ++i) {
        pthread_join(ticketAgent_tid[i], NULL);
    }

    printf("The left ticket is %d\n", ticketAmount);

    sem_close(mutex);

    sem_unlink("/semaphore_example");

    return 0;
}