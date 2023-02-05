#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define TICKET_AMOUNT 2

int ticketAmount = TICKET_AMOUNT;

void *ticketAgent(void *arg) {
    int t = TICKET_AMOUNT;

    printf("One ticket sold!\n");
    t--;

    ticketAmount = t;
    pthread_exit(0);
}

int ticket() {
    pthread_t ticketAgent_tid[2];

    for (int i = 0; i < TICKET_AMOUNT; ++i) {
        pthread_create(ticketAgent_tid + i, NULL, ticketAgent, NULL);
    }

    for (int i = 0; i < TICKET_AMOUNT; ++i) {
        pthread_join(ticketAgent_tid[i], NULL);
    }

    printf("The left ticket is %d\n", ticketAmount);

    return 0;
}