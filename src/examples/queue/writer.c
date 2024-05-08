#include <stdio.h>
#include <string.h>
#include <sys/msg.h>

#define MESSAGE_SIZE 2048

struct msg_struct {
    long msg_type;
    char msg_content[MESSAGE_SIZE];
};

int main(int argc, char *argv[]) {
    int exit = 0;
    int msg_queue_id;
    char buffer[256];
    struct msg_struct message;

    msg_queue_id = msgget((key_t)4789, 0666 | IPC_CREAT);
    printf("msg_queue_id: %d\n", msg_queue_id);

    while (!exit) {
        printf("Enter message for the Queue: ");

        fgets(buffer, 256, stdin);

        if (strncmp(buffer, "exit", 4) == 0) {
            exit = 1;
        } else {
            strcpy(message.msg_content, buffer);
            msgsnd(msg_queue_id, (void *)&message, MESSAGE_SIZE, 0);
            printf("Message sent to Queue: %s", message.msg_content);
        }
    }

    return 0;
}
