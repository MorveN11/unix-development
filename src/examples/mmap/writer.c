#include "common.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    int fd;

    fd = shm_open(SHARED_MEM_NAME, O_CREAT | O_RDWR, S_IWUSR);

    if (fd == -1) {
        perror("Error: Can't open shared memory\n");
        return EXIT_FAILURE;
    }

    if (ftruncate(fd, SHARED_MEMORY_SIZE) == -1) {
        perror("Eror: Can't truncate shared memory\n");
        close(fd);
        return EXIT_FAILURE;
    }

    void *shm_ptr = mmap(NULL, SHARED_MEMORY_SIZE, PROT_WRITE, MAP_SHARED, fd, 0);

    if (shm_ptr == MAP_FAILED) {
        perror("Error: Can't map shared memory\n");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Enter message to write to shared memory: ");
    fgets(buffer, sizeof(buffer), stdin);
    strcpy((char *)shm_ptr, buffer);

    munmap(shm_ptr, SHARED_MEMORY_SIZE);
    close(fd);

    return EXIT_SUCCESS;
}
