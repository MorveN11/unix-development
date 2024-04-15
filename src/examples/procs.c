#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    pid = fork();
    if (pid == -1) {
        printf("Failed in Fork \n ");
        return -1;
    } else if (!pid) {
        printf("Child Process: PID %d \n", getpid());
    } else {
        printf("Parent Process: PID %d \n", getpid());
    }

    return 0;
}
