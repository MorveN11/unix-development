#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {

    char *f_open = "./src/examples/files.c";

    int fd = open(f_open, O_RDONLY);
    printf("fd: %d\n", fd);

    char content[1000];
    int size = read(fd, content, 1000);
    printf("content: %s\n", content);
    printf("size: %d\n", size);

    char mod[3] = {'A', 'B', 'C'};
    int size_write = write(fd, mod, 3);
    printf("size_write: %d\n", size_write);

    int fd_write = open("write-me.txt", O_WRONLY | O_CREAT, 0666);
    printf("fd_write: %d\n", fd_write);
    size = write(fd_write, mod, 3);
    printf("new-size: %d\n", size);

    return 0;
}
