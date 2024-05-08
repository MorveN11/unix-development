#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

#define MESSAGE_SIZE 128

int main(int argc, char *argv[]) {
    void *mmap_ptr;
    int fd = open("/tmp/shared_resource", O_RDONLY, S_IRUSR);

    mmap_ptr = mmap(NULL, MESSAGE_SIZE, PROT_READ, MAP_SHARED, fd, 0);

    if (mmap_ptr == MAP_FAILED) {
        perror("Error: Can't map shared memory\n");
        close(fd);
        return 1;
    }

    printf("mmpa_ptr: %p\n", mmap_ptr);

    char message[MESSAGE_SIZE];

    memcpy(message, mmap_ptr, MESSAGE_SIZE);
    printf("Message read from mmap: %s\n", message);

    munmap(mmap_ptr, MESSAGE_SIZE);
    close(fd);

    return 0;
}
