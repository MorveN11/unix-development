#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    int child_pid = fork();

    if (child_pid == 0) {
        // child
        int counter = 0;
        while (1) {
            printf("Child counter %d\n", counter++);
            sleep(1);
        }
    } else {
        // main
        sleep(6);
        kill(child_pid, SIGKILL);
        wait(NULL);
    }

    return EXIT_SUCCESS;
}
