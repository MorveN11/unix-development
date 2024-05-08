#include <stdio.h>
#include <sys/msg.h>

#define MESSAGE_SIZE 2048

struct msg_struct {
    long msg_type;
    char msg_content[MESSAGE_SIZE];
};

int main(int argc, char *argv[]) {
    int msg_queue_id;
    struct msg_struct message;

    msg_queue_id = msgget((key_t)4789, 0666);
    printf("msg_queue_id: %d\n", msg_queue_id);

    msgrcv(msg_queue_id, (void *)&message, MESSAGE_SIZE, 0, 0);
    printf("Message received from Queue: %s\n", message.msg_content);

    return 0;
}
