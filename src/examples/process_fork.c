#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    pid_t main_pid = getpid();
    pid_t p_main_pid = getppid();

    printf("main_pid = %d\n", main_pid);
    printf("p_main_pid = %d\n", p_main_pid);

    pid_t child = fork();

    if (child == 1) {
        printf("Failed in Fork \n");
        return -1;
    }

    if (child == 0) {
        // child process
        printf("child pid = %d, ppid = %d\n", getpid(), getppid());
        sleep(5);
        printf("child finish\n");
    } else {
        // parent process
        printf("main pid = %d, ppid = %d\n", getpid(), getppid());
        wait(NULL);
        printf("parent finish\n");
    }

    return 0;
}
