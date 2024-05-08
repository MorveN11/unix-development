#include <stdio.h>
#include <sys/shm.h>

int main(int argc, char *argv[]) {
    int shm_id;
    void *shm_ptr;
    char buffer[256];

    shm_id = shmget((key_t)4583, (size_t)2048, 0666);

    shm_ptr = shmat(shm_id, NULL, 0);

    printf("Message read from shared memory: %s\n", (char *)shm_ptr);

    return 0;
}
