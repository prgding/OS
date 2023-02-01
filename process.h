#include <stdio.h>
#include <unistd.h>


int process() {
    pid_t pid;
    pid_t cid;
    printf("Before fork Process id : %d\n", getpid());

    cid = fork();

    if (cid == 0) {
        printf("Child process id (my parent pid is %d):%d\n", getppid(), getpid());
        for (int i = 0; i < 3; ++i) {
            printf("1\n");
        }
    } else {
        printf("Parent process id : %d\n", getpid());
        for (int i = 0; i < 3; ++i) {
            printf("2\n");
        }
    }

//    printf("After fork Process id : %d\n", cid);

    return 0;
}