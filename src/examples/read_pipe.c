#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define PIPE_NAME "/tmp/my_pipe"
#define BUFFER_SIZE 128

int main() {
    char buffer[BUFFER_SIZE];

    // Open the named pipe for reading
    int pipe_fd = open(PIPE_NAME, O_RDONLY);

    // Read the message from the pipe
    read(pipe_fd, buffer, BUFFER_SIZE);

    printf("Received message: %s", buffer);

    // Close the pipe
    close(pipe_fd);

    // Remove the named pipe
    unlink(PIPE_NAME);

    return 0;
}
