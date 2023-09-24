// CS21B2019 DEVARAKONDA SLR SIDDESH

// Write two different programs (Sender and Receiver) in C to demonstrate IPC using shared memory. 
// Process "Sender.c" will write atleast 100 bytes of data to the shared memory and process "Receiver.c"
//  will read from the shared memory and displays it. Then, "Receiver.c" will write atleast 100 bytes of data 
//  to the same shared memory and  "Sender.c" will read and displays it. 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>

#define SHM_SIZE 300

int main()
{
    int shmid;
    char *shm, *s;
    char *sentence = "hereisasentenceof100characterswithoutanyspacesorbreaksinbetweenitcontainslettersandnumbersandpunctuation.";
    key_t key = 1234;

    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if(shmid < 0)
    {
        printf("Error in creating shared memory");
        exit(1);
    }
    shm = shmat(shmid, NULL, 0);
    if(shm == (char *) -1)
    {
        printf("Error in attaching shared memory");
        exit(1);
    }

    printf("-------Writing 100 bytes into shared memory-------\n");

    s = shm;
    for (int i = 0; i < 100; i++)
        *s++ = sentence[i];
    *s = '\0';

    while (*shm != '#')
        sleep(1);
    
    printf("------------Reading from shared memory------------\n");

    for (; *s != '\0'; s++)
        putchar(*s);
    putchar('\n');

    return 0;
}