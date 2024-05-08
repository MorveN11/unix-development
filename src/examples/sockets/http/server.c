#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CONNECTIONS 30
#define PORT 3000
#define OK_RESPONSE "HTTP/1.1 200 OK\r\n\r\n"

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd == -1) {
        printf("Socket creation failed: %s...\n", strerror(errno));
        return EXIT_FAILURE;
    }

    int reuse = 1;
    int set_socket_status = setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse));

    if (set_socket_status < 0) {
        printf("SO_REUSEPORT failed: %s \n", strerror(errno));
        close(server_fd);
        return EXIT_FAILURE;
    }

    struct sockaddr_in serv_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = inet_addr("127.0.0.1"),
    };
    int bind_status = bind(server_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    if (bind_status != 0) {
        printf("Bind failed: %s \n", strerror(errno));
        close(server_fd);
        return EXIT_FAILURE;
    }

    int listen_status = listen(server_fd, MAX_CONNECTIONS);

    if (listen_status != 0) {
        printf("Listen failed: %s \n", strerror(errno));
        close(server_fd);
        return EXIT_FAILURE;
    }

    printf("Server listening on port %d\n\n", PORT);

    while (1) {
        struct sockaddr_in client_addr;
        int client_addr_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr *)&client_addr,
                               (socklen_t *)&client_addr_len);

        if (client_fd < 0) {
            printf("Accept failed: %s \n", strerror(errno));
            close(server_fd);
            return EXIT_FAILURE;
        }

        printf("Client connected\n");

        char buffer[1024] = {0};
        read(client_fd, buffer, sizeof(buffer));
        printf("Received: %s\n", buffer);

        write(client_fd, OK_RESPONSE, strlen(OK_RESPONSE));

        close(client_fd);
    }

    close(server_fd);

    return EXIT_SUCCESS;
}
