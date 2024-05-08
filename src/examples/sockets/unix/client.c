#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    int server_socket_fd;
    server_socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);

    if (server_socket_fd == -1) {
        perror("Error at socket init.");
        return EXIT_FAILURE;
    }

    struct sockaddr_un client_socket_addr;
    client_socket_addr.sun_family = AF_UNIX;
    strcpy(client_socket_addr.sun_path, "/tmp/ipc_socket");

    int connect_status = connect(server_socket_fd, (struct sockaddr *)&client_socket_addr, sizeof(client_socket_addr));

    if (connect_status == -1) {
        perror("Error at connect.");
        return EXIT_FAILURE;
    }

    int write_status = write(server_socket_fd, "Hi", 2);

    if (write_status == -1) {
        perror("Error at writing message.");
        return EXIT_FAILURE;
    }

    char response[2];
    int read_status = read(server_socket_fd, response, 2);

    if (read_status == -1) {
        perror("Error at reading response.");
        return EXIT_FAILURE;
    }

    printf("Response from server: %s\n", response);

    close(server_socket_fd);

    return EXIT_SUCCESS;
}
