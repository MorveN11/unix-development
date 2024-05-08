#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 8

void do_work() {
    pthread_t thread_id = pthread_self();
    printf("Thread %lu is running.\n", thread_id);

    sleep(1);

    printf("Thread %lu is done.\n", thread_id);
}

int main(int argc, char *argv[]) {
    pthread_t thread_ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        int thread_status = pthread_create(&thread_ids[i], NULL, (void *)do_work, NULL);

        if (thread_status != 0) {
            fprintf(stderr, "Error creating thread %d: %d\n", i, thread_status);
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        int join_status = pthread_join(thread_ids[i], NULL);

        if (join_status != 0) {
            fprintf(stderr, "Error joining thread %d: %d\n", i, join_status);
            return EXIT_FAILURE;
        }
    }

    return EXIT_FAILURE;
}
