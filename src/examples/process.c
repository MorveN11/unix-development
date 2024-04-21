#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    for (int i = 0; i < 10; i++) {
        printf("i = %d\n", i);
        sleep(1);
    }

    return 0;
}
