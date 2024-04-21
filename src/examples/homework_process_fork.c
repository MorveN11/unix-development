/*
Three levels of process:
p1 -> print PID, parent PID and counter every second staring from 0 until 10 (i.e. "main process PID(123), PPID(12), counter at 0")
|
+-- p2 -> print PID, parent PID and counter every second starting from 10 until 20 (i.e. "child process PID(233), PPID(123), counter at 10")
    |
    +-- p3 -> print PID, parent PID and counter every second starting from 20 until 40 (i.e. "child of child process PID(333), PPID(233), counter at 20")
p2 needs to wait for p3 to finish
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void print_pid_parent_counter(int start, int end, int is_child);

int main(int argc, char const *argv[]) {

    pid_t child = fork();

    if (child == -1) {
        printf("Failed in Fork \n");
        return 1;
    }

    if (child) {
        print_pid_parent_counter(0, 10, 0);
        printf("Main Process Finish Successfully\n");
        exit(0);
    }

    pid_t child2 = fork();

    if (child2 == -1) {
        printf("Failed in Fork \n");
        exit(1);
    }

    if (child2) {
        print_pid_parent_counter(10, 20, 1);
        printf("Waiting for Child Process -> P3 to Finish\n");
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            if (exit_status == 0) {
                printf("Child Process -> P3 Finish Successfully\n");
            } else {
                printf("Child Process -> P3 Finish with Error\n");
            }
        }
        printf("Child Process -> P2 Finish Successfully\n");
        exit(0);
    }

    print_pid_parent_counter(20, 40, 1);
    exit(0);

    return 0;
}

void print_pid_parent_counter(int start, int end, int is_child) {
    pid_t pid = getpid();
    pid_t ppid = getppid();
    int counter = start;
    while (counter <= end) {
        printf("%s process PID(%d), PPID(%d), counter at %d\n", is_child ? "child" : "main", pid, ppid, counter);
        sleep(1);
        counter++;
    }
}
