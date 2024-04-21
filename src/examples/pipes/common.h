#ifndef COMMON_H
#define COMMON_H

#define PIPE_NAME "/tmp/shared_pipe"
#define BUFFER_SIZE 128
#define FINISH_CHAT "bye\n"

int verify_exit(const char *buffer);

int write_pipe(int pipe_fd, char *buffer, const char *message);

int read_pipe(int pipe_fd, char *buffer, const char *message);

#endif
