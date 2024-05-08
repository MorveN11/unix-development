#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void sigkill_handler() {
    printf("SIGKILL handling\n");
}

void sigstop_handler() {
    printf("SIGSTOP handling\n");
}

void sigcont_handler() {
    printf("SIGCONT handling\n");
}

void sigint_handler() {
    printf("Ctrl-C detected\n");
    exit(0);
}

int main(int argc, char *argv[]) {

    int child_pid = fork();

    signal(SIGINT, &sigint_handler);

    if (child_pid == 0) {
        // child
        signal(SIGKILL, &sigkill_handler);
        signal(SIGSTOP, &sigstop_handler);
        signal(SIGCONT, &sigcont_handler);

        int counter = 0;
        while (1) {
            printf("Child counter %d\n", counter++);
            sleep(1);
        }
    } else {
        // main
        sleep(6);
        kill(child_pid, SIGSTOP);
        sleep(6);
        kill(child_pid, SIGCONT);
        sleep(6);
        kill(child_pid, SIGKILL);
        wait(NULL);
    }

    return EXIT_SUCCESS;
}
