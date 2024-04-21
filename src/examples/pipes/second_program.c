#include "common.h"

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    int pipe_fd, isGoodBye;

    while (1) {
        isGoodBye = read_pipe(pipe_fd, buffer, "SP Received message: ");

        if (isGoodBye) {
            break;
        }

        isGoodBye = write_pipe(pipe_fd, buffer, "SP Enter a message: ");

        if (isGoodBye) {
            break;
        }
    }

    return 0;
}
