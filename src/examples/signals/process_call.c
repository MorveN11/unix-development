#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *sort_pipe;
    char *args[5] = {"And", "D", "Bool", "Empty", "Catch"};

    for (int i = 0; i < 5; i++) {
        printf("%s\n", args[i]);
    }

    char *sort = "/usr/bin/sort";

    sort_pipe = popen(sort, "w");

    for (int i = 0; i < 5; i++) {
        fputs(args[i], sort_pipe);
        fputc('\n', sort_pipe);
    }

    pclose(sort_pipe);

    return EXIT_SUCCESS;
}
