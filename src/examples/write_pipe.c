#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define PIPE_NAME "/tmp/my_pipe"
#define BUFFER_SIZE 128

int main() {
    char buffer[BUFFER_SIZE];

    // Create the named pipe
    mkfifo(PIPE_NAME, 0666);

    // Open the named pipe for writing
    int pipe_fd = open(PIPE_NAME, O_WRONLY);

    printf("Enter a message: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    // Write the message to the pipe
    write(pipe_fd, buffer, strlen(buffer) + 1);

    // Close the pipe
    close(pipe_fd);

    return 0;
}
