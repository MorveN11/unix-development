#include "common.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int verify_exit(const char *buffer) {
    return strncmp(buffer, FINISH_CHAT, strlen(FINISH_CHAT)) == 0;
}

int write_pipe(int pipe_fd, char *buffer, const char *message) {
    pipe_fd = open(PIPE_NAME, O_WRONLY);
    printf("%s", message);
    fgets(buffer, BUFFER_SIZE, stdin);
    write(pipe_fd, buffer, strlen(buffer) + 1);
    close(pipe_fd);
    return verify_exit(buffer);
}

int read_pipe(int pipe_fd, char *buffer, const char *message) {
    printf("Waiting for a message...\n");
    pipe_fd = open(PIPE_NAME, O_RDONLY);
    read(pipe_fd, buffer, BUFFER_SIZE);
    printf("%s%s", message, buffer);
    close(pipe_fd);
    return verify_exit(buffer);
}
