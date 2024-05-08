#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char buffer[MAX_BUFFER_SIZE];
    FILE *ls_command_pipe, *sort_command_pipe;
    char *ls_command = "/usr/bin/ls /";
    char *sort_command = "/usr/bin/sort -r";

    ls_command_pipe = popen(ls_command, "r");
    sort_command_pipe = popen(sort_command, "w");

    while (fgets(buffer, MAX_BUFFER_SIZE, ls_command_pipe)) {
        fputs(buffer, sort_command_pipe);
    }

    pclose(ls_command_pipe);
    pclose(sort_command_pipe);

    return EXIT_SUCCESS;
}
