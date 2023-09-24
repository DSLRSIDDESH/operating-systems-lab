// Roll: CS21B2019
// Name: Devarakonda SLR Siddesh
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 512

// Define a structure for the message
typedef struct {
    long int msg_type;  // Message type (used for message selection)
    int data;      // Data array to hold integers
} Msg;

int main() {
    int msgid;           // Message queue ID
    Msg msg;             // Message structure

    msg.msg_type = 1;   // Set the message type for receiving

    // Get the message queue with key 2019 and read permissions
    msgid = msgget((key_t)1234, 0644);
    if (msgid == -1) {
        printf("Error in creating message queue\n");
        exit(0);
    }

    // Receive a message from the message queue
    if(msgrcv(msgid, (void *)&msg, MAX * sizeof(int), msg.msg_type, 0) == -1)
    {
        printf("Not able to receive message\n");
        exit(0);
    }
    
    // Print the number of odd numbers found
    printf("%d\n", msg.data);

    // Remove the message queue
    msgctl(msgid, IPC_RMID, 0);

    return 0;
}