#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int server_socket_fd;
    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket_fd == -1) {
        perror("Error at socket init.");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_socket_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(9292),
        .sin_addr.s_addr = inet_addr("127.0.0.1"),
    };

    int connect_status = connect(server_socket_fd, (struct sockaddr *)&server_socket_addr, sizeof(server_socket_addr));

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
