#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 8

int g_v = 0;

void do_increment_work() {
    pthread_t thread_id = pthread_self();
    printf("Thread %lu is running.\n", thread_id);

    sleep(1);
    g_v++;

    printf("Thread %lu inc: g_v %d.\n", thread_id, g_v);
    printf("Thread %lu is done.\n", thread_id);
}

void do_decrement_work() {
    pthread_t thread_id = pthread_self();
    printf("Thread %lu is running.\n", thread_id);

    sleep(1);
    g_v--;

    printf("Thread %lu dec: g_v %d.\n", thread_id, g_v);
    printf("Thread %lu is done.\n", thread_id);
}

int main(int argc, char *argv[]) {
    pthread_t inc_thread_ids[NUM_THREADS], dec_thread_ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        int thread_status = pthread_create(&inc_thread_ids[i], NULL, (void *)do_increment_work, NULL);

        if (thread_status != 0) {
            fprintf(stderr, "Error creating inc thread %d: %d\n", i, thread_status);
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        int join_status = pthread_join(inc_thread_ids[i], NULL);

        if (join_status != 0) {
            fprintf(stderr, "Error joining inc thread %d: %d\n", i, join_status);
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        int thread_status = pthread_create(&dec_thread_ids[i], NULL, (void *)do_decrement_work, NULL);

        if (thread_status != 0) {
            fprintf(stderr, "Error creating dec thread %d: %d\n", i, thread_status);
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        int join_status = pthread_join(dec_thread_ids[i], NULL);

        if (join_status != 0) {
            fprintf(stderr, "Error joining dec thread %d: %d\n", i, join_status);
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
