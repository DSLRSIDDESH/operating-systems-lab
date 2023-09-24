#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 512

typedef struct
{
    long int msg_type;
    int data;
} Msg;

int main()
{
    int msgid, n;
    Msg msg;
    key_t key = 1234;

    msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid == -1) {
        printf("Error in creating message queue\n");
        exit(0);
    }
    printf("Enter the number : ");
    scanf("%d", &n);

    msg.msg_type = 1;
    msg.data = n;

    if(msgsnd(msgid, (void *)&msg, MAX, 0) == -1)
    {
        printf("Message not sent\n");
        exit(0);
    }
    printf("Sent successfully\n");

    return 0;
}