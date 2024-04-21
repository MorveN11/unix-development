#include "common.h"
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    int pipe_fd, isGoodBye;

    mkfifo(PIPE_NAME, 0666);

    while (1) {
        isGoodBye = write_pipe(pipe_fd, buffer, "FP Enter a message: ");

        if (isGoodBye) {
            break;
        }

        isGoodBye = read_pipe(pipe_fd, buffer, "FP Received message: ");

        if (isGoodBye) {
            break;
        }
    }

    return 0;
}
