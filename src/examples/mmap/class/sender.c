#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

#define MESSAGE_SIZE 128

int main(void) {
    void *mmap_ptr;
    int fd = open("/tmp/shared_resource", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

    lseek(fd, MESSAGE_SIZE, SEEK_SET);
    write(fd, "", 1);

    mmap_ptr = mmap(NULL, MESSAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    printf("mmpa_ptr: %p\n", mmap_ptr);

    char message[64] = "Message by mmap";
    memcpy(mmap_ptr, message, sizeof(message));
    printf("Message sent: %s\n", (char *)mmap_ptr);

    munmap(mmap_ptr, MESSAGE_SIZE);
    close(fd);

    return 0;
}
