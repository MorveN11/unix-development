#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_CONNECNTIONS 5
#define MESSAGE_SIZE 256

int main(int argc, char *argv[]) {
    int server_socket_fd;
    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket_fd == -1) {
        perror("Error at socket init.");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(9292),
        .sin_addr.s_addr = inet_addr("127.0.0.1"),
    };

    int bind_status = bind(server_socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if (bind_status == -1) {
        perror("Error at bind.");
        return EXIT_FAILURE;
    }

    int listen_status = listen(server_socket_fd, MAX_CONNECNTIONS);

    if (listen_status == -1) {
        perror("Error at listening.");
        return EXIT_FAILURE;
    }

    struct sockaddr_in client_addr;
    int client_addr_len = sizeof(client_addr);
    int client_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr_len);

    if (client_socket_fd == -1) {
        perror("Error at accepting connection.");
        return EXIT_FAILURE;
    }

    char buffer[MESSAGE_SIZE];
    int read_status = read(client_socket_fd, &buffer, MESSAGE_SIZE);

    if (read_status == -1) {
        perror("Error at reading message.");
        return EXIT_FAILURE;
    }

    printf("Message from client: %s\n", buffer);

    int write_status = write(client_socket_fd, "Ok", 2);

    if (write_status == -1) {
        perror("Error at writing message.");
        return EXIT_FAILURE;
    }

    close(server_socket_fd);
    close(client_socket_fd);

    return EXIT_SUCCESS;
}
